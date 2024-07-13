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
    Stack(int = 1);
    Stack(Data *a, int s);
    ~Stack();

    int size();

    bool isEmpty();
    bool isFull();

    void stack_push(Data d);
    Data stack_pop();
    Data stack_peek();
    std::string stack_output();
    std::string stack_name_output();
};
#endif
