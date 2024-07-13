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
            DLLNode<int> *nd = new DLLNode<int>(a * 5);
            list.add(nd);
        }
        int len = list.size();
        for (int r = (amt_items - 1) / 2; r >= 0; r--)
        {
            DLLNode<int> *notinlist = new DLLNode<int>(r * 15);
            list.remove(r);
            list.set(notinlist, r);
        }
        printf("size():%d\n Original:%d\n", len, amt_items);

        DoublyLinkedList<int> listA;
        for(int i = 1; i < 10; i++){
            listA.add(new DLLNode<int>(i));
        }
        printf("Last Item: %d\n",listA.pop());
        DoublyLinkedList<int> listB;
        listB.add(new DLLNode<int>(10)); listB.add(new DLLNode<int>(11));
        listA.extend(listB);
        printf("%d, %d popped.\n",listA.pop(),listA.pop());
    }
}