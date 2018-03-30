
#ifndef LAB_STACK_H
#define LAB_STACK_H
#include <iostream> 
#include "pointer.h"

template <typename labType>
class Stack
{
private:
	Pointer<labType> *top;
	int size;
public:
	void push(labType);
	labType pop(void);
	void print(void);
	Stack(void);
	~Stack(void);
};

template <typename labType>
Stack<labType>::Stack(void)
{
	this->size = 0;
	this->top = nullptr;
}

template <typename labType>
Stack<labType>::~Stack(void)
{
	while (this->top) pop();
	system("pause");
}

template <typename labType>
void Stack<labType>::push(labType data)
{
	if (this->top == nullptr) this->top = new Pointer<labType>(data);
	else
	{
		Pointer<labType> *ptr = new Pointer<labType>(data);
		ptr->prev = this->top;
		this->top = ptr;
		this->size++;
	}
	std::cout << "Element(" << this->size + 1 << "): '" << data << "'.\n";
}

template <typename labType>
labType Stack<labType>::pop(void)
{
	if (this->top != nullptr)
	{
		std::cout << "Element(" << size + 1 << "): '" << top->data << "' udalen!\n";
		labType data = top->data;
		Pointer<labType> *ptr = this->top;
		this->top = top->prev;
		this->size--;
		delete ptr;
		ptr = nullptr;
		if (this->top == nullptr) this->size = 0;
		return data;
	}
	else std::cout << "Stack pustoy!\n";


	return NULL;
}


template <typename labType>
void Stack<labType>::print(void)
{
	int number = this->size + 1;
	Pointer<labType> *ptr = this->top;
	while (ptr)
	{
		std::cout << "Element(" << number << "): '" << ptr->data << "'.  " << ptr << "\n";
		ptr = ptr->prev;
		number--;
	}
}

#endif


