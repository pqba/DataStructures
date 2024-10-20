#pragma once
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
    constexpr int LARGE_TIMES = 300;
    constexpr int SMALL_TIMES = 30;
    for(int i = 0; i < LARGE_TIMES; i++) {
        l.add(new Node(Data(i,1.0,"")));
    }
    assert(l.size() == LARGE_TIMES);
    for(int i = 0; i < LARGE_TIMES-1;i++) {
        l.remove(0);
    }
    assert(l.size() == 1);
    Node * alterHead = new Node(someData);
    l.set(alterHead,0);
    assert(l.get(0) == alterHead);
    assert(l.print() == someData.print() + "=>" + "null");
    assert(l.find(alterHead) == 0);
    l.remove(0);
    assert(l.find(alterHead) == -1);
    l.clear();
    LinkedList a_list = LinkedList();
    LinkedList b_list = LinkedList();
    for(int i = 0; i < SMALL_TIMES; i++) {
        a_list.add(new Node(Data(i,2.0,"")));
    }
    LinkedList c_list = LinkedList();
    c_list.add(new Node(Data(3,4.0,"foo")));
    c_list.add(new Node(Data(4,5.0,"bar")));
    c_list.add(new Node(Data(5,6.0,"buzz")));
    c_list.remove(1);
    assert(c_list.size() == 2);
    assert(c_list.get(1)->info.getName() == "buzz");
    a_list.remove(SMALL_TIMES / 2);
    for(int j = SMALL_TIMES - 1; j >= 0; j--) {
        b_list.add(new Node(Data(j,2.0,"")));
    }
    b_list.remove(SMALL_TIMES / 2 - 1);
    assert(a_list.size() == b_list.size());
    for(int k = 0; k < SMALL_TIMES - 1; k++) {
        assert(a_list.get(k)->sameAs(b_list.get(SMALL_TIMES-k-2)));
    }
    a_list.reverse();
    for(int k = 0; k < a_list.size(); k++) {
        assert(a_list.get(k)->sameAs(b_list.get(k)));
    }
    a_list.clear(); b_list.clear();
}
}  // namespace TestLL
