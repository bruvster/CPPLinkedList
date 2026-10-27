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
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cin;

int main()
{
    cout << "*CREATING A NEW LIST*\n";
    LinkedList list1;
    string elem;
    if (list1.is_empty() == true)
    {
        cout << "The new list is empty\n";
    }else if (list1.is_empty() == false)
    {
        cout << "This list is not empty\n";
    }

    cout << "\n";
    cout << "*INSERT ELEMENTS FIRST*\n";
    for (int i = 0; i < 2; i ++)
    {
        cin >> elem;
        list1.insert_first(elem);
    }

    cout << "\n";
    cout << "*INSERTING ELEMENT BEFORE CURRENT*\n";
    list1.insert_before_current("beforecurrent");

    cout << "\n";
    cout << "*INSERT ELEMENTS LAST*\n";
    for (int i = 0; i < 2; i ++)
    {
        cin >> elem;
        list1.insert_last(elem);
    }

    cout << "\n";
    cout << "*INSERTING ELEMENT AFTER CURRENT*\n";
    list1.insert_after_current("aftercurrent");

    cout << "\n";
    cout << "*GETTING FIRST ELEMENT*\n";
    cout << list1.get_first() << endl;

    cout << "*GETTING LAST ELEMENT*\n";
    cout << list1.get_last() << endl;

    cout << "\n";
    cout << "*PRINTING CONTENTS OF LIST*\n";
    list1.print_contents();

    cout << "*PRINTING CONTENTS OF LIST IN REVERSE*\n";
    list1.print_contents_reverse();

    cout << "\n";
    cout << "*SETTING CURRENT TO INDEX POS 2*\n";
    list1.set_current(2);
    elem = list1.get_current();
    cout << "Current is now: " << elem << endl; 

    cout << "\n";
    cout << "*UPDATING CURRENT TO A NEW ELEMENT\n";
    string tmp = list1.update_current("newelem");
    cout << "old element was: " << tmp << endl;
    cout << "new element is: " << list1.get_current() << endl;

    cout << "*PRINTING CONTENTS OF LIST*\n";
    list1.print_contents();

    cout << "\n";
    cout << "The size of the list is: " << list1.get_size() << endl;

    cout << "\n";
    cout << "*CREATING A NEW LIST*\n";
    LinkedList list2;
    list2.insert_after_current("the");
    list2.insert_after_current("rain");
    list2.insert_after_current("in");
    list2.insert_after_current("spain");
    list2.insert_after_current("lies");
    list2.insert_after_current("mainly");
    list2.insert_after_current("on");
    list2.insert_after_current("the");
    list2.insert_after_current("plain");

    cout << "\n";
    cout << "*SETTING CURRENT TO INDEX POS 2*\n";
    list2.set_current(2);
    elem = list2.get_current();
    cout << "Current is now: " << elem << endl;
    elem = list2.next();
    cout << "The next element is: " << elem << endl;
    list2.set_current(2);
    elem = list2.prev();
    cout << "The previous element is: " << elem << endl;

    cout << "\n";
    cout << "*PRINTING CONTENTS OF LIST 2*\n";
    list2.print_contents();
    cout << "*REMOVING LAST ELEMENT*\n";
    list2.remove_last();
    cout << "*REMOVING FIRST ELEMENT*\n";
    list2.remove_first();
    list2.set_current(1);
    cout << "*REMOVING ELEMENT AT INDEX POSITION 1*\n";
    list2.remove_current();
    
    cout << "\n";
    cout << "*FINAL CONTENTS OF OUR SECOND LIST*\n";
    list2.print_contents();

    cout << "\n";
    cout << "*TESTING REMOVING FIRST ON AN EMPTY LIST*\n";
    LinkedList list3;
    try
    {
        list3.remove_first();
    }catch (const ListException &e)
    {
        cout << e.to_string() << endl;
    }

    return 0;
}