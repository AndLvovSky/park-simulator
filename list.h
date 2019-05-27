#ifndef LIST_H
#define LIST_H

template <typename Type>
struct Node {
	Type data;
	Node *next, *prev;
};

template <typename Type>
class List {
	
	private:
		
		Node <Type> *head, *tail;
		int count;
	
	public:
		
		List ();
		Node <Type> * find_node(int p);
		void insert(int pos, Type data);	
		void erase(int pos);	
		void add(Type data);
		Node <Type> * begin();
		Node <Type> * end();
		int size();
		void print();	
		void println();
};

#include "list_implementation.h"

#endif // LIST_H
