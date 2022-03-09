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

    if (id > 0 && !data->empty()){
        //preparing the new node to be added
        Node* newNode = new Node();
        newNode->data.id = id;
        newNode->data.data = *data;

       // //searching for place to add the node
       // while (id < position->data.id && position->next->data.id != id){
       //     position = position->next;
      //  }

        //are we at the head?
        if (position == NULL){
            newNode->prev = NULL;
            newNode->next = NULL;
            head = newNode;
            added = true;
            std::cout << "executed first if" << std::endl;

        //are we at the tail?
        } else if(position->next == NULL){
            newNode->next = NULL;
            newNode->prev = position;
            position->next = newNode;
            added = true;
            std::cout << "executed else if" << std::endl;

        } else{
            while (id < position->data.id && position->next->data.id != id){
            position = position->next;
            }

            newNode->next = position;
            newNode->prev = position->prev;
            position->prev->next = newNode;
            position->prev = newNode;
            std::cout << "executed else position is " << position << std::endl;

        } 

    }else{
        std::cout << "Could not add node" << std::endl;
    } 
    return added;
}

/*   


 //preparing the new node to be added
    Node* newNode = new Node();
    newNode->data.id = id;
    newNode->data.data = *data;

   
    newNode->prev = NULL;
    newNode->next = NULL;
    head = newNode;

    */






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