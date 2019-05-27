#include <iostream>

using namespace std;

template <typename Type>
List <Type> :: List() {
	head = NULL;
	tail = NULL;
	count = 0;
}

template <typename Type>
Node <Type> * List <Type> :: find_node(int p) {
	Node <Type> *cur = head;
	for (int i = 0; i < p; i++) {
		cur = cur->next;
	}
	return cur;
}

template <typename Type>
void List <Type> :: insert(int pos, Type data) {
	if (pos >= 0 && pos <= count) {
		Node <Type> *cur = new Node <Type>;
		cur->data = data;
		if (pos == count) {
			if (pos == 0) {
				cur->next = NULL;
				cur->prev = NULL;
				head = cur;
				tail = cur;
			}
			cur->prev = tail;
			tail->next = cur;
			cur->next = NULL;
			tail = cur;
		} else if (pos == 0) {
			cur->next = head;
			head->prev = cur;
			cur->prev = NULL;
			head = cur;
		} else {
			Node <Type> *rep = find_node(pos);
			cur->prev = rep->prev;
			rep->prev->next = cur;
			cur->next = rep;
			rep->prev = cur;
		}
		count++;
	} else {
		cout << "Position is out of the range" << endl;
	}
}

template <typename Type>
void List <Type> :: erase(int pos) {
	if (pos >= 0 && pos < count) {
		if (pos == 0) {
			if (count == 1) {
				delete head;
				head = NULL;
				tail = NULL;
			} else {
				Node <Type> *copy = head->next;
				delete head;
				copy->prev = NULL;
				head = copy;
			}
		}
		else if (pos == count - 1) {
			Node <Type> *copy = tail->prev;
			delete tail;
			copy->next = NULL;
			tail = copy;
		}
		else {
			Node <Type> *er = find_node(pos);
			Node <Type> *copyprev = er->prev, *copynext = er->next; 
			delete er;
			copyprev->next = copynext;
			copynext->prev = copyprev; 
		}
		count--;
	}
	else {
		cout << "Position is out of the range" << endl;
	}
}

template <typename Type>
void List <Type> :: add(Type data) {
	insert(count, data);
}

template <typename Type>
Node <Type> * List <Type> :: begin() {
	return head;
}

template <typename Type>
Node <Type> * List <Type> :: end() {
	return tail;
}

template <typename Type>
int List <Type> :: size() {
	return count;
}

template <typename Type>
void List <Type> :: print() {
	cout << "size = " << size() << endl;
	for (Node <Type> *cur = head; cur != NULL; cur = cur->next) {
		cout << cur->data << ' ';
	}
}

template <typename Type>
void List <Type> :: println() {
	print();
	cout << endl;
}
