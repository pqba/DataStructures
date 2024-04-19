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
