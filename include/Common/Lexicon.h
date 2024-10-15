#ifndef LEXICON_H
#define LEXICON_H
#define MAX_IGNORE 10
#include <string>
#include <utility>

#include "../Structures/BinTree.h"

// Word with frequency and message for Lexicon
struct Word {
    std::string message;
    int freq;
    Word() {
        message = "";
        freq = 0;
    }
    Word(std::string msg, int f) {
        message = std::move(msg);
        freq = f;
    }
    const std::string& getMsg() const {
        return message;
    }
    int getFreq() const {
        return freq;
    }
    void setFreq(int f) {
        freq = f;
    }
    void setMsg(std::string msg) {
        message = std::move(msg);
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

    std::string print() const {
        return message + "-" + std::to_string(freq);
    }
};

// General Utils for Lexicon
int levenshteinDistance(const std::string& first, const std::string& second);
Word* dllToArray(DoublyLinkedList<Word> list);
std::deque<std::string> expand(const std::string& s, char delim);
std::string join(const std::deque<std::string>& vec, const char delim);
std::string weightedChoice(const std::unordered_map<std::string, float>& probs);

typedef std::unordered_map<std::string, std::unordered_map<std::string, float> > chain_t;
typedef struct markov_t {
    chain_t chain;
    int order{};
} markov_t;

// Summarizes inputted text, sorts by frequency to output important words
class Lexicon {
   private:
    BinTree<Word> textTree;
    std::string ignoredWords[MAX_IGNORE];
    markov_t predictor;
    int ignoreLen;
    int MAX_WC = 5000;
    std::vector<std::string> originalStream;

   public:
    void loadFile(const std::ifstream& file);
    void loadIgnore(int size, std::string A[]);
    void loadWords(const std::string& text);

    const BinTree<Word>& getTree();
    const std::vector<std::string> & getStream();

    // Word is invalid if message is an empty string
    static bool invalidWord(const Word& w) {
        return
        w.getMsg().empty();
    }

    BTNode<Word>* find(const std::string& w);

    void removeWord(const std::string& w);
    int getFrequency(const std::string& w);

    DoublyLinkedList<Word>* topWords(int n);
    void outputTopWords(int n, std::string);

    // Vocabulary (tree size) of Lexicon
    int vocabulary() {
        return textTree.size();
    }
    std::string longestWord();
    std::string shortestWord();
    std::pair<std::string, std::string> mostSimilarPair();

    void make_predictor(int o);

    std::vector<std::string> generate_text(int l);

    Lexicon() {
        textTree = BinTree<Word>();
        ignoreLen = 0;
        predictor = markov_t();
    }
    Lexicon(const std::ifstream& file) {
        textTree = BinTree<Word>();
        ignoreLen = 0;  
        loadFile(file);
        predictor = markov_t();
    }
    Lexicon(const std::string& text) {
        textTree = BinTree<Word>();
        ignoreLen = 0;
        loadWords(text);
        predictor = markov_t();
    }
    Lexicon(const std::string& text, int sz, std::string ign[]) {
        textTree = BinTree<Word>();
        loadIgnore(sz, ign);
        loadWords(text);
        predictor = markov_t();
    }
    ~Lexicon() {}
};

#endif