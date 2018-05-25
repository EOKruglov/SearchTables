#pragma once
#include <iostream>
#include <stack>


using namespace std;



template <class TKey, class TValue> 
struct TRecord {
	TKey key;
	TValue value;
};




template <class TKey, class TValue> 
class TTable {
protected:
	int DataCount;
	int eff;

public:
	TTable() {
		DataCount = 0;
		eff = 0;
	}

	~TTable(){}


	bool IsEmpty() {
		return DataCount == 0;
	}


	virtual bool IsFull() = 0;
	virtual bool Find(TKey key) = 0;
	virtual bool Insert(TRecord<TKey, TValue> record) = 0;
	virtual void Delete(TKey key) = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual void Reset() = 0;
	virtual TRecord<TKey, TValue> GetCurrent() = 0;
	virtual void SetCurrentValue(TValue value) = 0;


	void Print() {
		TRecord<TKey, TValue> tmp;

		for (Reset(); !IsEnd(); GoNext())
		{
			tmp = GetCurrent();
			cout << tmp.value << endl;
		}
	}

	int GetEff()
	{
		return eff;
	}
};



template <class TKey, class TValue> 
class TArrayTable : public TTable<TKey, TValue> {
protected:
	TRecord<TKey, TValue> *arr;
	int size;
	int currNum;

public:

	TArrayTable(int _size = 10) {
		size = _size;
		arr = new TRecord<TKey, TValue>[size];
	}

	~TArrayTable() {
		delete[] arr;
	}

	TArrayTable(const TRecord<TKey, TValue>& recArr)
	{
		size = recArr.size;
		currNum = recArr.currNum;
		arr = new TRecord<TKey, TValue>[size];
		for (int i = 0; i < size; i++)
			arr[i] = recArr[i];
	}

	TRecord<TKey, TValue>*& operator=(const TRecord<TKey, TValue>& recArr) {
		if (size != recArr.size)
		{
			delete[] arr;
			size = recArr.size;
			arr = new TRecord<TKey, TValue>[size];
		}

		for (int i = 0; i < size; i++)
			arr[i] = recArr[i];
		return *this;
	}

	TRecord<TKey, TValue> GetCurrent()
	{
		return arr[currNum];
	}

	 void Reset() {
		currNum = 0;
	}

	void GoNext() {
		currNum++;
	}

	bool IsEnd() {
		return DataCount;
	}

	bool IsFull()
	{
		return size == DataCount;
	}

	void SetCurrentValue(TValue val)
	{
		arr[currNum].value = val;
	}
	
};


template <class TKey, class TValue>
class TScanTable :public TArrayTable<TKey, TValue>
{
public:

	TScanTable(int _size = 10) : TArrayTable(_size){}

	bool Find(TKey k)
	{
		for (int i = 0; i < DataCount; i++)
		{
			eff++;
			if (arr[i].key == k)
			{
				currNum = i;
				return true;
			}
		}
		currNum = DataCount;
		return false;
	}

	bool Insert(TRecord<TKey, TValue> tr)
	{
		if (!Find(tr.key))
		{
			arr[currNum] = tr;
			DataCount++;
			return true;
		}
		return false;
	}

	void Delete(TKey k)
	{
		if (Find(k))
		{
			arr[currNum] = arr[DataCount - 1];
			DataCount--;
		}
	}



};




template <class TKey, class TValue>
class TSortTable :public TArrayTable<TKey, TValue>
{

public:

	TSortTable(int _size) : TArrayTable(_size){}

	bool Find(TKey k)
	{
		int left = 0, right = DataCount - 1, middle;
		while (left <= right)
		{
			middle = (left + right) / 2;
			eff++;
			if (arr[middle].key == k)
			{
				currNum = middle;
				return true;
			}

			if (arr[middle].key < k)
				left = middle + 1;
			else
				right = middle - 1;
		}

		currNum = left;
		return false;
	}

	void QuickSort(int left, int right)
	{
		int middle = (left + right) / 2;
		TKey mKey = arr[middle].key;
		int i = left, j = right;

		while (i <= j)
		{
			while (arr[i].key < mKey)
			{
				i++;
				eff++;
			}

			while (arr[j].key > mKey)
			{
				j--;
				eff++;
			}

			if (i <= j)
				swap(arr[i], arr[j]);
			eff++;
		}

		if (j > left)
			QuickSort(left, j);
		if (i < right)
			QuickSort(i, right);
	}



	bool Insert(TRecord<TKey, TValue> tr)
	{
		if (!Find(tr.key))
		{
			for (int i = DataCount; i > currNum; i--)
			{
				arr[i] = arr[i - 1];
				eff++;
			}
			DataCount++;
			arr[currNum] = tr;
			return true;
			QuickSort(0, DataCount - 1);
		}
		return false;
	}

	void Delete(TKey k)
	{
		if (Find(k))
		{
			for (int i = currNum; i < DataCount; i++)
			{
				arr[i] = arr[i + 1];
				eff++;
			}
			DataCount--;
		}
	}



};

template<class TKey, class TValue>
class THashTable : public TTable<TKey, TValue>
{
protected:
	int HashFunc(TKey k)
	{
		int pos = 0;
		for (int i = 0; i < k.length(); i++)
			pos += k[i] << i;
		return pos;
	}
};

template<class TKey, class TValue>
class TArrayHash :public THashTable<TKey, TValue>
{
protected:
	int size, step, currNum;
	TRecord<TKey, TValue> *arr;

public:
	TArrayHash(int _size = 100)
	{
		size = _size;
		arr = new TRecord<TKey, TValue>[size];
		step = 13;
		for (int i = 0; i < size; i++)
			arr[i].key = " ";
	}

	TArrayHash()
	{
		delete[] arr;
	}

	bool Find(TKey k)
	{
		currNum = HashFunc(k) % size;
		int freepos = -1;
		for (int i = 0; i < size; i++)
		{
			eff++;
			if (arr[currNum].key == " ")
				if (freepos == -1)
					return false;
				else
				{
					currNum = freepos;
					return freepos;
				}
			if (arr[currNum].key == k)
				return true;
			if ((freepos == -1) && (arr[currNum].key == "&"))
				freepos = currNum;
			currNum += step;
			currNum %= size;
		}
		return false;
	}

	void Delete(TKey k)
	{
		if (Find(k))
		{
			DataCount--;
			arr[currNum].key = "&";
		}
	}

	void Reset()
	{
		currNum = 0;
		while ((arr[currNum].key == " " || arr[currNum].key == "&") && (currNum < size))
			currNum++;
	}

	bool isEnd() 
	{
		return currNum >= size;
	}

	void GoNext()
	{
		while ((++currNum < size)) {
			if (((arr[currNum].key != "&") && (arr[currNum].key != " ")))
				break;
		}
	}

	bool Insert(TRecord < TKey, TValue> record) {
		if (!Find(record.key)) 
		{
			arr[currNum] = record;
			DataCount++;
			return true;
		}
		return false;
	}

	bool IsFull()
	{
		return DataCount == size;
	}

	bool IsEnd()
	{
		return currNum >= size;
	}

	TRecord<TKey, TValue> GetCurrent()
	{
		return arr[currNum];
	}

	void SetCurrentValue(TValue val)
	{
		arr[currNum].value = val;
	}

};

template <class TKey, class TValue>
struct TNode
{
	int bal;
	TRecord<TKey, TValue> rec;
	TNode<TKey, TValue> *pLeft, *pRight;
};


template<class TKey, class TValue>
class TTreeTable :public TTable<TKey, TValue>
{
protected:
	TNode<TKey, TValue> *pRoot;
	TNode<TKey, TValue> *pCurr;
	stack<TNode<TKey, TValue>*> st;
	TNode<TKey, TValue> **pRes;
	int pos;
public:
	TTreeTable()
	{
		pRoot = nullptr;
		pCurr = nullptr;
		pRes = nullptr;
	}

	bool Find(TKey k)
	{
		pRes = &pRoot;
		while (*pRes != nullptr)
		{
			eff++;
			if ((*pRes)->rec.key == k)
				return true;
			if ((*pRes)->rec.key < k)
				pRes = &((*pRes) -> pRight);
			else
				pRes = &((*pRes)->pLeft);
		}
		return false;
	}

	bool Insert(TRecord<TKey, TValue> r)
	{
		if (!Find(r.key))
		{
			TNode<TKey, TValue> *tmp = new TNode<TKey, TValue>;
			tmp->rec = r;
			tmp->pLeft = nullptr;
			tmp->pRight = nullptr;
			pRes = &tmp;
			DataCount++;
			return true;
		}
		else
			return false;
	}

	void Delete(TKey k)
	{
		if (Find(k))
		{
			TNode<TKey, TValue> *tmp = *pRes;
			if (tmp->pLeft == nullptr)
				*pRes = tmp->pRight;
			else
				if (tmp->pRight == nullptr)
					*pRes = tmp->pLeft;
				else
				{
					TNode<TKey, TValue> *p = tmp->pLeft;
					TNode<TKey, TValue> **pPrev = &tmp->pLeft;
					while (p->pRight != nullptr)
					{
						eff++;
						pPrev = &(p->pRight);
						p = p->pRight;
					}
					tmp->rec = p->rec;
					tmp = p;
					*pPrev = p->pLeft;
				}
			delete tmp;
			DataCount--;
		}
	}

	void Reset()
	{
		pos = 0;
		while (!st.empty())
			st.pop();
		pCurr = pRoot;
		while (pCurr->pLeft != nullptr)
		{
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
		st.push(pCurr);
	}

	void GoNext()
	{
		st.pop();
		pos++;
		if (pCurr->pRight != nullptr)
		{
			pCurr = pCurr->pRight;
			while (pCurr->pLeft != nullptr)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
			st.push(pCurr);
		}
		else
			if (!st.empty())
			{
				pCurr = st.top();
				//st.pop();
			}
	}

	bool IsEnd()
	{
		return(pos == DataCount);
	}

	bool IsFull()
	{
		return false;
	}

	void SetCurrentValue(TValue val)
	{
		pCurr->rec.value = val;
	}

	TRecord<TKey, TValue> GetCurrent()
	{
		return pCurr->rec;
	}
};
