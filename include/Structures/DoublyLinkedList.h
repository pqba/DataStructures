#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string> 


// DoublyLinkedNode class with template types. Must implement == on data for correctness.
template <class T>
struct DoublyLinkedNode {
    T data;
    DoublyLinkedNode<T> * prev;
    DoublyLinkedNode<T> * next;
    DoublyLinkedNode(const T& data): data(data), prev(nullptr),next(nullptr) {}
    bool operator==(const DoublyLinkedNode<T>& rhs) {
        return this->data == rhs.data;
    }
};

// Doubly Linked List header
template<class T>
class DoublyLinkedList {
    private:
        DoublyLinkedNode<T>* head;
        DoublyLinkedNode<T>* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        int size();
        void clear();
        bool isEmpty();

        void remove(DoublyLinkedNode<T> *);
        void remove(int);
        void add(DoublyLinkedNode<T> *);
        void add(DoublyLinkedNode<T> *, int);
        void reverse();

        DoublyLinkedNode<T> * get(int);
        DoublyLinkedNode<T> * getHead();
        int find(DoublyLinkedNode<T> *);
        void set(DoublyLinkedNode<T> *, int);

        void checkIndex(std::string,int);
};

#endif

