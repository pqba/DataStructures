#include "../../include/Structures/BinTree.h"

// Construct binary tree
template <class T>
BinTree<T>::BinTree(){
    root = nullptr;
}

// Destructor for binary tree
template <class T>
BinTree<T>::~BinTree(){
    clear();
}

// Clears the entire tree's allocated memory
template <class T>
void BinTree<T>::clear(){
    destroyRecursive(root);
}

// Destroys node object and its children recursively 
template <class T>
void BinTree<T>::destroyRecursive(BTNode<T> nd) {
    if(nd) {
        destroyRecursive(nd->left);
        destroyRecursive(nd->right);
        delete nd;
    }
}
// Returns true if key exists as a value of root or is in the subtree of root. Calling exists(T) uses entire tree.
template <class T>
bool BinTree<T>::exists(BTNode<T> nd = root,T key) {
    if(nd == nullptr){
        return false;
    }
    else if(nd->val == key){
        return true;
    }
    else if(nd->val < key){
        return exists(root->right,key);
    }
    else { 
        return exists(nd->left,key);
    }
}
// Inserts node into of tree while maintaining property.
template <class T>
void BinTree<T>::insert(T){

}
// Removes node from key, does nothing if node doesn't exist in tree.
template <class T>
void BinTree<T>::remove(BTNode<T> nd){
    if(nd == nullptr || !exists(root,nd->val)) {
        return;
    }
    
}