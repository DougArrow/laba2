#ifndef LAB_DEQUE_H
#define LAB_DEQUE_H
#include <iostream> 
#include "pointer.h"

template <typename labType>
class Deque
{
private:
	Pointer<labType> *left;
	Pointer<labType> *right;
	int size;
	bool destr;
public:
	void push(bool, labType); 
	void pop(bool);
	void print(bool);  
	Deque(bool);	
	~Deque(void); 
};

template <typename labType>
Deque<labType>::Deque(bool destr) 
{
	
	this->destr = destr;
	this->size = 0;		 
	this->left = nullptr; 
	this->right = nullptr; 
}

template <typename labType>
Deque<labType>::~Deque(void) 
{
	while (this->left || this->right) pop(destr);
	system("pause");
}

template <typename labType>
void Deque<labType>::push(bool side, labType data) 
{
	if (!(this->left || this->right)) 
	{
		Pointer<labType> *ptr = new Pointer<labType>(data);
		this->left = ptr;
		this->right = ptr;
	}
	else if (!side)
	{
		Pointer<labType> *ptr = new Pointer<labType>(data); 
		ptr->next = this->left;
		left->prev = ptr;
		this->left = ptr;
		this->size++;
	}
	else
	{
		Pointer<labType> *ptr = new Pointer<labType>(data); 
		ptr->prev = this->right;
		right->next = ptr;
		this->right = ptr;
		this->size++;
	}
	std::cout << "Element(" << size + 1 << "): '" << data << "'.\n";
}

template <typename labType>
void Deque<labType>::pop(bool side) 
{
	if (this->left || this->right)
	{
		if (!side)
		{
			std::cout << "Element(" << size + 1 << "): '" << left->data << "' udalen\n"; 
			Pointer<labType> *ptr = this->left;
			this->left = left->next;
			if (this->left) left->prev = nullptr;
			this->size--;
			delete ptr;
			ptr = nullptr;
		}
		else
		{
			std::cout << "Element(" << size + 1 << "): '" << right->data << "' udalen\n"; 
			Pointer<labType> *ptr = this->right;
			this->right = right->prev;
			if (this->right) right->next = nullptr;
			this->size--;
			delete ptr;
			ptr = nullptr;
		}
	}
	else std::cout << "deq pustoy\n";
	if (this->left == nullptr) this->right = nullptr;
	if (this->right == nullptr) this->left = nullptr;
	if (!(this->left || this->right)) this->size = 0;
}

template <typename labType>
void Deque<labType>::print(bool side) 
{

	int number = this->size + 1;
	if (!side)
	{
		Pointer<labType> *ptr = this->left;
		while (ptr)
		{
			std::cout << "Element(" << number << "): '" << ptr->data << "'.  " << ptr << "\n";
			ptr = ptr->next;
			number--;
		}
	}
	else
	{
		Pointer<labType> *ptr = this->right;
		while (ptr)
		{
			std::cout << "Element(" << number << "): '" << ptr->data << "'.  " << ptr << "\n";
			ptr = ptr->prev;
			number--;
		}
	}

	if (!(this->left || this->right)) std::cout << "deq pustoy\n";
}

#endif