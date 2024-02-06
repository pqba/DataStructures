#include "Data.h"
#include <iostream>
#include "LinkedList.h"

// Compilation:  g++ -std=c++11 -o tImpl testImplements.cpp Data.cpp LinkedList.cpp
int main()
{
    int N = 10;
    LinkedList l;
    
    for (int i = 0; i < N; ++i) {
        std::cout << "size " << l.size() << std::endl;
        std::cout << "content: " << l.print() << std::endl;
        // Create a Data object for each node
        Data d(i, i + 0.5, "S" + std::to_string(i)); // Example data creation

        Node * currentNode = new Node (d);
        // Add the current node to the linked list
        l.add(currentNode);
    } 
    return 0;
}

