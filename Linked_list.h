#ifndef Linked_list_H
#define Linked_list_H
#include <iostream>
using namespace std;
template <class T>
class node;

template <class T>
class linked_list;

template <class T>
class node
{
	private:
		int dato;
		node<T> * p_next;
		
	
	public:
		node(const T & d, node<T> * n = NULL )
		{
			dato =d;
			p_next=n;
			
		}
		virtual ~node()
		{
			if(p_next)
			{
				delete p_next;
			}
		}
		void print();
	
	friend class linked_list<T>;
};



template <class T>
class linked_list
{
	private:
		node<T> * p_head;
		node<T> * p_last;

	public:
		linked_list()
		{
			p_head=NULL;
			p_last=NULL;
		}
		virtual ~linked_list()
		{
			delete p_head;
		}
		void insert_front(const T & d)
		{
			if(!p_head)
			{
				p_head=new node <T>(d,p_head);	
				p_last=p_head;
			}
			else if(p_head->p_next==NULL)
			{
				node<T>*temp=p_head;
				p_head=new node<T>(d,p_head);
				p_head->p_next=temp;
				p_last=temp;
			}
			else
			{
				p_head=new node<T>(d,p_head);
			}

		}
		void insert_back(const T & d)
		{
			if (!p_head)
			{
				p_head=new node <T>(d,p_head);
				p_last=p_head;
				return;
			}
			if(p_head->p_next==NULL)
			{
				p_last->p_next=new node <T>(d);
				p_last=p_last->p_next;
				return;
			}
			node<T>*temp=new node<T>(d);
			p_last->p_next=temp;
			p_last=temp;
		}
		void remove_front()
		{
			if(!p_head) return;
			node <T>* n_del=p_head;
			p_head=p_head->p_next;
			n_del->p_next=NULL;
			delete n_del;
		}
		void remove_back()
		{
			if(!p_head) return;
			if(!p_head->p_next)
			{
				delete p_head;
				p_head=NULL;	
			}
			node <T>* n_del=p_head;
			while (n_del->p_next->p_next != NULL)
			{
				n_del=n_del->p_next;
			}
			delete n_del -> p_next;
			p_last=n_del;
			p_last->p_next=NULL;
		}
		void reverse()
		{
			if(!p_head)NULL;
			node <T>*p_current=p_head;
			node <T>*p_prev=NULL;
			node <T>*next=NULL;
			while(p_current!=NULL)
			{
				next=p_current->p_next;
				p_head=p_current;
				p_current->p_next=p_prev;
				p_prev=p_current;
				p_current=next;
			}
		}
		T getFirstDato()
		{
			return p_head->dato;
		}
		T getLastDato()
		{
			return p_last->dato;
		}
		void print()
		{
			print(p_head);
		}
	private:
		void print(node<T>*n)
		{
			if(!n)return;
			cout<<n->dato<<"->";
			print(n->p_next);
		}
};

#endif

