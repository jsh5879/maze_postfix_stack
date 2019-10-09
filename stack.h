#pragma once
#pragma once
#include <iostream>
#include "bag.h"
#include <memory>

using namespace std;
template <class T>
class Stack : public Bag<T>
{
public:
	Stack(int MaxStackSize = DefaultSize);
	T& Pop() const;
	T& Top() const; //used for postfix notation
	void Push(const T&);
	//friend�� template�� ���� ����
	template <class T>
	friend ostream& operator<<(ostream& os, const Stack<T>& s);
	template <class T>
	friend ostream& operator<<(ostream& os, items& item);
private:
	void StackEmpty() { cout << "Stack is empty" << endl; };
	void StackFull() { cout << "Stack is full" << endl; };
};
//Visual Studio2019���� bag.h, bag.cpp�� �и����� �ʾƾ� ��
template <class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) cout << "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
T& Stack<T>::Pop() const
{
	if (IsEmpty()) StackEmpty();
	return array[top--];
}
template <class T>
T& Stack<T>::Top() const //used for postfix processing
{
	if (IsEmpty()) StackEmpty();
	return array[top];
}
template <class T>
void Stack<T>::Push(const T& t)
{
	if (IsFull()) StackFull();
	Bag<T>::Push(t);
}

template <class T>
Stack<T>::Stack(int MaxStackSize) : MaxSize(MaxStackSize)
{
	stack = new T[MaxSize];
	top = -1;
}

template <class T>
ostream& operator<<(ostream& os, const Stack<T>& s)
{
	os << "top = " << s.top << endl;
	os << "stack elements: from the bottom to the top: " << endl;
	for (int i = 0; i <= s.top; i++)
		os << i << ":" << s.stack[i] << endl;
	return os;
}
