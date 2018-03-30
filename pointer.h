#ifndef LAB_POINTER_H
#define LAB_POINTER_H
#include <iostream>

template <typename labType>
class Pointer
{
public:
	Pointer<labType> *next, *prev;
	labType data;
	Pointer(labType);
};

template <typename labType>
Pointer<labType>::Pointer(labType data)
{
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}

#endif

