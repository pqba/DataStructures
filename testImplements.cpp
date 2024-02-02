#include "Data.h"
#include <iostream>
#include "LinkedList.h"
#include "Stack.h"

int main()
{
    int N = 10;
    LinkedList l;
    Data *list = new Data[N];
    Node * nodes = new Node[N];

    //Basic testing script for Stack, to be more rigorous in future.
    for (int i = 0; i < N; i++)
    {

        static char n[] = {'x'};
        Data v(i, 1.3 * i, n);
        list[i] = v;
        nodes[i].info = v;
    }
    for(int i = 0; i < N;i++){
        
    }
    return 0;
}
