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
    Node * current = head;
    while(current != nullptr){
        Node * next = current->link;
        delete current;
        current = next;
    }
    head = nullptr;
}
// Returns if the linkedlist is empty
bool LinkedList::isEmpty(){
    return head == nullptr;
}

// Removes the first Node pointer which matches one in list. If nonexistent, does nothing.
// TODO: fix this function.
void LinkedList::remove(Node * item){
    if(item == head){
        head = nullptr;
    }
    else {
        Node * curr = head;
        while(curr->link != nullptr){
            Node * next = curr->link;
            // If the next node is the one to remove, point current to the other after next, or null
            if(next->sameAs(item)){
                Node * after = next->link;
                if(after == nullptr){
                    curr->link = nullptr;
                }
                else {
                    curr->link = after;
                }
                //Item was found to remove.
                break;
            }
            delete next;
            curr = curr->link;
        }
    }
}
// Adds Node to the end of linked list
void LinkedList::add(Node * item){
    if(head == nullptr){
        head = item;
    }
    else {
        Node * curr = head;
        // Loop to end of list
        while(curr->link != nullptr){
            curr = curr->link;
        }
        curr->link = item;
    }
}
//Adds Node to index in list, throws error if index out of bounds
void LinkedList::add(Node * item, int index){
    int count = 0;
    if(index < 0 || index > size()){
        throw std::invalid_argument("Insertion index out of bounds.");
    }
    Node * curr = head; 
    while(count != index){
        curr = curr->link;
        count++;
    }
    // before (current idx) -> item -> after 
    Node * before = curr;
    curr = item;
    if(before == nullptr) {
        curr->link = nullptr;
    }
    else {
        Node * after = before->link;
        item->link = after;
        before->link = item;
    }
}
std::string LinkedList::print(){
    Node * top = head;
    std::string output;
    while(top != nullptr){
       std::string line = top->info.print() + "=>";
       output += line;
       top = top->link;
    }
    output += "null";
    return output;
}