#include "../../include/Structures/DoublyLinkedList.h"
#include "../../include/Structures/Data.h"
#include "../../include/Common/MusicPlayer.h"
#include <stdexcept>
#include <string>

/*
Doubly Linked List implementation
Sources: 
https://en.wikipedia.org/wiki/Doubly_linked_list
https://www.jsums.edu/nmeghanathan/files/2017/08/CSC228-Fall2017-Module-2-List-ADT-v2.pdf?x61976
https://www.cs.cmu.edu/~mrmiller/15-121/Slides/13-DoublyLinkedList.pdf
*/

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
    clear();
}

// Clears entire list
template<class T>
void DoublyLinkedList<T>::clear(){
    DoublyLinkedNode<T> * curr = head;
    while(curr != nullptr){
        DoublyLinkedNode<T> * nxt = curr->next;
        delete curr;
        curr = nxt;
    }
    head = nullptr;
    tail = nullptr;
}
// Returns size of list
template<class T>
int DoublyLinkedList<T>::size(){
    int len = 0;
    DoublyLinkedNode<T> * curr = head;
    while(curr != nullptr){
        curr = curr->next;
        len++;
    }
    return len;
}
// Returns true if list is empty
template<class T>
bool DoublyLinkedList<T>::isEmpty(){
    return head == nullptr;
}

// Removes first ordered occurence of DoublyLinkedNode (same data), if found.
template<class T>
void DoublyLinkedList<T>::remove(DoublyLinkedNode<T> * nd){
    if(nd == nullptr) { // invalid case.
        return;
    }
    DoublyLinkedNode<T> * curr = head; 
    while(curr != nullptr) {
        if(curr == nd) { // T must have == operator
            DoublyLinkedNode<T> * after = curr->next;
            DoublyLinkedNode<T>  * before = curr->prev;
            if(before != nullptr){
                if(after != nullptr){
                    before->next = after;
                    after->prev = before;
                }
                else { // we are at tail
                    tail = before;
                    tail->next = nullptr;
                }
            }
            else { // we are at head
                head = curr->next;
                if(head == nullptr) {
                    tail = nullptr;
                }
                else {
                    head->prev = nullptr;
                }

            }
        delete curr;
        return;
        }
        curr = curr->next;
    }   
}
// Removes DoublyLinkedNode at index, throws error if out of range
template<class T>
void DoublyLinkedList<T>::remove(int remove_idx){
    checkIndex("Index out of bounds for removal",remove_idx);
    DoublyLinkedNode<T> * curr = head; 
    int currentIdx = 0;
    while(currentIdx != remove_idx){
        curr = curr->next;
        currentIdx++;
    }
    // prev -> <-after
    if(curr->prev != nullptr){
        DoublyLinkedNode<T> * previous = curr->prev;
        previous->next = curr->next;
        if(curr->next != nullptr){
            DoublyLinkedNode<T> * after = curr->next;
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
// Adds DoublyLinkedNode to end of list
template<class T>
void DoublyLinkedList<T>::add(DoublyLinkedNode<T> * nd){
    if(head == nullptr){
        head = nd;
        head->prev = nullptr;
        head->next = nullptr;
        tail = nd;
    }
    else {
        // oldtail -> <- nd -> nullptr
        nd->next = nullptr;
        nd->prev = tail;
        tail->next = nd;
        tail = nd;
    }
}
// Adds DoublyLinkedNode to doubly linked list after the specified index at (0 -> size() - 1)
// TODO: Fix.
template<class T>
void DoublyLinkedList<T>::add(DoublyLinkedNode<T> * nd, int ind){
    checkIndex("Invalid index to add. ",ind);
    int len = size();
    int counter = 0;
    DoublyLinkedNode<T> * curr = head; 
    if(ind == 0) {     // At head?
        if(len == 0) {
            nd->prev = nd->next = nullptr;
            head = nd;
        }
        else {
            nd->prev = head;
            if(head->next != nullptr) {
                head->next->prev = nd;
                nd->next = head->next;
                head->next = nd;
            }
            else { 
                nd->next = nullptr;
                head->next = nd;
            }   
        }

    }
    else if(ind == size() - 1) {     // At tail?
        nd->prev = tail;
        tail->next = nd;
        nd->next = nullptr;
        tail = nd;
    }
    else { // Somewhere inside list.
        while(counter != ind) {
            curr = curr->next;
            counter++;
        }
        nd->next = curr->next;
        nd->prev = curr;
        curr->next->prev = nd;
        curr->next = nd;
    }
}
// Reverses the doubly linked list. Unfinished.
template <class T>
void DoublyLinkedList<T>::reverse(){
  DoublyLinkedNode<T> * tmp = nullptr;
  DoublyLinkedNode<T> * curr = head;
  tail = head;
  if(head != nullptr){
    tail->prev = head->next;
  }
  while(curr != nullptr){
    tmp = curr->prev;
    curr->prev = curr->next;
    curr->next = tmp;
    curr = curr->prev;
  }
  if(tmp != nullptr){
    head = tmp->prev;
  }
}
// Returns DoublyLinkedNode at Head
template <class T>
DoublyLinkedNode<T> * DoublyLinkedList<T>::getHead(){
    if(head != nullptr){
        return head;
    }
    throw std::invalid_argument("No list head to get.");
}
// Returns DoublyLinkedNode at specified index
template <class T>
DoublyLinkedNode<T> * DoublyLinkedList<T>::get(int ind){
    checkIndex("Invalid index to get",ind);
    DoublyLinkedNode<T> * curr = head;
    for(int i = 0; i<ind ;i++){
        curr = curr->next;
    }
    return curr;
}
// Searches for DoublyLinkedNode in list, returns index if found, -1 otherwise.
template<class T>
int DoublyLinkedList<T>::find(DoublyLinkedNode <T> * nd) {
    // Implementing a bidirectional search
    int ind_head = 0;
    int ind_tail = size() - 1;
    DoublyLinkedNode<T> * curr_front = head;
    DoublyLinkedNode<T> * curr_back = tail;
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
// Sets DoublyLinkedNode at specific index to inputted data
template<class T>
void DoublyLinkedList<T>::set(DoublyLinkedNode<T> * nd, int ind){
    checkIndex("Invalid index to set.",ind);
    if(ind == 0){
        nd->prev = nullptr;
        nd->next = head->next;
        head = nd;
    }
    else if(ind == size() - 1){
        nd->prev = tail->prev;
        nd->next = nullptr;
        tail = nd;
    }
    else { //somewhere inside list
        DoublyLinkedNode<T> * curr = head;
        for(int i = 0; i < ind; i++){
            curr = curr->next;
        }
        nd->prev = curr->prev;
        nd->next = curr->next;
        curr = nd;
    }

}

// Throws specified error message if inputted index is out of bounds for list.
template<class T>
void DoublyLinkedList<T>::checkIndex(std::string msg, int possibleInd) {
    if(possibleInd < 0 || possibleInd >= size()) {
        throw std::invalid_argument(msg);
    }
}

// Explicit instantiations:
template class DoublyLinkedList<int>; 
template class DoublyLinkedList<std::string>; 
template class DoublyLinkedList<Data>;
template class DoublyLinkedList<Song>;