#include <iostream>

#include "../../include/Structures/Data.h"
#include "../../include/Structures/LinkedList.h"
#include <cassert>

namespace LLTest {

void test() {
    LinkedList l = LinkedList();
    // Test Node 
    Data someData = Data(5.0,3.9,"hello");
    Node sampleNode = Node(someData);
    Node theSame = Node(someData);
    assert(sampleNode.info == someData);
    assert(sampleNode.sameAs(&theSame));
    // Test LL
    assert(l.size() == 0);
    assert(l.isEmpty());
    assert(l.print() == "empty.");
    constexpr int TIMES = 300;
    for(int i = 0; i < TIMES; i++) {
        l.add(new Node(Data(i,1.0,"")));
    }
    assert(l.size() == TIMES);
    for(int i = 0; i < TIMES-1;i++) {
        l.remove(0);
    }
    assert(l.size() == 1);
    Node * alterHead = new Node(someData);
    l.set(alterHead,0);
    assert(l.get(0) == alterHead);
    assert(l.print() == someData.print() + "=>" + "null");
    // Node * t = new Node(Data(-5,1.0,""));

}
}  // namespace TestLL
