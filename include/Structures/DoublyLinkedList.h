#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string> 

// DLLNode class with template types. Must implement == on data for correctness.
template <class T>
struct DLLNode {
    T data;
    DLLNode<T> * prev;
    DLLNode<T> * next;
    DLLNode(const T& data): data(data), prev(nullptr),next(nullptr) {}
    bool operator==(const DLLNode<T>& rhs) {
        return this->data == rhs.data;
    }
};

// Doubly Linked List header
template<class T>
class DoublyLinkedList {
    private:
        DLLNode<T>* head;
        DLLNode<T>* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        int size();
        void clear();
        bool isEmpty();

        T pop();
        void remove(DLLNode<T> *);
        void remove(int);
        void add(DLLNode<T> *);
        void add(DLLNode<T> *, int);
        void extend(DoublyLinkedList<T>&);
        void reverse();

        DLLNode<T> * get(int);
        DLLNode<T> * getHead();
        int find(DLLNode<T> *);
        void set(DLLNode<T> *, int);

        void checkIndex(std::string,int);
};

#endif

