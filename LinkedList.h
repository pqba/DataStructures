#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Data.h"

struct Node
{
    Data info;
    struct Node *link;
    // Returns if internals of Data are the exact same.
    bool sameAs(Node *comp) {
        internal other = comp->info.getData();
        internal ours = info.getData();
        return ours.constant == other.constant && ours.ID_NUMBER == other.ID_NUMBER && ours.name == other.name;
    }
    ~Node() {
    }
    Node(Data d) {
        info = d;
        link = nullptr;
    }
};

class LinkedList {
    private:
        Node *head;
        void setHead(Node * Nd){
            Nd->link = head->link;
            head = Nd;
        }
    public:
        LinkedList();
        ~LinkedList();

        int size();
        void clear();
        bool isEmpty();

        void remove(Node *);
        void remove(int);
        void add(Node *);
        void add(Node *, int);

        Node * get(int);
        int find(Node *);
        void set(Node *, int);

        void checkIndex(std::string,int);

        std::string print();
};

#endif