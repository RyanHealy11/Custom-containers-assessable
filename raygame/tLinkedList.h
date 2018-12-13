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
};

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
