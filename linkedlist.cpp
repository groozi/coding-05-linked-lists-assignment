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
            added = true;

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

                addTail(id, data, position);
                added = true;

            }else{
                //in any other case we are adding to middle of the list
                addMiddle(id, data, position);
                added = true;
            }
        }
    }else{
        std::cout << "Could not add node" << std::endl;
    } 
    return added;
}

void LinkedList::printList(bool backward){
    Node* position = head;

    if (backward == true){
        while(position->next != NULL){
            position = position->next;
        }
        while (position){
            std::cout << position->data.id << ": " << position->data.data << " " << position<< std::endl;
            position = position->prev;
        }
    }
    //if bool is false, print forward 
    else {
        while (position){
            std::cout << position->data.id << ": " << position->data.data << " " << position<< std::endl;
            position = position->next;
        }
    }
}


bool LinkedList::deleteNode(int id){
    Node* position = head;
    bool deleted; 

    if (position == NULL){
        deleted = false;
        std::cout << "No nodes to delete..empty list" << std::endl;
    }
    else{
        while (id != position->data.id && position->next != NULL){
            position = position->next;
        }

        //couldn't find the node with id
        if(id != position->data.id){
            deleted = false;

        //deleting the head when it's the only thing in the list
        } else if(id == position->data.id && position->prev == NULL && position->next == NULL){
            delete(position);
            head = NULL;
            deleted = true;
        }

        //are we deleting the current head?
        else if (position->prev == NULL){
            head = position->next;
            position->next->prev = NULL;
            delete(position);
            deleted = true;
        }

        //are we deleting at end of list and must establish a new tail?
        else if(position->next == NULL){
            position->prev->next = NULL;
            delete(position);
            deleted = true;
        }
        //we are deleting from the middle of the list
        else if (position->next != NULL){
            position->prev->next = position->next;
            position->next->prev = position->prev;
            delete(position);
            deleted = true;
        }
    }
    return deleted;
}


int LinkedList::getCount(){
    Node* position = head;
    int count = 0;

    if (position != NULL){
       while(position){
        count++;
        position = position->next;
        } 
    }
    return count;
}

bool LinkedList::getNode(int id, Data* dataStruct){
    //begin at the head
    Node* position = head;
    bool gotNode;

    //compare id to current node
    if (id == position->data.id){
        dataStruct->id = position->data.id;
        dataStruct->data = position->data.data;
        gotNode = true;
    } else {
        while(id != position->data.id && position->next!= NULL){
            position = position->next;
        }

        if (id == position->data.id){
            dataStruct->id = position->data.id;
            dataStruct->data = position->data.data;
            gotNode = true;
        } 
        else{
            gotNode = false;
        }

    }

        return gotNode;
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

void LinkedList::addTail(int id, string *data, Node* position){
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    newNode->next = NULL;
    newNode->prev = position;
    position->next = newNode;
}

void LinkedList::addMiddle(int id, string* data, Node* position){
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    newNode->next = position;
    newNode->prev = position->prev;
    position->prev->next = newNode;
    position->prev = newNode;
}






