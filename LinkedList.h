#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Data.h";

struct Node {
    Data info;
    struct Node * link;
};

class LinkedList {
    private:
        Node * head;
    public:
        LinkedList();
        ~LinkedList();

        int length();
        void clear();

        void remove(Node *);
        void add(Node *);
};

#endif