#include "Node.h"

template <class T>
Node<T>::Node() {
	m_next = nullptr;
}

template <class T>
Node<T>::Node(const T& data) {
	m_data = data;
	m_next = nullptr;
}

template class Node<NhanVien*>;