/**********************************************************
 * Name: Graziella Buitron
 * Coding 05
 * Purpose: To create a fully functional doubly linked list
 *********************************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

bool LinkedList::addNode(int id , string *data){
    bool added; //will tell us if node added successfully or not

    //checks if id is greater than 0 and the string is not empty
    if (id > 0 && *data != "/0"){

        Node* position = head;

        //checks if current head is null (list is empty) or if id of new node is less than head's id
        if (position == NULL || id < position->data.id){

            addHead(id, data);
            /*

            //if any of these are true we are adding a new head

            //creating and assigning id and data to new node
            Node* newNode = new Node;
            newNode->data.id = id;
            newNode->data.data = *data;

            //if list is empty, new node next and prev point to null
            if (position == NULL){
                newNode->prev = NULL;
                newNode->next = NULL;
            
            //list is not empty but we are adding new node to front of list
            }else{
                newNode->prev = NULL;
                newNode->next = position;
                position->prev = newNode;

            }

            head = newNode;
            added = true;

            */

        }else{
            Node* position = head;

            //looping through data to check if id i less than current position and making sure we are not at tail
            while (id > position->data.id && position->next != NULL){
                position = position->next;
            }

            //if id is equal to an id we already have, don't include in list
            if (id == position->data.id){
                added = false;
                std::cout << "Could not add node. Id already exists" << std::endl;

            //is id greater than the id in the current position and we ARE at the end of the list? add a new tail
            }else if(id > position->data.id && position->next == NULL){
            
                //making and prepping the new node
                Node *newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *data;

                newNode->next = NULL;
                newNode->prev = position;
                position->next = newNode;
                added = true;

            }else{
                //in any other case we are adding to middle of the list
                
                //making and prepping the new node
                Node* newNode = new Node;
                newNode->data.id = id;
                newNode->data.data = *data;

                newNode->next = position;
                newNode->prev = position->prev;
                position->prev->next = newNode;
                position->prev = newNode;
                added = true;
            }
        }
    }else{
        std::cout << "Could not add node" << std::endl;
    } 
    return added;
}

void LinkedList::printList(bool flag){
    Node* current = head;

    if (flag == true){
        while(current->next != NULL){
            current = current->next;
        }
        while (current){
            std::cout << current->data.id << ": " << current->data.data << " " << current<< std::endl;
            current = current->prev;
        }
    }

    //if bool is false, print forward 
    else {
        while (current){
            std::cout << current->data.id << ": " << current->data.data << " " << current<< std::endl;
            current = current->next;
        }
    }
}

void LinkedList::addHead(int id, string *data){
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    if (head == NULL){
        newNode->prev = NULL;
        newNode->next = NULL;
    } else {
        newNode->prev = NULL;
        newNode->next = head;
        head->prev = newNode;
    }
    head = newNode;
}








