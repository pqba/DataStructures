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

// Returns root of binary tree, by reference
template<class T>
BTNode<T>* BinTree<T>::getRoot(){
    return root;
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
        return existsRecur(nd->right,key);
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

template <class T>
BTNode<T>* BinTree<T>::get(BTNode<T>*node,T item){
    if(!existsRecur(root,item) || node == nullptr) {
        return nullptr;
    }
    if(node->val == item){
        return node;
    }
    return node->val < item ? get(node->right,item) : get(node->left,item);
}
template <class T>
BTNode<T>* BinTree<T>::getParent(BTNode<T>*node, T item) {
    if (!existsRecur(root, item) || node == nullptr) {
        return nullptr;
    }
    if ((node->left && node->left->val == item) || (node->right && node->right->val == item)) {
        return node;
    }
    return node->val < item ? getParent(node->right, item) : getParent(node->left, item);
}

// Removes node from tree, does nothing if node doesn't exist
template <class T>
void BinTree<T>::remove(T item) {
    if (!existsRecur(root, item)) {
        return;
    }
    BTNode<T>* request = get(root, item);
    if (request == nullptr) {
        return;
    }
    BTNode<T>* parent = getParent(root, item);
    
    // Case 0: No children
    if (request->left == nullptr && request->right == nullptr) {
        if (parent == nullptr)
            root = nullptr;
        else if (parent->left == request)
            parent->left = nullptr;
        else
            parent->right = nullptr;
        delete request;
    }
    // Case 2: Both children exist
    else if (request->left && request->right) {
        BTNode<T>* scsr = request->left;
        BTNode<T>* scsrParent = request; // Track parent of the successor
        while (scsr->right != nullptr) {
            scsrParent = scsr;
            scsr = scsr->right;
        }
        T temp = request->val;
        request->val = scsr->val;
        scsr->val = temp;
        
        // Update parent's pointer to successor node
        if (scsrParent->left == scsr) {
            scsrParent->left = scsr->left;
        } else {
            scsrParent->right = scsr->left;
        }
        delete scsr;
    }
    // Case 1: One child exists
    else {
        BTNode<T>* child = (request->left) ? request->left : request->right;

        if (parent == nullptr)
            root = child;
        else if (parent->left == request)
            parent->left = child;
        else
            parent->right = child;

        delete request;
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
// Prints string visualization of tree
template <class T>
void BinTree<T>::display(const std::string&prefix, BTNode<T>*nd,bool isLeft ) const  {
    if(nd == nullptr){
        return;
    }
    std::cout << prefix;
    std::cout << (isLeft ? "|--" : "\\--");
    std::cout << nd->val.print() << "\n";
    display( prefix + (isLeft ? "|   " : "    "), nd->left, true);
    display( prefix + (isLeft ? "|   " : "    "), nd->right, false);
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
