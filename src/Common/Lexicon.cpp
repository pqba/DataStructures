#include "../../include/Common/Lexicon.h"

// Loads in space delinated newline split text to tree 
void Lexicon::loadWords(const std::string& text) {

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
// Returns list of top n words in tree
DoublyLinkedList<Word> Lexicon::topWords(int n) {
    if(n <= 0 || vocabulary() == 0) return DoublyLinkedList<Word>();
    int tree_size = textTree.size();
    if(tree_size < n){
        n = tree_size;
    }
    DoublyLinkedList<Word> lst = *textTree.inOrderList();
    lst.reverse();
    DoublyLinkedList<Word> top_list = DoublyLinkedList<Word>();
    top_list.extend(lst);
    return top_list;   
}