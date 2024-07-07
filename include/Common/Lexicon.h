#ifndef LEXICON_H
#define LEXICON_H
#include <string>
#include "../Structures/BinTree.h"

// Word with frequency and message for Lexicon
struct Word {
    std::string message;
    int freq;

    Word(std::string msg, int f){
        message = msg;
        freq = f;
    }
    const std::string& getMsg() const{
        return message;
    }
    const int getFreq() const{
        return freq;
    }
    void setFreq(int f){
        freq = f;
    }
    void setMsg(std::string msg){
        message = msg;
    }
    bool operator==(const Word& other){
        return other.getFreq() == freq && other.getMsg() == message;
    }
    bool operator>(const Word& other){
        return other.getFreq() > freq;
    }
    bool operator<(const Word& other){
        return other.getFreq() < freq;
    }
    const std::string& print() const {
        return message + "-" + std::to_string(freq);
    }
};
// Summarizes inputted text, sorts by frequency to output important words
class Lexicon {
    void loadWords(const std::string& text);
    
    void addWord(const std::string& w);
    void removeWord(const std::string& w);
    int getFrequency(std::string& w) const;

    std::string topWords(int n);
    const int vocabulary(){
        return textTree.size();
    }
    Lexicon(){
        textTree = BinTree<Word>();
    }
    Lexicon(const std::string& text){
        textTree = BinTree<Word>();
        loadWords(text);
    }
    ~Lexicon(){
        textTree.clear();
    }
    private:
        BinTree<Word> textTree;
        
};

#endif