#pragma once
#include<iostream>
#include"Entities.h"
using namespace std;

template<class T>
class Stack {
	T* data;
	size_t size = 0;
public:
	Stack() :data(NULL), size(NULL) {}
	void Push(const T& newdata) {
		auto newarray = new T[size + 1]{};
		for (size_t i = 0; i < size; i++)
		{
			newarray[i] = data[i];
		}
		newarray[size] = newdata;
		data = newarray;
		newarray = nullptr;
		++size;
	}
	void Pop(int index = -1) {
		if (index != -1) {
			auto newitems = new T[size - 1]{};
			for (size_t i = 0; i < index; i++)
			{
				newitems[i] = data[i];
			}
			int index1 = index + 1;
			int index2 = index;
			for (size_t i = 0; i < size - (index + 1); i++)
			{
				newitems[index2] = data[index1];
				index1++;
				index2++;
			}
			data = newitems;
			newitems = nullptr;
			size -= 1;
		}
		else {
			auto newitems = new T[size - 1]{};
			for (size_t i = 0; i < size - 1; i++)
			{
				newitems[i] = data[i];
			}
			data = newitems;
			newitems = nullptr;
			size -= 1;
		}
	}
	int Peek()const {
		assert(size > 0 && "Empty Stack");
		return data[size - 1];
	}
	void Clear() {
		if (this->data == NULL || this->size == NULL) {
			return;
		}
		delete[]data;
		this->data = NULL;
		this->size = NULL;
	}
	void Show()const {
		for (size_t i = 0; i < size; i++)
		{
			cout << data[i] << endl;
		}
	}
	size_t GetSize()const {
		return size;
	}
	T& operator[](int index) {
		assert(index >= 0 && index <= size && "Invalid Index");
		return data[index];
	}
};