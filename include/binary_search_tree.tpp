#ifndef BINARY_SEARCH_TREE_TPP
#define BINARY_SEARCH_TREE_TPP

template <typename T>
Binary_Search_Tree<T>::Binary_Search_Tree()
{
    root = NULL;
    height = 0;
}

template <typename T>
Binary_Search_Tree<T>::~Binary_Search_Tree()
{
    clear(root);
}

template <typename T>
void Binary_Search_Tree<T>::add(BST_node<T> *new_obj)
{
    BST_node<T> *current = root;
    BST_node<T> *parent = NULL;
    if (root == NULL)
    {
        root = new_obj;
        root->is_root = true;
        return;
    }
    while (current != NULL)
    {
        parent = current;
        if (*new_obj->obj < *current->obj)
        {
            current = current->child_left;
        }
        else if (*new_obj->obj > *current->obj)
        {
            current = current->child_right;
        }
        else
        {
            current->repetitions++;
            return;
        }
    }
    if (*new_obj->obj < *parent->obj)
    {
        parent->child_left = new_obj;
        new_obj->parent = parent;
    }
    else
    {
        parent->child_right = new_obj;
        new_obj->parent = parent;
    }
}

template <typename T>
void Binary_Search_Tree<T>::remove(T *del_obj)
{
    BST_node<T> *current = root;
    BST_node<T> *parent = NULL;
    while (current != NULL)
    {
        if (*del_obj < *current->obj)
        {
            parent = current;
            current = current->child_left;
        }
        else if (*del_obj > *current->obj)
        {
            parent = current;
            current = current->child_right;
        }
        else
        {
            if (current->repetitions > 1)
            {
                current->repetitions--;
                return;
            }
            if (current->is_leaf())
            {
                if (current->is_root)
                {
                    root = NULL;
                    delete current;
                    return;
                }
                if (current == parent->child_left)
                {
                    parent->child_left = NULL;
                }
                else
                {
                    parent->child_right = NULL;
                }
                delete current;
                return;
            }
            if (current->child_left != NULL && current->child_right == NULL)
            {
                if (current->is_root)
                {
                    root = current->child_left;
                    root->is_root = true;
                    delete current;
                    return;
                }
                if (current == parent->child_left)
                {
                    parent->child_left = current->child_left;
                }
                else
                {
                    parent->child_right = current->child_left;
                }
                delete current;
                return;
            }
            if (current->child_left == NULL && current->child_right != NULL)
            {
                if (current->is_root)
                {
                    root = current->child_right;
                    root->is_root = true;
                    delete current;
                    return;
                }
                if (current == parent->child_left)
                {
                    parent->child_left = current->child_right;
                }
                else
                {
                    parent->child_right = current->child_right;
                }
                delete current;
                return;
            }
            if (current->child_left != NULL && current->child_right != NULL)
            {
                BST_node<T> *successor = current->child_right;
                while (successor->child_left != NULL)
                {
                    successor = successor->child_left;
                }
                T *temp = current->obj;
                current->obj = successor->obj;
                successor->obj = temp;
                if (successor->repetitions > 1)
                {
                    successor->repetitions--;
                    return;
                }
                if (successor->is_leaf())
                {
                    if (successor->is_root)
                    {
                        root = NULL;
                        delete successor;
                        return;
                    }
                    if (successor == successor->parent->child_left)
                    {
                        successor->parent->child_left = NULL;
                    }
                    else
                    {
                        successor->parent->child_right = NULL;
                    }
                    delete successor;
                    return;
                }
                if (successor->child_left != NULL && successor->child_right == NULL)
                {
                    if (successor->is_root)
                    {
                        root = successor->child_left;
                        root->is_root = true;
                        delete successor;
                        return;
                    }
                    if (successor == successor->parent->child_left)
                    {
                        successor->parent->child_left = successor->child_left;
                    }
                    else
                    {
                        successor->parent->child_right = successor->child_left;
                    }
                    delete successor;
                    return;
                }
                if (successor->child_left == NULL && successor->child_right != NULL)
                {
                    if (successor->is_root)
                    {
                        root = successor->child_right;
                        root->is_root = true;
                        delete successor;
                        return;
                    }
                    if (successor == successor->parent->child_left)
                    {
                        successor->parent->child_left = successor->child_right;
                    }
                    else
                    {
                        successor->parent->child_right = successor->child_right;
                    }
                    delete successor;
                    return;
                }
            }
        }
    }
}

template <typename T>
BST_node<T> *Binary_Search_Tree<T>::find_obj(T *ser_obj)
{
    BST_node<T> *tmp = root;
    while (tmp != NULL)
    {
        if (*ser_obj == *tmp->obj)
            return tmp;
        else if (*ser_obj < *tmp->obj)
            tmp = tmp->child_left;
        else
            tmp = tmp->child_right;
    }
    return NULL;
}

template <typename T>
void Binary_Search_Tree<T>::inorder(BST_node<T> *sub_root)
{
    if (sub_root != NULL)
    {
        inorder(sub_root->child_left);
        sub_root->print();
        inorder(sub_root->child_right);
    }
}

template <typename T>
void Binary_Search_Tree<T>::preorder(BST_node<T> *sub_root)
{
    if (sub_root != NULL)
    {
        sub_root->print();
        preorder(sub_root->child_left);
        preorder(sub_root->child_right);
    }
}

template <typename T>
void Binary_Search_Tree<T>::print_tree()
{
    if (root == NULL)
    {
        std::cout << "\nTree is empty\n";
    }
    else
    {
        std::cout << "BST:\n";
        std::cout << "{\n";
        print_tree_inorder(root);
        std::cout << "}\n";
    }
}

template <typename T>
void Binary_Search_Tree<T>::print_tree_inorder(BST_node<T> *sub_root)
{
    if (sub_root != NULL)
    {
        print_tree_inorder(sub_root->child_left);
        std::cout << "{ node addr: " << sub_root << ", parent addr: " << sub_root->parent << ", left child addr: " << sub_root->child_left << ", right child addr: " << sub_root->child_right << "value: ";
        sub_root->print();
        std::cout << "}\n";
        print_tree_inorder(sub_root->child_right);
    }
}

template <typename T>
void Binary_Search_Tree<T>::clear(BST_node<T> *sub_root)
{
    subclear(sub_root);
    root = NULL;
}

template <typename T>
void Binary_Search_Tree<T>::subclear(BST_node<T> *sub_root)
{
    if (sub_root != NULL)
    {
        clear(sub_root->child_left);
        clear(sub_root->child_right);
        delete sub_root;
        sub_root = NULL;
    }
}

template <typename T>
int Binary_Search_Tree<T>::get_height(BST_node<T> *sub_root)
{
    if (root == NULL)
        return -1;
    if (sub_root == NULL)
    {
        return 0;
    }
    int height_left = get_height(sub_root->child_left);
    int height_right = get_height(sub_root->child_right);
    if (height_left >= height_right)
        return height_left + 1;
    else
        return height_right + 1;
}

#endif