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

        Node* newNode = new Node();
            newNode->data.id = id;
            newNode->data.data = *data;

        if (position == NULL || id < position->data.id){

            if(position == NULL){
                newNode->prev = NULL;
                newNode->next = NULL;
                head = newNode;
                added = true;
            } else {
                head->prev = newNode;
                newNode->next = head;
                newNode->prev = NULL;
                head = newNode;
                added = true;
            }
        }else {
            //looping through data to check if id i less than current position and checking for dupes
            while (id > position->data.id && position->next != NULL){
                position = position->next;
            }
            
            if (id == position->data.id){
                added = false;
                std::cout << "Could not add node. Id already exists" << std::endl;
            }else {
                newNode->next = NULL;
                newNode->prev = position;
                position->next = newNode;
                added = true;
            }
        }
    }else{
        std::cout << "Could not add node" << std::endl;
    } 
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


/*
void LinkedList::prepNode(int id, string *data, Node *passedNode){
        passedNode = new Node();
        passedNode->data.id = id;
        passedNode->data.data = *data;

}
*/



void LinkedList::printList(){
    Node* current = head;

    while (current){
        std::cout << current->data.id << ": " << current->data.data << " " << current<< std::endl;
        current = current->next;
    }
}