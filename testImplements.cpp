#include "Data.h"
#include <iostream>
#include "LinkedList.h"

// Compilation:  g++ -std=c++11 -o tImpl testImplements.cpp Data.cpp LinkedList.cpp
int main()
{
    int N = 40;
    LinkedList l;
    
    for (int i = 0; i < N; ++i) {
        // Create a Data object for each node
        Data d(i, i + 0.5, "S" + std::to_string(i)); // Example data creation

        Node * currentNode = new Node (d);
        // Add the current node to the linked list
        l.add(currentNode);
    } 
    for(int i = 0; i < N; i++){
        Node * first = l.get(0);
        l.remove(first);
        Data v(i*3,i,"Q");
        Node * nd = new Node(v);
        l.remove(nd); 
        delete nd;
    }
    std::cout << l.size() << "\n"  << l.print() << std::endl;
    return 0;
}

