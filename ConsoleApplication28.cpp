#include "stdafx.h"
#include <iostream>
#include "CTEK.h"
#include "ochered.h"
#include <fstream>
#include "dek.h"

void main()
{
	/*
	Stack<int> *p1 = new Stack<int>;
	std::cout << "Stack add: ";
	p1->push(1);
	std::cout << "Stack add: ";
	p1->push(2);
	p1->print();
	std::cout << "\n";
	p1->pop();
	p1->pop();
	p1->pop();
	p1->print();
	std::cout << "\nStack add: ";
	p1->push(3);
	p1->print();
	delete p1;
	p1 = nullptr;
*/
/*
Deque<int> *p2 = new Deque<int>(false);
std::cout << "Deque add(left): ";
p2->push(false, 1);
std::cout << "Deque add(right): ";
p2->push(true, 2);
std::cout << "Deque add(left): ";
p2->push(false, 0);
p2->print(false);
p2->print(true);
std::cout << "\nDeque add(left): ";
p2->push(false, 3);
p2->pop(true);
p2->pop(true);
p2->pop(true);
p2->print(false);
p2->print(true);
std::cout << "\nDeque add(left): ";
p2->push(false, 4);
delete p2;
p2 = nullptr;
}
*/
/*
	Queue<int> *p3 = new Queue<int>;
	std::cout << "Queue add: ";
	p3->push(1);
	std::cout << "Queue add: ";
	p3->push(2);
	p3->print();
	std::cout << "\n";
	p3->pop();
	p3->pop();
	p3->pop();
	p3->print();
	std::cout << "\nQueue add: ";
	p3->push(3);
	p3->print();
	delete p3;
	p3 = nullptr;
}
*/
	
	std::ifstream alg("text.txt");
	bool flag = true;
	Stack<char> *p4 = new Stack<char>;
	if (!alg.is_open()) std::cout << "File ne nayden";
	else
	{
	while (!alg.eof())
	{
	char ch;
	alg >> ch;
	if (ch == '(') p4->push(ch);
	if ((ch == ')') && (p4->pop() == NULL))
	{
	flag = false;
	break;
	}
	ch = '\0';
	}
	alg.close();
	}
	if (p4->pop() != NULL) flag = false;
	if (flag) std::cout << "balans ne narushen\n";
	else std::cout << "balans narushen\n";
	delete p4;

	system("Pause");
	}
	
