#include "../../include/Common/Lexicon.h"
#include <fstream>

namespace LexTest {
void test() {
    Lexicon l = Lexicon("abc abc abc\ndef def\ndef def\nghi");
    DoublyLinkedList<Word>* X = l.topWords(3);
    for (int i = 0; i < X->size(); i++) {
        std::cout << X->get(i)->data.print() << " ";
    }
    std::cout << "\n";
    delete X;
    Lexicon levvy = Lexicon("kitten\nkitte\nsitting\nxxxxxux\nfoo\nbar\nfoo\nbuzz\ndarting");
    std::pair<std::string, std::string> mostSim = levvy.mostSimilarPair();
    std::cout << mostSim.first << " " << mostSim.second << "\n";

    // runs in build/bin/ directory, so '..' for local paths. May only work on UNIX systems
    const std::ifstream lorem_file("../../test/Common/loremipsum.txt");
    if(!lorem_file.fail()) {
        Lexicon dummytext = Lexicon(lorem_file);
        std::cout << dummytext.getStream().size() << "\n";
        auto t = dummytext.mostSimilarPair();
        std::cout << t.first << " " << t.second << "\n";
        dummytext.make_predictor(9);
        auto v = dummytext.generate_text(20);
        for(auto& x : v) {
            std::cout << x << " ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "lorem not opening." << "\n";
    }
   
}
}  // namespace LexTest