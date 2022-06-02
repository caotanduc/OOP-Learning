#include "LinkedList.h"


template <class T>
LinkedList<T>::LinkedList() {
	m_head = nullptr;
	m_tail = nullptr;
}


template <class T>
LinkedList<T>::~LinkedList() {
	Node<T>* p;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
		p = nullptr;
	}

	m_head = m_tail = nullptr;
}

template <class T>
int LinkedList<T>::length() const {
	int len = 0;
	Node<T>* run = m_head;
	while (run != nullptr) {
		run = run->m_next;
		len += 1;
	}
	return len;
}

template <class T>
bool LinkedList<T>::is_empty() const {
	return m_head == nullptr;
}

template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& lt) {
	if (this == &lt) 
		return *this;

	remove_all();
	Node<T>* run = m_head;
	while (run != nullptr) {
		push_tail(run->m_data);
		run = run->m_next;
	}

	return *this;
}

template <class T>
void LinkedList<T>::push_head(const T& data) {
	Node<T>* p = new Node<T>(data);
	if (m_head == nullptr) {
		m_head = m_tail = p;
	}
	else {
		p->m_next = m_head;
		m_head = p;
	}
}


template <class T>
void LinkedList<T>::push_tail(const T& data) {
	Node<T>* p = new Node<T>(data);
	if (m_head == nullptr) {
		m_head = m_tail = p;
		return;
	}
	else {
		m_tail->m_next = p;
		m_tail = p;
	}
}


template <class T>
void LinkedList<T>::pop_head() {
	if (is_empty() == false)
		return;

	if (m_head == m_tail) {
		delete m_head;
		m_head = m_head = nullptr;
	}
	else {
		Node<T>* tar = m_head;
		m_head = m_head->m_next;
		delete tar;
		tar = nullptr;
	}
}


template <class T>
void LinkedList<T>::pop_tail() {
	if (is_empty() == false) 
		return ;

	if (m_head == m_tail) {
		delete m_head;
		m_head = m_tail = nullptr;
	}
	else {
		Node<T>* temp = m_head;
		while (temp->m_next != m_tail) {
			temp = temp->m_next;
		}

		delete m_tail;
		m_tail = temp;
		m_tail->m_next = nullptr;
	}
}

template <class T>
void LinkedList<T>::print() {
	Node<T>* run = m_head;
	while (run != nullptr) {
		cout << run->m_data << "->";
		run = run->m_next;
	}
	cout << endl;
}

template <class T>
void LinkedList<T>::remove_all() {
	Node<T>* p;
	while (m_head != nullptr) {
		p = m_head;
		m_head = m_head->m_next;
		delete p;
		p = nullptr;
	}
	m_head = m_tail = nullptr;
}

template class LinkedList<NhanVien*>;
