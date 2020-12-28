/*
Author : F323RED
Date : 2020/11/25
Describe : A queue data structure class
*/

#include <stdexcept>

#ifndef QUEUE_H
#define QUEUE_H

template <class T>
class Queue
{
private:
	int  headIndex, tailIndex, length, size;
	T* items;

public:
	Queue(int size) {
		this->headIndex = 0;
		this->tailIndex = 0;
		this->length = 0;
		this->size = size;

		this->items = new T[size];
	}
	 
	int MaxSize() {
		return size;
	}
	 
	int Length() {
		return length;
	}
	 
	bool IsFull() {
		return (length >= size);
	}
	 
	bool IsEmpty() {
		return (length <= 0);
	}
	 
	void Push(T input) {
		if (IsFull())	// Overflow
		{
			throw std::overflow_error("Queue overflow.");
		}

		items[tailIndex] = input;

		tailIndex++;
		tailIndex %= size;
		length++;
	}
	 
	T Pop() {
		if (IsEmpty())	// Empty
		{
			throw std::underflow_error("Queue underflow.");
		}

		T output = items[headIndex];

		headIndex++;
		headIndex %= size;
		length--;

		return output;
	}
	 
	T GetValue(int index) {
		if (index >= length || index < 0)	// Out of bound
		{
			throw std::exception("Index out of bound.");
		}

		index = (index + headIndex) % size;

		return items[index];
	}
	 
	void SetValue(int index, T input) {
		if (index >= length || index < 0)	// Out of bound
		{
			throw std::exception("Index out of bound.");
		}

		index = (index + headIndex) % size;

		items[index] = input;
	}
	 
	void Clear() {
		headIndex = 0;
		tailIndex = 0;
		length = 0;
	}

	T & operator[](int index) {
		if (index >= length || index < 0)	// Out of bound
		{
			throw std::exception("Index out of bound.");
		}

		index = (index + headIndex) % size;

		return items[index];
	}
};

#endif