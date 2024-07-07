#include "../../include/Structures/AVLTree.h"

/*
AVL Tree References:
https://en.wikipedia.org/wiki/AVL_tree
*/

// Returns height of node
template <class T>
int AVLTree<T>::nodeHeight(BTNode<T>*node){
    if(node == nullptr) return 0;
    return node->height;
}

// Gets balance factor of node: h(right)-h(left)
template <class T>
int AVLTree<T>::balance(BTNode<T>*node) {
    if(node == nullptr) return 0;
    //  < 0 is left heavy, > 0 is right heavy
    return nodeHeight(node->right) - nodeHeight(node->left);
}

// Inserts T, maintaining AVL Tree properties
template <class T>
void AVLTree<T>::insert(T value){
    BTNode<T>* node = BinTree<T>::insertSubtree(BinTree<T>::getRoot(),value);
    node->height = 1 + max(nodeHeight(node->left),nodeHeight(node->right));
    int bal = balance(node);

}


template <class T>
BTNode<T>* AVLTree<T>::rotate_right(BTNode<T>*X,BTNode<T>*Z){

}

template <class T>
BTNode<T>* AVLTree<T>::rotate_left(BTNode<T>*X,BTNode<T>*Z){

}