#ifndef LEXICON_H
#define LEXICON_H
#define TOP_W_COUNT 16
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
    bool operator==(const Word& other) {
        return other.getFreq() == freq && other.getMsg() == message;
    }
    bool operator>(const Word& other) {
        if (freq > other.getFreq()) {
            return true;
        } else if (message > other.getMsg()) {
            return true;
        }
        return false;
    }
    bool operator<(const Word& other) {
        if (freq < other.getFreq()) {
            return true;
        } else if (message < other.getMsg()) {
            return true;
        }
        return false;
    }
    const std::string print() const {
        return message + "-" + std::to_string(freq);
    }
};
// Summarizes inputted text, sorts by frequency to output important words
class Lexicon {
   private:
    BinTree<Word> textTree;

   public:
    void loadWords(const std::string& text);

    // Word is invalid if message is an empty string
    bool invalidWord(const Word& w) {
        return w.getMsg() == "";
    }

    BTNode<Word>* find(const std::string& w);

    void removeWord(const std::string& w);
    int getFrequency(const std::string& w);

    DoublyLinkedList<Word> topWords(int n);

    // Vocabulary (tree size) of Lexicon
    const int vocabulary() {
        return textTree.size();
    }
    Lexicon() {
        textTree = BinTree<Word>();
    }
    Lexicon(const std::string& text) {
        textTree = BinTree<Word>();
        loadWords(text);
    }
    ~Lexicon() {
        textTree.clear();
    }
};

#endif