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
        //Node **nodeHolder;

        if (position == NULL || id < position->data.id){
            //prepNode(id, data, nodeHolder);
            addHead(id, data);
            added = true;

        }else{
            //looping through data to check if id i less than current position and checking for dupes
            while (id > position->data.id && position->next != NULL){
                position = position->next;
            }
            if (id == position->data.id){
                added = false;
                std::cout << "Could not add node. Id already exists" << std::endl;

            }else if(id > position->data.id && position->next == NULL){
                addTail(id, data, position);
                added = true;
            }else{
                //addMiddle(id, data, position);
                
                Node* newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *data;

                newNode->next = NULL;
                newNode->prev = position;
                position->next = newNode;
                added = true;
                //addMiddle(id, data, position);
                
            }
        }
    }else{
        std::cout << "Could not add node" << std::endl;
    } 
    return added;
}

void LinkedList::addHead(int id, string *data){
    /*
    Node* position = head;
    prepNode(id, data, nodeHolder);
    
    if (position == NULL){
        *nodeHolder->prev = NULL;
        *nodeHolder->next = NULL;
        //head = newNode;
    } else{
        *nodeHolder->prev = NULL;
        *nodeHolder->next = position;
        position->prev = *nodeHolder;
    }
   head = newNode;
    */

    Node* newNode = new Node;
    Node* position = head;

    newNode->data.id = id;
    newNode->data.data = *data;

    if (position == NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
        //head = newNode;
    } else{
        newNode->prev = NULL;
        newNode->next = position;
        position->prev = newNode;
    }
   head = newNode;
   
}

void LinkedList::addTail(int id, string *data, Node *nodePtr){
    //prepping the new node
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    newNode->next = NULL;
    newNode->prev = nodePtr;
    nodePtr->next = newNode;
}

/*
void LinkedList::addMiddle(int id, string *data, Node* nodePtr){
    std::cout << "fails in the addMiddle function" << std::endl;
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;


    newNode->prev = nodePtr->prev;
    newNode->next = nodePtr;
    nodePtr->prev->next = newNode;
    nodePtr->prev = newNode;

    //newNode->next = nodePtr;
    //newNode->prev = nodePtr->prev;
    //nodePtr->prev->next = newNode;
    //nodePtr->prev = newNode;

}

*/

/*
void LinkedList::prepNode(int id, string* data, Node** nodeHolder){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    *nodeHolder = newNode;
}
*/

void LinkedList::printList(){
    Node* current = head;

    while (current){
        std::cout << current->data.id << ": " << current->data.data << " " << current<< std::endl;
        current = current->next;
    }
}