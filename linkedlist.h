#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include <fstream>

using namespace std;

class Node {
private:
    int coef; // coefficient of a term
    int expo; // exponent of a term
    Node* next; // Link (pointer) to the next Node

public:
    Node(int coef, int expo) : coef(coef), expo(expo), next(NULL) {}
    friend class LinkedList;
    friend class PolyCalculator;
};

class LinkedList {
private:
    Node* head; // pointer to the head of the Singly Linked list

public:
    LinkedList();  // empty list constructor

    void insert(int coef, int expo); // add a new Node (term) at the right place in the Linked List
    void print(ostream& os = cout) const;
    void removeAll(); // clean up (delete) all nodes
    ~LinkedList(); // destructor to clean up all nodes
    Node* getHead();
    bool empty();
    friend class PolyCalculator;
};


#endif