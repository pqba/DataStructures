#include "../../include/Common/Lexicon.h"

namespace LexTest {
    void test() {
    Lexicon l = Lexicon("abc abc abc\ndef def\ndef def\nghi");
    DoublyLinkedList<Word>* X = l.topWords(3);
    for (int i = 0; i < X->size(); i++) {
        std::cout << X->get(i)->data.print() << " ";
    }
    std::cout << "\n";
    delete X;
    
    }
}