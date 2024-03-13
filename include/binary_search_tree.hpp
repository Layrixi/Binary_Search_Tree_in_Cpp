#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <cstddef>
#include <iostream>
#include "bst_node.hpp"

template <typename T>
class Binary_Search_Tree;

template <typename T>
class Binary_Search_Tree
{
public:
    Binary_Search_Tree();
    ~Binary_Search_Tree();
    void add(BST_node<T> *new_obj);
    void remove(T *del_obj);
    BST_node<T> *find_obj(T *ser_obj);
    void inorder(BST_node<T> *sub_root);
    void preorder(BST_node<T> *sub_root);
    void print_tree();
    void print_tree_inorder(BST_node<T> *sub_root);
    void clear(BST_node<T> *sub_root);
    void subclear(BST_node<T> *sub_root);
    int get_height(BST_node<T> *sub_root);

    int height;
    BST_node<T> *root;
};

#include "binary_search_tree.tpp"

#endif