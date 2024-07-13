#include "../../include/Structures/Stack.h"

#include <sstream>
#include <stdexcept>
#include <string>

#include "../../include/Structures/Data.h"

/*
References : https://www.cse.unr.edu/~sushil/class/cs202/notes/stacks/stacks.html
*/

// Stack implementation on data class
Stack::Stack(int size) {
    size = boundCapacity(size);
    initialize(size);
}
Stack::Stack(Data *a, int elements) {
    elements = boundCapacity(elements);
    initialize(elements + 1);
    for (int t = 0; t < elements; t++) {
        stack_push(*(a + t));
    }
    capacity = elements + 1;
    head = elements;
}
Stack::~Stack() {
    delete[] array;
}

// Limit size of stack between 1 and absolute_max
int Stack::boundCapacity(int c) {
    if (c < 1) {
        c = 1;
    } else if (c > absolute_max) {
        c = absolute_max;
    }
    return c;
}

int Stack::size() {
    return head;
}

bool Stack::isEmpty() {
    return head < 0;
}
bool Stack::isFull() {
    return head >= capacity;
}

// Pushes onto stack, capacity is at maximum.
void Stack::stack_push(Data d) {
    if (head == capacity - 1) {
        // check for capacity and absolute max.
        if (capacity < absolute_max) {
            int newcapac = std::min(absolute_max, capacity * 2);
            Data *newArray = new Data[newcapac];

            for (int i = 0; i < capacity; i++) {
                newArray[i] = array[i];
            }

            delete[] array;

            array = newArray;
            capacity = newcapac;
        } else {
            throw std::invalid_argument("Tried to expand max capacity stack.");
        }
        head++;
        array[head] = d;
    } else {
        head++;
        *(array + head) = d;
    }
}
// Returns popped value, error if stack empty.
Data Stack::stack_pop() {
    if (head < 0) {
        throw std::invalid_argument("Tried to pop empty stack.");
    } else {
        Data val = *(array + head);
        head--;
        return val;
    }
}

Data Stack::stack_peek() {
    if (head < 0) {
        throw std::invalid_argument("Nothing to be peeked at, empty.");
    } else {
        return *(array + head);
    }
}

// Print out each data member of stack
std::string Stack::stack_output() {
    std::ostringstream os;
    for (int i = 0; i < head; i++) {
        std::string value = (*(array + i)).print();
        os << value << "->";
    }
    if (head >= 0) {
        std::string headValue = (*(array + head)).print();
        os << headValue;
    }
    std::string s = os.str();
    return s;
}
// print out only the name of each member in stack
std::string Stack::stack_name_output() {
    std::ostringstream os;
    for (int i = 0; i < head; i++) {
        std::string value = (*(array + i)).getName();
        os << value << "-> ";
    }
    if (head >= 0) {
        std::string headValue = (*(array + head)).getName();
        os << headValue;
    }
    std::string s = os.str();
    return s;
}
// head is index of top value, array is working stack, capacity is limit of stack, absolute_max = final limit
// create stack, size > 0
void Stack::initialize(int s) {
    array = new Data[s];
    head = -1;
    capacity = s;
}
