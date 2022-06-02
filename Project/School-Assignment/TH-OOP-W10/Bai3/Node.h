#ifndef NODE_H
#define NODE_H

#include "NhanVien.h"

template <class T>
class Node {
	T m_data;
	Node<T>* m_next;
	template <class U> friend class LinkedList;
	friend class CongTy;
public:
	Node();
	Node(const T& data);
};


#endif // !NODE_H


