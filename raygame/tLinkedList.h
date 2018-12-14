#pragma once
#include<iostream>
template<typename T>
class tForwardList
{
    struct Node
    {
        T data;                     // data for the element stored
        Node * next;                // pointer to node following this node
    };

    Node * head, * tail;                    // pointer to head of linked list
	
public:
    tForwardList();                 // default constructor
    ~tForwardList();                // destructor

    void push_front(const T& val);  // adds element to front (i.e. head)
    void pop_front();               // removes element from front

    T& front();                     // returns the element at the head
    const T& front() const;         // returns the element at the head (const)

    void remove(const T& val);      // removes all elements equal to the given value
	void display();
	
	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator();                                 // initializes an empty iterator pointing to null
		iterator(Node * startNode);                 // initializes an iterator pointing to the given node


		bool operator==(const iterator& rhs) const; // returns true if the iterator points to the same node
		bool operator!=(const iterator& rhs) const; // returns false if the iterator does not point to the same node
		T& operator*() const;                       // returns a reference to the element pointed to by the current node
		iterator& operator++();                     // pre-increment (returns a reference to this iterator after it is incremented)
		iterator operator++(int);                   // post-increment (returns an iterator to current node while incrementing the existing iterator)
	};

	iterator begin();
	iterator end();
};

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::begin()
{
	return head;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::end()
{
	return iterator(nullptr);
}

template<typename T>
inline tForwardList<T>::tForwardList()
{
	head = NULL;
	tail = NULL;
}

template<typename T>
inline tForwardList<T>::~tForwardList()
{
	while (head != NULL) { pop_front(); }
	delete head;
	delete tail;

}

template<typename T>
inline void tForwardList<T>::push_front(const T & val)
{
	Node *temp = new Node;
	temp->data = val;
	temp->next = head;
	if (head == NULL) 
	{
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else 
	{
		/*tail->next = temp;*/
		head = temp;
	}
}

template<typename T>
inline void tForwardList<T>::pop_front()
{
	Node *temp = new Node;
	temp = head;
	head = head->next;
	delete temp;
}

template<typename T>
inline T & tForwardList<T>::front()
{
	return head->data;
}

template<typename T>
inline const T & tForwardList<T>::front() const
{
	return head->data;
}

template<typename T>
inline void tForwardList<T>::remove(const T & val)
{
	if (head == NULL) { return; }
	do {
		if (head->data == val)
		{
			Node * temp = head;
			head = head->next;
			delete temp;
		}
	} while (head->data == val);

	Node *temp = head->next;
	Node *hold = head;
	while (temp != NULL) {
		if (temp->data == val)
		{
			hold->next = temp->next;
			temp = hold->next;
		}
		else
		{
			hold = hold->next;
			hold = temp;
			temp = temp->next;
		}
	}

}

template<typename T>
inline void tForwardList<T>::display()
{
	Node *temp = new Node;
	temp = head;
	while (temp != NULL) 
	{
		std::cout << temp->data << "\t";
		temp = temp->next;
	}
	delete temp;
}

template<typename T>
inline tForwardList<T>::iterator::iterator()
{
	cur = NULL;
}

template<typename T>
inline tForwardList<T>::iterator::iterator(Node * startNode)
{
	cur = startNode;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator==(const iterator & rhs) const
{
	return cur == rhs.cur;
}

template<typename T>
inline bool tForwardList<T>::iterator::operator!=(const iterator & rhs) const
{
	return !(*this == rhs);
}

template<typename T>
inline T & tForwardList<T>::iterator::operator*() const
{
	return cur->data;
}

template<typename T>
typename tForwardList<T>::iterator& tForwardList<T>::iterator::operator++()
{
	cur = cur->next;
	return *this;
}

template<typename T>
typename tForwardList<T>::iterator tForwardList<T>::iterator::operator++(int)
{
	iterator temp = cur;
	cur = cur->next;
	return temp;
}
