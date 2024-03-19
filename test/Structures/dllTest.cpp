#include "../../include/Structures/Data.h"
#include "../../include/Structures/DoublyLinkedList.h"
#include <iostream>
#include <random>

namespace TestDLL
{
    void testDLL()
    {
        int amt_items = 15;
        DoublyLinkedList<int> list;
        for (int a = 0; a < amt_items; a++)
        {
            Node<int> *nd = new Node<int>(a * 5);
            list.add(nd);
        }
        int len = list.size();
        for (int r = (amt_items - 1) / 2; r >= 0; r--)
        {
            Node<int> *notinlist = new Node<int>(r * 15);
            list.remove(r);
            list.set(notinlist, r);
        }
        printf("size():%d\n Original:%d\n", len, amt_items);
    }
}