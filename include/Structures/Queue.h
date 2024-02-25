#ifndef QUEUE_H
#define QUEUE_H
#include "Data.h"


class Queue {
    private:
        Data * array;
        int head;
        int count;
        int absolute_max = 1000;
    public:
        Queue();
        Queue(int);
        Queue(Data *, int);
        ~Queue();
        
        void clear();
        bool isEmpty();
        int size();

        void enqueue(Data);
        Data dequeue();

        std::string print();
        void checkIndex(std::string,int);
        int boundCapacity(int);

};
#endif