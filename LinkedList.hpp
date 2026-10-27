#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
	using std::string;

class ListException {
	private :
		string m_location;
		string m_message;
	public :
		ListException(const string& where_thrown, const string& msg) {
			m_location = where_thrown;
			m_message = msg;
		}
		
		string to_string() const {
			return "*** StackException in "+
				m_location + ": "+m_message;
		}
};

class LinkedList {
	private :
		// private inner class
		class Node {
		public:
			string element;
			Node * next;
			Node * prev;
			
			Node(const string &value, Node * nxt=nullptr, Node * prv=nullptr) {
				element = value;
				next = nxt;
				prev = prv;
			}
		};

		Node * first;
		Node * last;
		Node * current;
		int m_size;

	public:
	/*******************  Constructors / Destructors ***************/
		LinkedList();
		~LinkedList();
		// note: there is no copy constructor
		// We do not expect to make copies.

		/******************  Getters, Setters *****************/
		string get_first() throw (ListException);
		string get_last() throw (ListException);
		string get_current() const throw (ListException);
		void set_current(int index) throw (ListException);
		int get_size() const;
		bool is_empty() const;
		string next() throw (ListException);
		string prev() throw (ListException);

		/****************** Updating ************************/
		string update_current(string element) throw (ListException);

		/******************  Inserting **********************/
		void insert_first(string element);
		void insert_last(string element);
		void insert_after_current(string element);
		void insert_before_current(string element);

		/*****************  Removing ***********************/
		string remove_first() throw (ListException);
		string remove_last() throw (ListException);
		string remove_current() throw (ListException);

		/**************** Printing ***********************/
		void print_contents() const;
		void print_contents_reverse() const;
};
 
#endif
