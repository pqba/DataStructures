#include "../../include/Common/Lexicon.h"
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <vector>

// Loads entire ASCII text file into tree given a valid filename, doesn't load if invalid
void Lexicon::loadFile(const std::string& fname) {
    std::ifstream textFile(fname);
    if(textFile.is_open()){
        std::stringstream buffer;
        buffer << textFile.rdbuf();
        std::string corpus = buffer.str();
        loadWords(corpus);
    }
}

// Loads strings up to size  amount into ignore array
void Lexicon::loadIgnore(int size, std::string A[]) {
    if(size <= 0) {
        ignoreLen = 0; 
    }
    else {
        int len = size > MAX_IGNORE ?  MAX_IGNORE : size;
        for(int i = 0; i < len; i++) {
            ignoredWords[i] = A[i];
        }
        ignoreLen = len;
    }
}


// Loads in space delinated newline split text to tree 
void Lexicon::loadWords(const std::string& text) {
    std::unordered_map<std::string,int> freqMap;
    std::istringstream blockStream(text);
    std::string line;

    // Other configuration options could be to change getline/lineStream to work with general chars.
    while(std::getline(blockStream,line)){
        std::istringstream lineStream(line);
        std::string sequence;
        while(lineStream >> sequence) {
            if(freqMap.find(sequence) != freqMap.end()){
                freqMap[sequence] += 1;
            }
            else {
                bool contains = false;
                for(int i = 0; i < ignoreLen; i++) {
                    if(ignoredWords[i] == sequence) {
                        contains = true;
                        break;
                    }
                }
                if(!contains) {
                    freqMap[sequence] = 1;
                }
            }
        }
    }

    for(std::pair<std::string,int> val : freqMap) {
        textTree.insert(Word(val.first,val.second));
    }
}

// Returns textTree by a constant reference
const BinTree<Word>& Lexicon::getTree(){
    return textTree;
}

// Finds word in textTree given w, invalid Word otherwise
BTNode<Word>* Lexicon::find(const std::string& w) {
    BTNode<Word>* nd = textTree.getRoot();
    while(nd != nullptr){
        if(nd->val.getMsg() == w){
            return nd;
        }
        else if(nd->val.getMsg() > w ){
            nd = nd->right;
        }
        else if(nd->val.getMsg() < w){
            nd = nd->left;
        }
        else {
            return nullptr; // Neither larger or smaller, invalid word
        }
    }
    return nullptr; 
}
// removes string from tree
void Lexicon::removeWord(const std::string& w){
    BTNode<Word> * w_search = find(w);
    if(w_search){
        textTree.remove(w_search->val);
    }
}
// returns frequency of given string
int Lexicon::getFrequency(const std::string& w) {
    BTNode<Word>* w_search = find(w);
    if(w_search) {
        return w_search->val.freq;
    }
    return 0;
}
// Returns reference to list of highest n frequency words in tree
DoublyLinkedList<Word>* Lexicon::topWords(int n) {
    if(n <= 0 || vocabulary() <= 0){
        return new DoublyLinkedList<Word>();
    }
    int tree_size = textTree.size();
    if(tree_size < n){
        n = tree_size;
    }
    DoublyLinkedList<Word>* lst = textTree.inOrderList();
    std::vector<Word> wordVec;
    int l_sz = lst->size();
    for(int ind = 0; ind < l_sz; ind++){
        wordVec.push_back(lst->pop());
    }
    std::sort(wordVec.begin(),wordVec.end());

    DoublyLinkedList<Word>* top_list = new DoublyLinkedList<Word>();
    for(int i = 0; i < n; i++){
        top_list->add(new DLLNode<Word>(wordVec.back()));
        wordVec.pop_back();
    }
    delete lst;
    return top_list;   
}

// Displays highest n frequency words in tree, seperated by a delimiter
void Lexicon::outputTopWords(int n, std::string delim){
    if(n <= 0 || vocabulary() <= 0) {
        return;
    }
    int tree_size = textTree.size();
    n = tree_size < n ?  tree_size : n;
    DoublyLinkedList<Word> * lst = textTree.inOrderList();
    
    std::vector<Word> wordVec;
    int l_sz = lst->size();
    for(int ind = 0; ind < l_sz; ind++){
        wordVec.push_back(lst->pop());
    }
    std::sort(wordVec.begin(),wordVec.end(),std::greater<Word>());

    for(int i = 0; i < n; i++){
        std::cout << wordVec.at(i).print() << delim;
    }
    std::cout << "\n";
    delete lst;
}