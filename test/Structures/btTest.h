#pragma once
#include "../../include/Structures/BinTree.h"
#include "../../include/Structures/Data.h"

namespace BTTest {
void test() {
    // test BTNode
    BTNode<int> foo = BTNode<int>(1);
    BTNode<int> bar = BTNode<int>(1);
    assert(foo == bar);
    assert(foo.print() == "BTNode(1)");
    Data someData(3,1.5,"ABCD");
    BTNode<Data> buzz = BTNode<Data>(someData);
    assert(buzz.print() == "BTNode(" + someData.print() + ")");

    BinTree<int> oak;
    assert(oak.size() == 0);
    constexpr int growth = 50;
    for(int i = 1; i < growth; i++) {
        oak.insert(i);
    }
    assert(oak.size() == growth-1);
    assert(oak.getRoot()->val == 1);
}
}  // namespace BT