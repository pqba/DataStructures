#include "../../include/Structures/AVLTree.h"

template <class T>
int AVLTree<T>::nodeHeight(BTNode<T>*node){
    if(node == nullptr) return 0;
    return 1 + max(height(node->left),height(node->right));
}

template <class T>
int AVLTree<T>::balance(BTNode<T>*node) {
    if(node == nullptr) return 0;
    return nodeHeight(node->left) - nodeHeight(node->right);
}