#include "Data.h"
#include <iostream>
#include "Queue.h"
#include "LinkedList.h"
#include <random>

// Compilation:  g++ -std=c++11 -o tImpl testImplements.cpp Data.cpp LinkedList.cpp

int main()
{
    // Generate items
    int amt_items = 1e4;
    LinkedList list;
    for (int i = 0; i < amt_items; i++)
    {
        Data d(i, i * 1, "G" + std::to_string(i));
        Node * nd = new Node(d);
        list.add(nd);
    }

    // Random number gen.
    std::random_device dev;
    std::mt19937 rng(dev());

    std::uniform_int_distribution<std::mt19937::result_type> distItem(1, amt_items - 1);
    std::uniform_int_distribution<std::mt19937::result_type> distAmount(1, amt_items / (amt_items/10));
    int testTimes = distAmount(rng);

    for (int i = 0; i < testTimes; i++)
    {
        int num = distItem(rng);
        std::cout << "#" << num << ": " << list.get(num)->info.print() << std::endl;
        Node *setterNode = new Node(Data(num, num * 1, "S" + std::to_string(i)));
        list.set(setterNode, num);
        int where = list.find(setterNode);
        std::cout << "#" << where << ": " << list.get(where)->info.print() << std::endl;
    }
    std::cout << "size: " << list.size() << std::endl;
    std::cout << "empty? " << list.isEmpty() << std::endl;
    return 0;
} // implicit deletion of nodes from list using ~LL()
