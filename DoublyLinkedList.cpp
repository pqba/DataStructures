#include "Data.h"
#include "DoublyLinkedList.h"
#include <stdexcept>
#include <string>

/*
Doubly Linked List implementation
Sources: https://en.wikipedia.org/wiki/Doubly_linked_list
https://www.jsums.edu/nmeghanathan/files/2017/08/CSC228-Fall2017-Module-2-List-ADT-v2.pdf?x61976
*/
DoublyLinkedList<class T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}
DoublyLinkedList<class T>::~DoublyLinkedList(){
    clear();
}

// Clears entire list
void DoublyLinkedList<class T>::clear(){
    Node<T> * curr = head;
    while(curr != nullptr){
        Node<T> * nxt = curr->next;
        nxt->prev = nullptr;
        delete curr;
        curr = nxt;
    }
    tail = nullptr;
}
// Returns size of list
int DoublyLinkedList<class T>::size(){
    int len = 0;
    Node<T> * curr = head;
    while(curr != nullptr){
        curr = curr->next;
        len++;
    }
    return len;
}
// Returns true if list is empty
bool DoublyLinkedList<class T>::isEmpty(){
    return head == nullptr;
}
// Removes first ordered occurence of Node (same data and links), if found.
void DoublyLinkedList<class T>::remove(Node<T> * nd){
    Node<T> * curr = head; //incomplete currently
    while(curr != nullptr){
        
    }   
}
// Removes Node at index, throws error if out of range
void DoublyLinkedList<class T>::remove(int remove_idx){
    checkIndex("Index out of bounds for removal",remove_idx);
    Node<T> * curr = head; 
    int currentIdx = 0;
    while(currentIdx != remove_idx){
        curr = curr->next;
        currentIdx++;
    }
    // prev -> <-after
    if(curr->prev != nullptr){
        Node<T> * previous = curr->prev;
        previous->next = curr->next;
        if(curr->next != nullptr){
            Node<T> * after = curr->next;
            after->prev = previous;
        }
        else { // we are at tail
            tail = previous;
        }
    }
    else { // we are at head
        head = curr->next;
        if(head == nullptr){
            tail = nullptr;
        }
        else {
            head->prev = nullptr;
        }
    }
    delete curr;
}
// Adds Node to end of list
void DoublyLinkedList<class T>::add(Node<T> * nd){
    if(head == nullptr){
        head = nd;
        tail = nd;
    }
    else {
        // oldtail -> <- nd -> nullptr
        nd->prev = tail;
        tail->next = nd;
        tail = nd;
    }
}

// Searches for Node in list, returns index if found, -1 otherwise.
int DoublyLinkedList<class T>::find(Node <T> * nd) {
    // Implementing a bidirectional search
    int ind_head = 0;
    int ind_tail = size() - 1;
    Node<T> * curr_front = head;
    Node<T> * curr_back = tail;
    while(curr_back != nullptr || curr_front !=nullptr) {
        if(curr_front == nd){
            return ind_head;
        }
        if(curr_back == nd){
            return ind_tail;
        }
        if(curr_front !=nullptr) {
            curr_front = curr_front->next;
            ind_head++;
        }
        if(curr_back!= nullptr) {
            curr_back = curr_back->prev;
            ind_tail--;
        }
    }
    return -1;
}

// Throws specified error message if inputted index is out of bounds for list.
void DoublyLinkedList<class T>::checkIndex(std::string msg, int possibleInd) {
    if(possibleInd < 0 || possibleInd >= size()) {
        throw std::invalid_argument(msg);
    }
}