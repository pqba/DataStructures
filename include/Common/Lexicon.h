#ifndef LEXICON_H
#define LEXICON_H
#define MAX_IGNORE 10
#include <string>

#include "../Structures/BinTree.h"


// Word with frequency and message for Lexicon
struct Word {
    std::string message;
    int freq;
    Word(){
        message = "";
        freq = 0;
    }
    Word(std::string msg, int f) {
        message = msg;
        freq = f;
    }
    const std::string& getMsg() const {
        return message;
    }
    const int getFreq() const {
        return freq;
    }
    void setFreq(int f) {
        freq = f;
    }
    void setMsg(std::string msg) {
        message = msg;
    }
    bool operator==(const Word& other) const {
        return other.getFreq() == freq && other.getMsg() == message;
    }
    bool operator>(const Word& other) const {
        return freq > other.freq || (freq == other.freq && message > other.message);
    }

    bool operator<(const Word& other) const {
        return freq < other.freq || (freq == other.freq && message < other.message);
    }

    const std::string print() const {
        return message + "-" + std::to_string(freq);
    }
};

// General Utils for Lexicon
int levenshteinDistance(std::string first, std::string second);
Word * dllToArray(DoublyLinkedList<Word> list);

// Summarizes inputted text, sorts by frequency to output important words
class Lexicon {
   private:
    BinTree<Word> textTree;
    std::string ignoredWords[MAX_IGNORE];
    int ignoreLen;

   public:
    void loadFile(const std::string& fname);
    void loadIgnore(int size, std::string A[]);
    void loadWords(const std::string& text);

    const BinTree<Word>& getTree();

    // Word is invalid if message is an empty string
    bool invalidWord(const Word& w) {
        return w.getMsg() == "";
    }

    BTNode<Word>* find(const std::string& w);

    void removeWord(const std::string& w);
    int getFrequency(const std::string& w);

    DoublyLinkedList<Word>* topWords(int n);
    void outputTopWords(int n, std::string);

    // Vocabulary (tree size) of Lexicon
    const int vocabulary() {
        return textTree.size();
    }
    std::string longestWord();
    std::string shortestWord();
    std::pair<std::string,std::string> mostSimilarPair();

    Lexicon() {
        textTree = BinTree<Word>();
        ignoreLen = 0;
    }
    Lexicon(const std::string& text) {
        textTree = BinTree<Word>();
        ignoreLen = 0;
        loadWords(text);
    }
    Lexicon(const std::string& text, int sz, std::string ign[]){
        textTree = BinTree<Word>();
        loadIgnore(sz,ign);
        loadWords(text);
    }
    ~Lexicon() {}
};

#endif