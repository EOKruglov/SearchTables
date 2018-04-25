#pragma once
#include <iostream>


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

	TArrayTable(const TRecord<TKey, TValue>& *recArr)
	{
		size = recArr.size;
		currNum = recArr.currNum;
		arr = new TRecord<TKey, TValue>[size];
		for (int i = 0; i < size; i++)
			arr[i] = recArr[i];
	}

	TRecord<TKey, TValue>*& operator=(const TRecord<TKey, TValue>& *recArr) {
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

	void IsEnd() {
		return DataCount;
	}
	

};


template <class TKey, class TValue>
class TScanTable :public TArrayTable<TKey, TValue>
{
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
};
