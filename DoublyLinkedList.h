#ifndef DOUBLYLINKEDLIST_H
#define LINKEDLIST_H

template <class T>
struct Node {
    T data;
    Node * prev;
    Node * next;
    Node(const T& data): data(data), prev(nullptr),next(nullptr);

};

template<class T>
class DoublyLinkedList {
    private:
        Node<T>* head;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
};

#endif

