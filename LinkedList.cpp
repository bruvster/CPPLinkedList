/*
    Author : Mia Murray
    Date   : February 27th 2020
    Title  : CSCI 161 - Assignment 6

    Invariants :
    -m_size must be accurate, must be 0 if empty
    -Node must contain element
    -Node must have accurate prev/next, if none exist pointers should be null
    -list must have a first and last element, if empty then both should be null
    -when list isn't empty, current will point to last inserted element (until user moves it)
    -a list with one element will have first, last, and current pointing to said element

    A Program for doubly linked list that has the functionality of inserting,
    removing, and peeking at any element in the list within O(1). The user also 
    has the ability of traversing the list linearly with the implementation of a 
    'current' pointer. Finally, the contents of the list can be printed 
*/
#include "LinkedList.hpp"
#include<iostream>
using std::cout;
using std::endl;
using std::string;

/*******************  Constructors / Destructors ***************/
LinkedList::LinkedList() 
{
	first = last = current = nullptr;
	m_size = 0;
}

LinkedList::~LinkedList() 
{
	while (first) 
	{
		remove_first();
	}
}

/******************  Inserting **********************/
void LinkedList::insert_first(string element) 
{
	first = new Node(element, first);
	if (is_empty()) 
	{
		current = last = first;
	} else 
	{
		first->next->prev = first;
		current = first;
	}
	m_size++;
	return;
}

void LinkedList::insert_last(string element) 
{
	last = new Node(element,nullptr,last);
	if (is_empty()) 
	{
		current = first = last;
	} else 
	{
		last->prev->next = last;
		current = last;
	}
	m_size++;
	return;
}

void LinkedList::insert_before_current(string element)
{
	if (is_empty() || current == first) 
	{
		insert_first(element);
	} else 
	{
		current = new Node(element,current,current->prev);
		current->next->prev = current;
		current->prev->next = current;	
		m_size++;
	}
	return;
}
	
void LinkedList::insert_after_current(string element) 
{
	if (is_empty() || current == last) 
	{
		insert_last(element);
	} else 
	{
		current = new Node(element,current->next, current);
		current->next->prev = current;
		current->prev->next = current;
		m_size++;
	}
	return;
}

/**************** Printing ***********************/
void LinkedList::print_contents() const
{
	for (Node * t=first; t != nullptr; t=t->next) 
	{
		cout << "[" << t->element << "]" << endl;
	}
	return;
}

void LinkedList::print_contents_reverse() const 
{
	for (Node * t=last; t != nullptr; t=t->prev) 
	{
		cout << "[" << t->element << "]" << endl;
	}
	return;
}

/******************  Getters, Setters *****************/
string LinkedList::get_first() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("get_first()", "list is empty");
	}
	string elem = first->element;
	return elem;
}

string LinkedList::get_last() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("get_last()", "list is empty");
	}
	string elem = last->element;
	return elem;
}

string LinkedList::get_current() const throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("get_current()", "list is empty");
	}
	string elem = current->element;
	return elem;
}

void LinkedList::set_current(int index) throw (ListException)
{
	if (is_empty() == true)
	{
		return;
	}else if (index < 0 || index >= m_size)
	{
		throw ListException("set_current()", "index out of bounds");
	}
	int counter = 0;
	for (Node *t = first; t != nullptr; t=t->next)
	{
		if(counter == index)
		{
			current = t;
			break;
		}
		counter ++;
	}
	return;
}

int LinkedList::get_size() const
{
	return m_size;
}

bool LinkedList::is_empty() const
{
	if(m_size == 0)
	{
		return true;
	}
	return false;
}

string LinkedList::next() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("next()", "list is empty");
	}
	current = current->next;
	string elem = current->element;
	return elem;
}

string LinkedList::prev() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("prev()", "list is empty");
	}
	current = current->prev;
	string elem = current->element;
	return elem;
}

/*****************  Removing ***********************/
string LinkedList::remove_first() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("remove_first()", "list is empty");
	}
    string elem = first->element;
    Node* temp = first->next;
    delete first;
    first = temp;
	first->prev = nullptr;
    m_size --;
	if(m_size == 1)
	{
		first = last = current;
	}else if (is_empty() == true)
	{
		first = last = current = nullptr;
	}
    return elem;
}

string LinkedList::remove_last() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("remove_last()", "list is empty");
	}
    string elem = last->element;
    Node* temp = last->prev;
    delete last;
    last = temp;
	last->next = nullptr;
    m_size --;
	if(m_size == 1)
	{
		first = last = current;
	}else if (is_empty() == true)
	{
		first = last = current = nullptr;
	}
    return elem;
}

string LinkedList::remove_current() throw (ListException)
{
	if(is_empty() == true)
	{
		throw ListException("remove_current()", "list is empty");
	}
    string elem = current->element;
	current->prev->next = current->next;
	current->next->prev = current->prev;
    Node* temp = current->prev;
	delete current;
	current = temp;
	m_size --;
	if(m_size == 1)
	{
		first = last = current;
	}else if (is_empty() == true)
	{
		first = last = current = nullptr;
	}
    return elem;
}

/****************** Updating ************************/
string LinkedList::update_current(string element) throw (ListException)
{
	if (is_empty() == true)
	{
		throw ListException("update_current()", "list is empty");
	}
	string tmp = current->element;
	current->element = element;
	return tmp;
}

			

