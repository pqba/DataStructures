#include "../../include/Structures/Data.h"
#include "../../include/Structures/Queue.h"
#include "../../include/Common/MusicPlayer.h"
#include "../../include/Common/Event.h"
#include <stdexcept>
#include <string>
#define INIT_SIZE 10

// Array based Queue Data Structure, referenced from https://www.csd.uwo.ca/courses/CS1027b/notes/CS1027-Queues-W17.pdf

template<class T>
// Creates Queue of initial size
Queue<T>::Queue()
{
    front = -1;
    array = new T[INIT_SIZE];
    count = INIT_SIZE;
}
template<class T>
// Intializes Queue with size length.
Queue<T>::Queue(int size){
    front = -1;
    int bounded = boundCapacity(size);
    array = new T[bounded];
    count = bounded;
}
template<class T>
// Initializes Queue from array of T objects with size length
Queue<T>::Queue(T * past, int length){
    if(length > absolute_max || length < 1) {
        throw std::invalid_argument("Invalid queue length.");
    }
    count = length; front = length-1;
    array = new T[length];
    for(int i = 0; i < length;i++){
        array[i] = past[i];
    }
}
template<class T>
// Destructs Queue
Queue<T>::~Queue()
{
    clear();
}

// Clears Queue memory
template<class T>
void Queue<T>::clear()
{
    front = -1;
    delete[] array;
    array = nullptr; // Set to nullptr after deletion.
    count = 0;
}
// Returns if the queue is empty
template<class T>
bool Queue<T>::isEmpty()
{
    return front < 0;
}
// Returns size of Queue
template<class T>
int Queue<T>::size()
{
    return front+1;
}
// Adds an element to the rear of the queue
template<class T>
void Queue<T>::enqueue(T d)
{
    expand();
    front++;
    array[front] = d;
}

// Removes an element from the front of the queue
template<class T>
T Queue<T>::dequeue()
{
    if(front < 0) {
        throw std::invalid_argument("Queue is empty, can't dequeue.");
    }
    else {
        T result = array[0];
        T * new_queue = new T[count];
        // Perform shift down
        for(int i=0; i < front;i++){
            new_queue[i] = array[i+1];
        }
        delete[] array;
        front--;
        array = new_queue;
        return result;
    }
}
template <class T>
T Queue<T>::peek(){
    if(front < 0){
        throw std::invalid_argument("Queue is empty, can't peek.");
    }
    else {
        return array[0];
    }
}

// Expands underlying array based on current count size. 
template<class T>
void Queue<T>::expand(){
    if(front == count-1) {
        if(count < absolute_max) {
            int new_capac = std::min(absolute_max,static_cast<int>(count * 1.5));
            T* new_queue = new T[new_capac];
            for(int i = 0; i <= front; i++) {
                new_queue[i] = array[i];
            }
            delete[] array;
            array = new_queue;
            count = new_capac;
        } else {
            throw std::invalid_argument("Tried to expand max capacity queue.");
        }
    }
}
// Outputs Queue
template<class T>
const std::string& Queue<T>::print()  {
    static std::string s;
    s.clear();
    for(int i = 0; i <= front;i++){
      s += array[i].print() + "  ";
    }
    return s;
}

template<class T>
void Queue<T>::checkIndex(std::string msg, int possibleInd)
{
    if (possibleInd < 0 || possibleInd >= size())
    {
        throw std::invalid_argument(msg);
    }
}
template<class T>
int Queue<T>::boundCapacity(int c){
    if(c < 1){
        c = 1;
    }
    else if(c > absolute_max){
        c = absolute_max;
    }
    return c;
}

// Explicit instantiations:
template class Queue<Data>;
template class Queue<Event>;