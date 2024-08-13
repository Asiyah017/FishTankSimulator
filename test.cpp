/* * Linked lists of strings. * * (c) Mark A. Sheldon, Tufts University, Spring 2018 */
#include <iostream> #include <stdexcept>
#include "StringLinkedList.h"
using namespace std;
/* * Useful helper functions for allocating a new Node on the * heap and initializing it. * Native C++ speakers would make Node constructors for this. * * StringLinkedList:: is required Node, because C++ hasn’t * realized this function is in the class yet. */ StringLinkedList::Node *StringLinkedList::newNode(string s, Node *next) {        Node *result = new Node;
        result−>element = s;        result−>next    = next;
        return result; }
/* * Return a new Node instance whose next field is the nullptr, * suitable if this is the last node in a list, or if we don’t  * know the next field’s value yet. */ StringLinkedList::Node *StringLinkedList::newNode(string s) {        return newNode(s, nullptr); }
/* * Initialize an empty list instance */ StringLinkedList::StringLinkedList() {        front = nullptr; }
/* * Reclaim all heap−allocated data associate with list */ StringLinkedList::~StringLinkedList() {        while (not isEmpty())                removeFirst(); }
/* * Return true if the list is empty, false otherwise */ bool StringLinkedList::isEmpty() {        return isEmpty(front); }
bool StringLinkedList::isEmpty(Node *first) {        return first == nullptr; }
Apr 15, 19 21:00Page 1/7 StringLinkedList.cpp
/* * If the list is empty, throw an exception with the given message. * Otherwise, return normally. */ void StringLinkedList::enforceNonEmpty(string message) {        if (isEmpty())                throw runtime_error(message); }
/* * Remove the first element (and associated node) from the list * Throws exception if list is empty */ void StringLinkedList::removeFirst() {        enforceNonEmpty("Cannot remove first of empty list");
        front = removeFirst(front); }
StringLinkedList::Node *StringLinkedList::removeFirst(Node *firstNode) {        Node *toDiscard = firstNode;        Node *newFirstNode = firstNode−>next;                // The following are not necessary, but can help us        // detect bugs later        toDiscard−>element = "*** I was deleted ***";        toDiscard−>next    = nullptr;
        delete toDiscard;
        return newFirstNode; }
/* * Return first element in the list. * Assume list is non−empty. */ string StringLinkedList::firstElement() {        enforceNonEmpty("Cannot get first of empty list");        return front−>element; }
/* * Add the given string to the front of the list */ void StringLinkedList::addToFront(string s) {        front = newNode(s, front); }
Apr 15, 19 21:00Page 2/7 StringLinkedList.cpp Printed by Mark Sheldon
Monday April 15, 20191