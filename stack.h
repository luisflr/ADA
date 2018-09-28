#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Linked_list.h"
using namespace std;

template<class T> 
class stack
{
	private:
		linked_list<T> list;
	
	public:
		stack(){};
		~stack(){};

		void push(T dato)
		{
			list.insert_back(dato);
		}
		void pop()
		{
			list.remove_back();
		}
		T top()
		{
			return list.getLastDato();
		}
		void print()
		{
			list.print();
		}

};

#endif
