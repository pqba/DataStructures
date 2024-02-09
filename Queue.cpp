#include "Data.h"
#include "Queue.h"
#include <stdexcept>
#include <string>

// Array based Queue Data Structure, as stated in https://www.csd.uwo.ca/courses/CS1027b/notes/CS1027-Queues-W17.pdf

Queue::Queue()
{

}
Queue::Queue(int size){

}
Queue::Queue(Data * past, int length){

}
Queue::~Queue()
{
    clear();
}

void Queue::clear()
{
}

bool Queue::isEmpty()
{
}

int Queue::size()
{
}

void Queue::enqueue(Data d)
{
}

Data Queue::dequeue()
{
}

std::string Queue::print()
{
}

void Queue::checkIndex(std::string msg, int possibleInd)
{
    if (possibleInd < 0 || possibleInd >= size())
    {
        throw std::invalid_argument(msg);
    }
}
int Queue::boundCapacity(int c){
    if(c < 1){
        c = 1;
    }
    else if(c > absolute_max){
        c = absolute_max;
    }
    return c;
}