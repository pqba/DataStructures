#include "../../include/Structures/BinTree.h"
#include "../../include/Structures/Data.h"

namespace BT {
    void testBT(){
            BinTree<Data> bt;
    for(int i = 1; i < 15; i++){
        Data d = Data(rand() % (i+5),i,"D");
        bt.insert(d);
        Data e = Data(rand() % (i),i,"E");
        bt.insert(e);
        bt.display("",bt.getRoot(),false);
        if(rand() % 10 <= 4){
            bt.remove(d);
        }
        if(rand() % 10 <= 4){
            bt.remove(e);
        }
    }
    }
}