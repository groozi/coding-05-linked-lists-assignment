/**********************************************************
 * Name: Graziella Buitron
 * Coding 05
 * Purpose: To create a fully functional doubly linked list
 *********************************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    Node *head = NULL;
}

bool LinkedList::addNode(int id , string *data){
    Node* position = head;
    bool added = false;

    /*
    if (id > 0 && !string->empty()){


    }

    */






    
    //preparing the new node to be added
    Node* newNode = new Node();
    newNode->data.id = id;
    newNode->data.data = *data;

    head = newNode;
    head->prev = NULL;
    newNode->next = NULL;
    head = newNode;
    
        

 return added;
}

/*
void LinkedList::addHead(int id, string *data, Node** head){
    Node* newNode = new Node();
    newNode->data.id = id;
    newNode->data.data = *data;
    newNode->next = *head;
    *head = newNode;

}

*/




void LinkedList::printList(){
    Node* current = head;

    while (current){
        std::cout << current->data.id << ": " << current->data.data << std::endl;
        current = current->next;
    }
}