#include "Data.h"
#include <iostream>
#include "LinkedList.h"

// Compilation:  g++ -std=c++11 -o tImpl testImplements.cpp Data.cpp LinkedList.cpp

int main()
{
    int N = 10;
    LinkedList l;
    for (int i = 0; i < N; ++i) {
        // Create a Data object for each node
        Data d(i, i + 0.5, "S" + std::to_string(i)); // Example data creation (int, float, string)
        Node * currentNode = new Node (d);
        // Add the current node to the linked list
        l.add(currentNode);
    } 
    std::cout << l.print() << std::endl;
    for(int i = 0; i < N/2; i++){
        Data nD(i*N, i+ 1, "N" + std::to_string(i));
        Node *  betterNode = new Node(nD);
        l.set(betterNode,i);
    }

    std::cout << l.print() << std::endl;
    
    return 0;
}
