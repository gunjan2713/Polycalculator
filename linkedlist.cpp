
#include <iostream>
#include <fstream>
#include<iostream>
#include "linkedlist.h"
using namespace std;

// Constructor to create empty list(head ==nullptr)
LinkedList::LinkedList(){
      head=nullptr;
}
// Insert function simplifies and sorts expressions
void LinkedList::insert(int coef, int expo) {
    // Creating a new node
    Node* newNode = new Node(coef, expo);

    // If the list is empty, insert the new node at the beginning
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        Node* previous = nullptr;

        // traverse list to find right place to insert the node when expo is less than current expo
        while (current && expo < current->expo) {
            // store current to previous
            previous = current;
            // move pointer to next node
            current = current->next;
        }

        // checking if exponents are equal
        if (current && expo == current->expo) {
            // add both the coeffcients 
            current->coef = current->coef + coef;
            // if coeeficient becomes zero
            if (current->coef == 0) {
                // remove the node form the polynomial
                if (previous) {
                    previous->next = current->next;
                } else {
            // if there is no previous noce, move head to next node
                    head = current->next;
                }
                delete current;
            }
        } else {
            // Insert the new node at the correct position
            newNode->next = current;
            if (previous) {
                previous->next = newNode;
            } else {
                // / if there is no previous node,update the head
                head = newNode;
            }
        }
    }
}

// To print the expressins
void LinkedList::print(ostream& os) const {
    
    const Node* current = head;
   // it will run until it reaches end of the list
    while (current) {
        
// checking if current is not head
        if (current!=head) {
            // if coeff is posiitve
            if(current->coef>=0){
                os << " + ";
            }
            // if coef is negative give space, as it already takes sign with it, no need to add sign again
            else{
                os << "  ";
            }
            
        }
        // this is responsib for actually printing the 
        os << current->coef << "x^" << current->expo;
        current = current->next;
    }
    os << endl;
}
// deleting all nodes of the list
void LinkedList::removeAll() {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
// calling remove all in destructor
LinkedList::~LinkedList() {
    removeAll();
}
// this function returns head of list
Node* LinkedList::getHead() {
    return head;
}
// checks if list is empty
bool LinkedList::empty() {
    // if head is null then it means it is empty
    if(head==nullptr){
        return true;
    }
}
