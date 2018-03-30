#ifndef LAB_QUEUE_H
#define LAB_QUEUE_H
#include <iostream> 
#include "pointer.h"

template <typename labType>
class Queue
{
private:
	Pointer<labType> *left, *right;
	int size;
public:
	void push(labType);
	labType pop(void);
	void print(void);
	Queue(void);
	~Queue(void);
};

template <typename labType>
Queue<labType>::Queue(void)
{
	this->size = 0;
	this->left = nullptr;
	this->right = nullptr;
}

template <typename labType>
Queue<labType>::~Queue(void)
{
	while (this->left != nullptr) pop();
	std::cout << "ochered udalena\n";
	system("pause");
}

template <typename labType>
void Queue<labType>::push(labType data)
{
	if (this->left == nullptr)
	{
		Pointer<labType> *ptr = new Pointer<labType>(data);
		this->left = ptr;
		this->right = ptr;
	}
	else
	{
		Pointer<labType> *ptr = new Pointer<labType>(data);
		right->next = ptr;
		ptr->prev = this->right;
		this->right = ptr;
		this->size++;
	}
	std::cout << "Element(" << size + 1 << "): '" << data << "'.\n";
}

template <typename labType>
labType Queue<labType>::pop(void)
{
	if (this->left != nullptr)
	{
		std::cout << "Element(" << size + 1 << "): '" << left->data << "udalen\n";
		labType data = left->data;
		Pointer<labType> *ptr = this->left;
		this->left = left->next;
		this->size--;
		delete ptr;
		ptr = nullptr;
		if (this->left == nullptr) this->size = 0;
		return data;
	}
	else std::cout << "ohered pustaya\n";
	return NULL;
}

template <typename labType>
void Queue<labType>::print(void)
{
	int number = this->size + 1;
	Pointer<labType> *ptr = this->left;
	while (ptr)
	{
		std::cout << "Element(" << number << "): '" << ptr->data << "'.\n";
		ptr = ptr->next;
		number--;
	}
}

#endif

