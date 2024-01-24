#ifndef QUEUE_H
#define QUEUE_H
#include "Data.h"


class Queue {
    private:
        Data * array;
        int head;
        int absolute_max = 1000;
    public:
        Queue();
        ~Queue();
        void clear();
        void enqueue(Data);
        Data dequeue();
};
#endif