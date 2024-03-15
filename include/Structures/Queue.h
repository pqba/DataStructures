#ifndef QUEUE_H
#define QUEUE_H
#include "Data.h"

template<class T>
// Array based templated Queue implementation. 'T' must implement print() method.
class Queue {
    private:
        T * array; // Underlying array structure of T objects
        int front; // Current index to front of Queue, most recently inserted
        int count; // Size of array 
        int absolute_max = 1e6; // Absolute maximum number of objects in Queue
    public:
        Queue();
        Queue(int);
        Queue(T *, int);
        ~Queue();
        
        void clear();
        bool isEmpty();
        int size();

        void expand();
        void extend(Queue<T>&);

        void enqueue(T);
        T dequeue();
        T peek();

        const std::string& print();
        void checkIndex(std::string,int);
        int boundCapacity(int);

};
#endif