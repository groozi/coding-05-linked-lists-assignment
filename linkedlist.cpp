/**********************************************************
 * Name: Graziella Buitron
 * Coding 05
 * Purpose: To create a fully functional doubly linked list
 *********************************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

bool LinkedList::addNode(int id , string *data){
    bool added;

    if (id > 0 && *data != "/0"){
        Node* position = head;
        Node **nodeHolder;

        //if list is empty or if id of new node is less than position's id add a new head
        if (position == NULL || id < position->data.id){
            addHead(id, data, position, *nodeHolder);
            added = true;
        }else{
            //search for place to add node
            while (id > position->data.id && position->next != NULL){
                position = position->next;
            }
            if (id == position->data.id){
                added = false;
            //if id is greater than position's id and we ARE at the end of the list, add a new tail
            }else if(id > position->data.id && position->next == NULL){
                addTail(id, data, position, *nodeHolder);
                added = true;
            }else{
                //in any other case we add to middle of the list
                addMiddle(id, data, position, *nodeHolder);
                added = true;
            }
        }
    }else{
        added = false;
    } 
    return added;
}

void LinkedList::printList(bool backward){
    Node* position = head;
    if(position == NULL){
        std::cout << "List is empty" << std::endl;
    }

    else if (backward == true){
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

bool LinkedList::exists(int id){
    bool nodeFound; 
    Node* position = head;

    if (id == position->data.id){
        nodeFound = true;
    } else {
        while(id != position->data.id && position->next!= NULL){
            position = position->next;
        }
        if (id == position->data.id){
            nodeFound = true;
        } 
        else{
            nodeFound = false;
        }
    }
    return nodeFound;
}

bool LinkedList::clearList(){
    Node* position = head;
    bool listCleared = false;

    while (position != NULL){
        head = position->next;
        delete position;
        position = position->next;
    }
    delete (head);

    if (head==NULL){
        listCleared = true;
    }
    return listCleared;
}



void LinkedList::addHead(int id, string *data, Node* position, Node* nodeHolder){
    prepNode(id, data, &nodeHolder);

    if (position == NULL){
        nodeHolder->prev = NULL;
        nodeHolder->next = NULL;
    } else{
        nodeHolder->prev = NULL;
        nodeHolder->next = position;
        position->prev = nodeHolder;
    }

    head = nodeHolder;

    /*
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
    */
}

void LinkedList::addTail(int id, string *data, Node* position, Node* nodeHolder){

    prepNode(id, data, &nodeHolder);
    nodeHolder->next = NULL;
    nodeHolder->prev = position;
    position->next = nodeHolder;

    /*
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    newNode->next = NULL;
    newNode->prev = position;
    position->next = newNode;
    */
}

void LinkedList::addMiddle(int id, string* data, Node* position, Node* nodeHolder){
    prepNode(id, data, &nodeHolder);

    nodeHolder->next = position;
    nodeHolder->prev = position->prev;
    position->prev->next = nodeHolder;
    position->prev = nodeHolder;


    /*
    Node* newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;

    newNode->next = position;
    newNode->prev = position->prev;
    position->prev->next = newNode;
    position->prev = newNode;
    */
}

void LinkedList::prepNode(int id, string *data, Node** nodeHolder){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    *nodeHolder = newNode;

    //not sure if you need this line~ newNode->next = NULL;

}


