#ifndef BST_NODE_TPP
#define BST_NODE_TPP

template <typename T>
BST_node<T>::BST_node()
{
    obj = NULL;
    parent = NULL;
    child_left = NULL;
    child_right = NULL;
    repetitions = 1;
    is_root = false;
}

template <typename T>
BST_node<T>::~BST_node()
{
    delete obj;
}

template <typename T>
bool BST_node<T>::is_leaf()
{
    return (child_left == NULL && child_right == NULL);
}

template <typename T>
void BST_node<T>::print()
{
    std::cout << *obj << " ";
}

#endif
