#include "../../include/Structures/BinTree.h"
#include "../../include/Structures/Data.h"

namespace BT {
void testBT() {
    BinTree<Data> bt;
    for (int i = 1; i < 15; i++) {
        Data d = Data(rand() % (i + 5), i, "D");
        bt.insert(d);
        Data e = Data(rand() % (i), i, "E");
        bt.insert(e);
        // bt.display("", bt.getRoot(), false);
        if (rand() % 10 <= 4) {
            bt.remove(d);
        }
        if (rand() % 10 <= 4) {
            bt.remove(e);
        }
    }
    BinTree<int> bt2;
    for (int i = 1; i < 20; i++) {
        bt2.insert(i);
        bt2.insert(i - 5);
    }
    std::cout << bt2.size() << "\n";
    std::cout << bt2.maxDepth() << "\n";
    std::cout << bt2.postOrder() << "\n";

    BinTree<int> bt3;
    bt3.insert(5);
    bt3.insert(4);
    bt3.insert(8);
    bt3.insert(13);
    bt3.insert(11);
    bt3.insert(7);
    bt3.insert(3);
    bt3.insert(1);
    bt3.display("", bt3.getRoot(), false);
    bt3.mirror(bt3.getRoot());
    bt3.display("", bt3.getRoot(), false);

    BinTree<int> bt4;
    bt4.insert(5);
    bt4.insert(5);
    bt4.display("", bt4.getRoot(), false);
}
}  // namespace BT