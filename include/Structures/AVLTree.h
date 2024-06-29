#include "BinTree.h"

// Balanced Binary Tree class using AVL algorithms, inherited from BinTree. 
template <class T>
class AVLTree : public BinTree<T> {
    
    int balance(BTNode<T>*nd);
    int nodeHeight(BTNode<T>*nd);
    void remove(T);
    void insert(T);

    BTNode<T>* rotate_right(BTNode<T>*a,BTNode<T>*b);
    BTNode<T>* rotate_left(BTNode<T>*a,BTNode<T>*b);
};