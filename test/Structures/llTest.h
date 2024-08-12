#include <iostream>

#include "../../include/Structures/Data.h"
#include "../../include/Structures/LinkedList.h"

namespace LLTest {

void test() {
    LinkedList l;
    l.add(new Node(Data(1, 1.1, "A")));
    l.add(new Node(Data(2, 1.1, "B")));
    l.add(new Node(Data(3, 1.1, "C")));
    std::cout << l.print() << "\n";
    l.reverse();
    std::cout << l.print() << "\n";
}
}  // namespace TestLL
