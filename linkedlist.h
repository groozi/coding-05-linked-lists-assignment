/**********************************************************
 * Name: Graziella Buitron
 * Coding 05
 * Purpose: To create a fully functional doubly linked list
 *********************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList {

public:

    LinkedList();
    ~LinkedList();
    void printList(bool = false); //if bool is false, list will print forward
    bool addNode(int, string*); 
    int getCount();
    bool deleteNode(int); 
    bool getNode(int, Data*);
    bool exists(int);
    bool clearList();

private:
    Node *head;
    void addHead(int, string*, Node*, Node*);
    void addTail(int, string*, Node*);
    void addMiddle(int, string*, Node*);
    void prepNode(int, string*, Node**);

};

#endif //LINKEDLIST_H