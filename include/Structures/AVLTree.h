#ifndef AVLTREE_H
#define AVLTREE_H
#include "BinTree.h"

template <class T>
struct AVLNode : BTNode<T> {
private:
    int height;
public:
    AVLNode(const T& data) : BTNode<T>(data) {
        height = 0;
    }
    bool operator==(const AVLNode& other) {
        return this->val == other->val && this->height == other->height;
    }
};
// Balanced Binary Tree class using AVL algorithms, inherited from BinTree.
template <class T>
class AVLTree : public BinTree<T> {
private:
    AVLNode<T>* root;
public:
    AVLTree() : root(nullptr) {}

    int balance(AVLNode<T>* nd);

    static int nodeHeight(AVLNode<T>* nd);
    void remove(T);
    void insert(T);

    BTNode<T>* rotate_right(AVLNode<T>* a, AVLNode<T>* b);
    BTNode<T>* rotate_left(AVLNode<T>* a, AVLNode<T>* b);
    BTNode<T>* rotate_rightLeft(AVLNode<T>* a, AVLNode<T>* b);
    BTNode<T>* rotate_leftRight(AVLNode<T>* a, AVLNode<T>* b);
};

#endif