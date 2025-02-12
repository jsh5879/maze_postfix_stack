#pragma once
#include <iostream>
#include <memory>
using namespace std;
#define MaxSize 100
template <class T>
class Bag {
public:
	Bag(int bagCapacity = 10);
	~Bag();
	bool IsFull();
	int Size() const;
	bool IsEmpty() const;
	virtual T& Pop();
	virtual void Push(const T&);
protected:
	T* ary;
	int capacity;
	int top;
};
//Visual Studio2019에서 bag.h, bag.cpp로 분리하지 않아야 함
template <class T>
Bag<T>::Bag(int bagCapacity) : capacity(bagCapacity)
{
	if (capacity < 1) throw "Capacity must be > 0";
	ary = new T[capacity];
	top = -1;
}

template <class T>
Bag<T>::~Bag() { delete[] ary; }

template <class T>
void ChangeSizeID(T*& a, const int oldSize, const int newSize)
{
	if (newSize < 0) throw "New length must be >= 0";

	T* temp = new T[newSize];
	int number = oldSize;
	if (oldSize > newSize) number = newSize;
	//copy(a, a + number, temp);
	memcpy(temp, a, number);
	delete[] a;
	a = temp;
}

template <class T>
int Bag<T>::Size() const {
	return top + 1;
}

template <class T>
bool Bag<T>::IsEmpty() const {
	return top < 0;
}

template <class T>
void Bag<T>::Push(const T& x)
{
	if (top == capacity - 1)
		// 현재 버젼은 ordering 상태에서 push한다. non-ordering되게 push가 가능하게 수정
	{
		ChangeSizeID(ary, capacity, 2 * capacity);
		capacity *= 2;
	}
	ary[++top] = x;
}

template <class T>
T& Bag<T>::Pop()
{
	T retValue;
	if (IsEmpty()) throw "Bag is empty, cannot delete";
	int deletePos = top / 2;
	retValue = ary[deletePos];
	// 실습 사항: no ordering상태로 pop되게 수정
	//copy(ary + deletePos + 1, ary + top + 1, ary + deletePos);
	memcpy(ary + deletePos, ary + deletePos, top + 1);
	top--;
	return retValue;
}

template <class T>
inline bool Bag<T>::IsFull()
{
	if (top == MaxSize - 1) return true;
	else return false;
}
