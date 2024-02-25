#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include <string> 


// Node class with template types. Must implement == on data for correctness.
template <class T>
struct Node {
    T data;
    Node<T> * prev;
    Node<T> * next;
    Node(const T& data): data(data), prev(nullptr),next(nullptr) {}
    bool operator==(const Node<T>& rhs) {
        return this->data == rhs.data;
    }
};

// Doubly Linked List header
template<class T>
class DoublyLinkedList {
    private:
        Node<T>* head;
        Node<T>* tail;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();

        int size();
        void clear();
        bool isEmpty();
        int find();

        void remove(Node<T> *);
        void remove(int);
        void add(Node<T> *);
        void add(Node<T> *, int);

        Node<T> * get(int);
        int find(Node<T> *);
        void set(Node<T> *, int);

        void checkIndex(std::string,int);
};

#endif

