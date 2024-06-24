#include "../../include/Structures/BinTree.h"
#include "../../include/Structures/Data.h"

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
    destroyRecur(root);
}

// Destroys node object and its children recursively 
template <class T>
void BinTree<T>::destroyRecur(BTNode<T>* nd) {
    if(nd) {
        destroyRecur(nd->left);
        destroyRecur(nd->right);
        delete nd;
    }
}
// Returns true if key exists as a value of node or is in the subtree of node with recursion
template <class T>
bool BinTree<T>::existsRecur(BTNode<T>* nd,T key) {
    if(nd == nullptr){
        return false;
    }
    else if(nd->val == key){
        return true;
    }
    else if(nd->val < key){
        return existsRecur(root->right,key);
    }
    else { 
        return existsRecur(nd->left,key);
    }
}
// Returns true if key exists as a value of node or is in the subtree of node with iteration
template <class T>
bool BinTree<T>::existsIter(BTNode<T>* nd,T key){
    while(nd != nullptr) {
        if(nd->val == key){
            return true;
        }
        else if(nd->val < key){
            nd = nd->right;
        }
        else {
            nd = nd->left;
        }
    }
    return false;
}
// Inserts value into Binary Tree
template <class T>
void BinTree<T>::insert(T value){
    root = insertSubtree(root,value);
}

// Inserts node into subtree of parent, while maintaining property.
template <class T>
BTNode<T>* BinTree<T>::insertSubtree(BTNode<T>* parent,T value) {
    if(!parent){
        return new BTNode<T>(value);
    }
    else if(value < parent->val){
        parent->left = insertSubtree(parent->left,value);
    }
    else {
        parent->right = insertSubtree(parent->right,value);
    }
    return parent;
}
// Removes node from key, does nothing if node doesn't exist in tree.
template <class T>
void BinTree<T>::remove(BTNode<T>* nd,T val){
    if(nd == nullptr || !existsRecur(root,nd->val)) {
        return;
    }
    if(nd){

    }
    
}
// Returns in order traversal of entire tree
template <class T>
std::string BinTree<T>::inOrder(){
    return inOrderSubtree(root,"");
}

// Returns space delimited string representing the in-order traversal of binary tree's subtree
template <class T>
std::string BinTree<T>::inOrderSubtree(BTNode<T>* nd,std::string current){
    if(nd){
        current += inOrderSubtree(nd->left,"");
        current += " "+ nd->val.print() + " ";
        current += inOrderSubtree(nd->right,"");
        return current;
    }
    return "";
}
// Return number of nodes in given subtree
template <class T>
int BinTree<T>::subtreeSize(BTNode<T>* nd){
    if(!nd) {
        return 0;
    }
    return 1 + subtreeSize(nd->left) + subtreeSize(nd->right);
}
// Return number of nodes in tree
template <class T>
int BinTree<T>::size(){
    return subtreeSize(root);
}

// Explicit instantiations
template class BinTree<Data>;
