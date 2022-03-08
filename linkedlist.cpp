/**********************************************************
 * Name: Graziella Buitron
 * Coding 05
 * Purpose: To create a fully functional doubly linked list
 *********************************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    //Node *head = NULL;


    Node *node1;
    node1 = new Node;

    Node *node2; 
    node2 = new Node;

    Node *node3;
    node3 = new Node;
    
    node1->data.id = 1; 
    node1->data.data = "Helloooo"; 

    node2->data.id = 2; 
    node2->data.data = "World"; 

    node3->data.id = 3; 
    node3->data.data = "This is working! woo";
    
    head = node1;         // first point the head at node1
    node1->prev = NULL;   // point node1 prev to NULL because there is no previous
    node1->next = node2;  // point node1 next to node2
    node2->prev = node1;  // point node2 back to node1
    node2->next = node3;  // point node2 next to node3
    node3->prev = node2;  // point node3 back to node2
    node3->next = NULL; 
}

void LinkedList::printList(bool backward){
    Node* current = head;

    while (current){
        std::cout << current->data.id << ": " << current->data.data << std::endl;
        current = current->next;
    }
}