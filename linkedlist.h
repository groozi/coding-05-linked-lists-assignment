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
    void printList(); //if bool is false, list will print forward
    bool addNode(int, string*); 

private:
    Node *head;
    //void addHead(int, string*, Node**);


};

#endif //