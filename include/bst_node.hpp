#ifndef BST_NODE_HPP
#define BST_NODE_HPP

#include <cstddef>
#include <iostream>

template <typename T>
class BST_node
{
public:
    BST_node();
    ~BST_node();
    bool is_leaf();
    void print();
    T *obj;
    BST_node<T> *parent;
    BST_node<T> *child_left;
    BST_node<T> *child_right;
    int repetitions;
    bool is_root;
};

#include "bst_node.tpp"

#endif