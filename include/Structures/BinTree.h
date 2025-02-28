#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include <type_traits>

#include "DoublyLinkedList.h"

// Node structure for Binary Search Tree. Must implement == on template class data as well as a < or > and a print() function if non-integral type
template <class T>
struct BTNode {
    BTNode<T>* left;
    BTNode<T>* right;
    T val;
    int height;
    BTNode(T data) {
        left = nullptr;
        right = nullptr;
        val = data;
    }
    bool operator==(const BTNode& other) {
        return this->val == other.val;
    }
    // Printing for nodes, infers types
    std::string print() const {
        return "BTNode(" + print_impl(val) + ")";
    }

   private:
    // Using SFINAE for std::string, fundamental, and clases: https://en.wikipedia.org/wiki/Substitution_failure_is_not_an_error
    template <typename U>
    std::enable_if_t<!std::is_fundamental<U>::value, std::string>
    print_impl(const U& val) const {
        return val.print();
    }
    template <typename U>
    std::enable_if_t<std::is_fundamental<U>::value, std::string>
    print_impl(const U& val) const {
        return std::to_string(val);
    }
};

// Binary Tree Class
template <class T>
class BinTree {
   private:
    BTNode<T>* root;

   public:
    BinTree();
    ~BinTree();

    BTNode<T>* getRoot();

    void insert(T);
    BTNode<T>* insertSubtree(BTNode<T>*, T);
    void remove(T);

    void destroyRecur(BTNode<T>*);
    void clear();

    bool existsRecur(BTNode<T>*, T);
    bool existsIter(BTNode<T>*, T);
    BTNode<T>* get(BTNode<T>*, T);
    BTNode<T>* getParent(BTNode<T>*, T);

    int subtreeSize(BTNode<T>*);
    int size();
    int maxDepth();
    int maxSubtreeDepth(BTNode<T>*);

    void paths(BTNode<T>*, const std::string&);
    void mirror(BTNode<T>*);
    DoublyLinkedList<T>* inOrderList();
    DoublyLinkedList<T>* inOrderSubtreeList(BTNode<T>*);
    std::string inOrder();
    std::string inOrderSubtree(BTNode<T>*, std::string);
    std::string postOrder();
    std::string postOrderSubtree(BTNode<T>*, std::string);
    void display(const std::string& p, BTNode<T>* n, bool l) const;
};

#endif