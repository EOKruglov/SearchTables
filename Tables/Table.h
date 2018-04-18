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



};
