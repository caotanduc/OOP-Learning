#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Node.h"
#include "NhanVien.h"


template <class T>
class LinkedList {
private:
	Node<T>* m_head;
	Node<T>* m_tail;
	friend class CongTy;
public:
	LinkedList();
	~LinkedList();	

	LinkedList& operator=(const LinkedList&);
	
	int length() const;
	bool is_empty() const;

	void push_head(const T&);
	void push_tail(const T&);
	void pop_head();
	void pop_tail();
	void print();

	void remove_all();
};

#endif // LINKED_LIST_H
