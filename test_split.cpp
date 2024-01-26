/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{

    Node* h = new Node(4, nullptr);
    Node* g = new Node(12, h);
    Node* f = new Node(2, g);
    Node* e = new Node(8, f);
    
    Node* d = new Node(3, e);
    Node* c = new Node(5, d);
    Node* b = new Node(9, c);
    Node* a = new Node(1, b);

    // Node* a = new Node(2, nullptr);
    Node* nullNode = NULL;

    

    // while(a != nullptr) {
    //     cout<<a->value<<endl;
    //     a = a->next;
    // }
    Node* odds = NULL;
    Node* evens = NULL;

    cout<<"Hello!"<<endl;
    split(a, odds, evens);
    // split(nullNode, odds, evens);
    // sort(odds, a);
    
    // cout<<"Is odds empty: "<<(odds == nullptr)<<endl;

    while(odds != nullptr) {
        cout<<"For odds, "<<odds->value<<endl;
        odds = odds->next;
    }

    while(evens != nullptr) {
        cout<<"For evens, "<<evens->value<<endl;
        evens = evens->next;
    }
    
    // currently odds includes only the first and last element

    return 0;
}
