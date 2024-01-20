#ifndef STACK_H
#define STACK_H
#include "Data.h"

class Stack {
    private:
        int absolute_max = 1000;
        int capacity;
        int head;
        Data *array;
        void initialize(int s);
        int boundCapacity(int c);

    public:
        Stack(int s);
        Stack(Data *a, int s);
        ~Stack();

        int size();

        bool isEmpty();
        bool isFull();

        void stack_push(Data d);
        Data stack_pop();
        Data stack_peek();
        void stack_print();
};
#endif
