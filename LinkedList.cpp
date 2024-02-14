#include "Data.h"
#include "LinkedList.h"
#include <stdexcept>
#include <string>

/*
Singly Linked List Implementation. 
References: 
https://en.wikipedia.org/wiki/Linked_list 
http://cslibrary.stanford.edu/103/LinkedListBasics.pdf
*/

LinkedList::LinkedList(){
    head = nullptr;
}

//Removes the entire list
LinkedList::~LinkedList(){
    clear();
}

// Size of linkedlist
int LinkedList::size(){
    int length = 0;
    Node * curr = head;
    while(curr != nullptr){
        curr = curr->link;
        length++;
    }
    return length;
}
// Empties list, deletes all nodes. 
void LinkedList::clear(){
    while(head != nullptr){
       Node * current = head;
       head = head->link;
       delete current;
    }
}
// Returns if the linkedlist is empty
bool LinkedList::isEmpty(){
    return head == nullptr;
}

// Removes the first Node pointer which matches one in list. If nonexistent, does nothing.
void LinkedList::remove(Node * item){
    if(head == nullptr || item == nullptr){
        return;
    }
    else if(item->sameAs(head)){
        if(head->link != nullptr){
            setHead(head->link);
        }
        else { 
            head = nullptr;
        }
    }
    else {
        Node * curr = head; Node * past = nullptr;
        while(curr->link != nullptr) {
            past = curr;
            curr = curr->link;
            if(curr->sameAs(item)) {
                Node * next = curr->link;
                past->link = next;
                delete curr;
                return;
            }
        }
    }
}
// Removes the Node at a specified index
void LinkedList::remove(int index){
    checkIndex("Removal index out of bounds",index);
    int count = 0;
    Node * curr = head; Node * past = nullptr;
    while(count != index) {
        past = curr;
        curr = curr->link;
        count++;
    } 

    if(index == 0) {
        setHead(curr->link);
        return;
    }

    Node * next = curr->link;
    if(next == nullptr) { 
        past->link = nullptr;
    } 
    else { 
        past->link = next;
    }
}
// Adds Node to the end of linked list
void LinkedList::add(Node * item){
    if(head == nullptr) {
        head = item;
    }
    else {
        Node * curr = head;
        // Loop to end of list
        while(curr->link != nullptr) {
            curr = curr->link;
        }
        curr->link = item;
    }
}
//Adds Node to index in list, throws error if index out of bounds
void LinkedList::add(Node * item, int index){
    if (index < 0 || index > size()) {
        throw std::invalid_argument("Insertion index out of bounds");
    }   
    if(index == 0 && head == nullptr) {
        setHead(item);
        return;
    }
    else if(index == 0){
        item->link = head;
        head = item;
        return;
    }

    int count = 0;
    Node * curr = head; 
    
    // Move to right before inseration
    while(count != index - 1) {
        curr = curr->link;
        count++;
    }
    // curr -> item -> curr's link
    item->link = curr->link;
    curr->link = item;
}

// Gets Node at specified index.
Node * LinkedList::get(int index) {
    checkIndex("Access index out of bounds.",index);
    Node * curr = head;
    int count = 0;
    while(count != index) {
        curr = curr->link;
        count++;
    }
    return curr;
    
}
// Finds index for specified Node, returns -1 otherwise
int LinkedList::find(Node * nd){
    if(head == nullptr){
        return -1;
    }
    Node * curr = head; int ind = 0;
    while(curr->link != nullptr){
        if(curr->sameAs(nd)){
            return ind;
        }
        curr = curr->link;
        ind++;
    }
    return -1;
}
// Sets Node at specified index.
void LinkedList::set(Node * item, int index){
    checkIndex("Set index out of bounds.",index);
    if(index == 0){
        setHead(item);
        return;
    }
    Node * curr = head;
    int count = 0;
    while(count < index - 1){
        curr = curr->link;
        count++;
    }
    // Curr -> ITEM -> toSet->link;
    Node * toSet = curr->link;
    curr->link = item;
    item->link = toSet->link;  
    delete toSet; // must be removed.
}

// Returns string representation of singly linked list.
std::string LinkedList::print() {
    Node * top = head;
    if(top == nullptr){
        return "empty.";
    }
    std::string output;
    while(top != nullptr) {
       std::string line = top->info.print() + "=>";
       output += line;
       top = top->link;
    }
    output += "null";
    return output;
}

// Throws specified error message if inputted index is out of bounds for list.
void LinkedList::checkIndex(std::string msg, int possibleInd) {
    if(possibleInd < 0 || possibleInd >= size()) {
        throw std::invalid_argument(msg);
    }
}