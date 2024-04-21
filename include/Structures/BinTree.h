#ifndef BINTREE_H
#define BINTREE_H
#include <string>

// Node structure for Binary Search Tree. Must implement == on template class data as well as a < or >.
template <class T>
struct BTNode
{
    BTNode<T> *left;
    BTNode<T> *right;
    T val;
    Node(T data)
    {
        left = nullptr;
        right = nullptr;
        val = data;
    }
    bool operator==(const BTNode &other)
    {
        return this->val == other->val;
    }
};

// Binary Tree Class
template <class T>
class BinTree
{
private:
    BTNode<T> root;
public:
    BinTree();
    ~BinTree();

    void insert(T);
    void remove(BTNode<T>);

    void destroyRecursive(BTNode<T>);
    void clear();

    bool exists(BTNode<T>,T);
    void get(BTNode<T>);
    int size();

    std::string outputTree();
};

#endif