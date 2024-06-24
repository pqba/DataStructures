#ifndef BINTREE_H
#define BINTREE_H
#include <string>

// Node structure for Binary Search Tree. Must implement == on template class data as well as a < or > and a print() function
template <class T>
struct BTNode
{
    BTNode<T> *left;
    BTNode<T> *right;
    T val;
    BTNode(T data)
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
    BTNode<T>* root;
public:
    BinTree();
    ~BinTree();

    void insert(T);
    BTNode<T>* insertSubtree(BTNode<T>*,T);
    void remove(BTNode<T>*,T);

    void destroyRecur(BTNode<T>*);
    void clear();

    bool existsRecur(BTNode<T>*,T);
    bool existsIter(BTNode<T>*,T);
    void get(BTNode<T>);
    int subtreeSize(BTNode<T>*);
    int size();


    std::string inOrder();
    std::string inOrderSubtree(BTNode<T>*,std::string);
    std::string outputTree();
    std::string postOrder(BTNode<T>*,std::string current);
};

#endif