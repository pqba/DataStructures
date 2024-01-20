#include <iostream>
#include "Stack.h"
#include "Data.h"
#include <stdexcept>
#include <sstream>
#include <string>

/*
ADT
A stack, S of type T is a sequence of items of type T on which the following operations are defined:
LIFO: Last put into the stack is the first to be popped off

Initialize the stack S to be the empty stack
Determine whether or not the stack S is empty()
Determine whether or not the stack S is full()
push() a new item of type T onto the top of the stack, S
If S in not empty, pop() an item from the top of the stack, S.

References : https://www.cse.unr.edu/~sushil/class/cs202/notes/stacks/stacks.html
*/

// Stack implementation on data class 
Stack::Stack(int size = 1)
{
    size = boundCapacity(size);
    initialize(size);
}
Stack::Stack(Data *a, int elements)
{
    elements = boundCapacity(elements);
    initialize(elements + 1);
    for (int t = 0; t < elements; t++)
    {
        stack_push(*(a + t));
    }
    capacity = elements + 1;
    head = elements;
}
Stack::~Stack()
{
    delete[] array;
}

// Limit size of stack between 1 and absolute_max
int Stack::boundCapacity(int c)
{
    if (c < 1)
    {
        c = 1;
    }
    else if (c > absolute_max)
    {
        c = absolute_max;
    }
    return c;
}

int Stack::size(){
    return head;
}

bool Stack::isEmpty()
{
    return head  < 0;
}
bool Stack::isFull()
{
    return head == capacity;
}

// Pushes onto stack, capacity is at maximum.
void Stack::stack_push(Data d)
{
    if (head == capacity)
    {
        // check against absolute max
        if (capacity < absolute_max)
        {
            capacity++;
            head++;
            *(array + head) = d;
        }
        else
        {
            std::cout << "Err, capacity limit reached" << std::endl;
            throw std::invalid_argument("Tried to expand max capacity stack.");
        }
    }
    else
    {
        head++;
        *(array + head) = d;
    }
}
//Returns popped value, error if stack empty.
Data Stack::stack_pop()
{
    if (head < 0)
    {
        std::cout << "Nothing to be popped. " << std::endl;
        throw std::invalid_argument("Tried to pop empty stack.");
    }
    else
    {
        Data val = *(array + head);
        head--;
        return val;
    }
}
Data Stack::stack_peek(){
    if(head < 0){
        throw std::invalid_argument("Nothing to be peeked at, empty.");
    }
    else {
        return *(array + head);
    }
}

void Stack::stack_print()
{
    std::ostringstream os;
    for (int i = 0; i < head; i++)
    {
        os << *(array + i)->print() << "->";
        std::cout << *(array+i)->print() << std::endl;
    }
    if(head >= 0){
        os << *(array+head)->print();
    }
    std::string s = os.str();
    std::cout << s << std::endl;
}

// head is index of top value, array is working stack, capacity is limit of stack, absolute_max = final limit
// create stack, size > 0
void Stack::initialize(int s)
{
    array = new Data[s];
    head = -1;
    capacity = s;
}
