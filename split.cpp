/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void sort(Node*& set, Node* current);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

  if(in == NULL || in == nullptr) {
    return;
  }
  

  int x = in->value;
  Node* theNext = in->next;
  
  // odd
  if(x % 2 == 1) {
    // if odds is empty
    if(odds == NULL || odds == nullptr) {
      odds = in;
      in->next = nullptr;
    }
    else { // odds != nullptr
      sort(odds, in);
      
    }
  }
  else if(x % 2 == 0) { // even
    // if evens is empty
    if(evens == NULL || evens == nullptr) {
      evens = in;
      in->next = nullptr;
      // delete in;
    }
    else {
      // Node* temp = in;
      sort(evens, in);
    }
  }
  else {
    // std::cerr<<"ERROR: why is x neither??"<<std::endl;
    return;
  }
  in = NULL;
  // std::cout<<"split once"<<std::endl;
  split(theNext, odds, evens);
  

}

/* If you needed a helper function, write it here */

void sort(Node*& set, Node* current) {
  
  // set already has something inside of it
  Node* theNext = set->next;

  // for the case where set's size = 1 oor when we reach its end
  if(set == nullptr) {
    current->next = nullptr;
    set = current;
    return;
  }
  
  // if set size = 1
  if(set->next == nullptr) {
    if(current->value < set->value) {
      current->next = set;
      set = current;
      return;
    }
    else { // current is larger than the current set
      set->next = current;
      current->next = nullptr;
      return;
    }
  }

  if(current->value >= (set->next)->value) {
    sort(set->next, current);
  }
  else { // current->value < set->value
    // replace 
    current->next = theNext;
    set->next = current;
    return;
  }
  
 return;
}