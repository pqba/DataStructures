#include <iostream>
#include "Stack.h"
#include "Data.h"

int main()
{
    int N = 5;
    Stack myStack(N);
    Data *list = new Data[N];

    //Basic testing script for Stack, to be more rigorous in future.
    for (int i = 0; i < N; i++)
    {

        static char n[] = {'x'};
        Data v(i, 1.5, n);
        list[i] = v;
    }

    for (int k = 0; k < N; k++)
    {
        *(list+k)->print();
        myStack.stack_push(*(list + k));

    }
    std::cout << "done fill." << std::endl;

    while (!myStack.isEmpty())
    {
        myStack.stack_print();
        myStack.stack_pop();
    }
    myStack.stack_print();
    myStack.stack_push(list[4]);
    myStack.stack_print();

    std::cout << "End program." << std::endl;

    delete[] list;
    return 0;
}
