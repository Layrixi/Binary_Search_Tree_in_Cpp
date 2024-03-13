#include <string>
#include <iostream>
#include "dynamic_arr.h"

using namespace std;

class test_class {
public:
	int key = 0;
	friend bool operator>(const test_class& klasa1, const test_class& klasa2)
	{
		return klasa1.key > klasa2.key;
	}
	friend bool operator<(const test_class& klasa1, const test_class& klasa2)
	{
		return klasa1.key < klasa2.key;
	}
	friend bool operator==(const test_class& klasa1, const test_class& klasa2)
	{
		return klasa1.key == klasa2.key;
	}
	friend ostream& operator<<(ostream& os, const test_class klasa1)
	{
		os << klasa1.key;
		return os;
	}
	test_class(int i)
	{
		key = i;
	}
	test_class()
	{
		key = 0;
	}
};

template <typename T> class BST_node {
public:
	T* obj;
	BST_node* child_left;
	BST_node* child_right;
	BST_node* parent;
	bool is_root = 0;
	int repetitions = 1;
	bool is_leaf();
	void print();
	BST_node()
	{
		obj = NULL;
		child_left = NULL;
		child_right = NULL;
		parent = NULL;
	}
	~BST_node() {
		child_left = NULL;
		child_right = NULL;
		parent = NULL;
		delete obj;
		obj = NULL;
	}
};

template <typename T> void BST_node<T>::print()//need to be a pointer to print correctly
{
	cout << *obj << " ";
}

template <typename T> bool BST_node<T>::is_leaf()
{
	if (child_left == NULL && child_right == NULL)
		return 1;
	return 0;
}

template <typename T> class Binary_Search_Tree {
public:
	int height;
	BST_node<T>* root;
	void add(BST_node<T>* new_obj);
	void remove(T* ser_obj);
	BST_node<T>* find_obj(T* ser_obj);
	void preorder(BST_node<T>* sub_root);
	void inorder(BST_node<T>* sub_root);
	void print_tree();
	void print_tree_inorder(BST_node<T>* sub_root);
	void clear(BST_node<T>* sub_root);
	void subclear(BST_node<T>* sub_root);
	int get_height(BST_node<T>* sub_root);
	Binary_Search_Tree()
	{
		root = 0;
		height = 0;
	}
	~Binary_Search_Tree()
	{
		clear(root);
	}
};

template <typename T> void Binary_Search_Tree<T>::print_tree()
{
	if (root == NULL)
		cout << "\nTree is empty\n";
	else
	{
		cout << "BST:\n";
		//cout << "height: " << end;
		cout << "{\n";
		print_tree_inorder(root);
		cout << "}\n";
	}
}
template <typename T> void Binary_Search_Tree<T>::print_tree_inorder(BST_node<T>* sub_root)
{
	if (sub_root == NULL)
		return;
	print_tree_inorder(sub_root->child_left);
	cout << "{ node addr: " << sub_root <<
		"; node child left addr: " << sub_root->child_left <<
		"; node child right addr: " << sub_root->child_right <<
		"; node parent:" << sub_root->parent
		<< "value: ";
	sub_root->print();
	cout << "}"<<endl;
	print_tree_inorder(sub_root->child_right);
}

template <typename T> void Binary_Search_Tree<T>::add(BST_node<T>* new_obj)
{
	//pierw root check
	if (root == NULL)
	{
		root = new_obj;
	}
	else
	{
		BST_node<T>* ptr = root;
		while (ptr != NULL)
		{
			if (*new_obj->obj < *ptr->obj)
			{
				if (ptr->child_left == NULL)
				{
					//przypisania w lewo
					ptr->child_left = new_obj;
					new_obj->parent = ptr;
					return;
				}
				else
					ptr = ptr->child_left;
			}
			else if(*new_obj->obj > *ptr->obj)
			{
				if (ptr->child_right == NULL)
				{
					//przypisanie w prawo
					ptr->child_right = new_obj;
					new_obj->parent = ptr;
					return;
				}
				else
					ptr = ptr->child_right;
			}
			else
			{
				ptr->repetitions++;
				delete new_obj;
				return;
			}
		}
	}
}

template <typename T> BST_node<T>* Binary_Search_Tree<T>::find_obj(T* ser_obj)
{
	/*if (sub_root == NULL)
		return 0;
	if (*sub_root->obj == *ser_obj)
		return sub_root;
	else if(*ser_obj < *sub_root->obj)
		find_obj(ser_obj, sub_root->child_left);
	else
	find_obj(ser_obj, sub_root->child_right);*///resztki po rekurencji
	BST_node<T>* tmp = root;
	while (tmp != NULL)
	{
		if (*ser_obj == *tmp->obj)
			return tmp;
		else if (*ser_obj > *tmp->obj)
			tmp = tmp->child_right;
		else
			tmp = tmp->child_left;
	}
	return tmp;
}

template <typename T> void Binary_Search_Tree<T>::remove(T* ser_obj)//problem taki, że jest problem jak odwołuje się do parenta bo root nie ma parenta
{
	if (root == NULL)
		return;//nie rob nic jesli drzewo puste
	
	BST_node<T>* ptr = find_obj(ser_obj);
	//4 cases
	//1 - node is a leaf
	if (ptr->is_leaf() == 1)
	{
		if (ptr == root)
		{
			delete ptr;
			ptr = NULL;

		}
		else
		{
			if (*ptr->obj < *ptr->parent->obj)//jest po lewym dzieckiem
			{
				ptr->parent->child_left = NULL;
				delete ptr;
				ptr = NULL;

			}
			else//jest po prawym dzieckiem
			{
				ptr->parent->child_right = NULL;
				delete ptr;
				ptr = NULL;

			}
		}
	}
	//2 - ma lewego potomka
	else if (ptr->child_left != NULL && ptr->child_right == NULL)
	{
		if (ptr == root)
		{
			root = ptr->child_left;
			delete ptr;
			ptr = NULL;
		}
		else
		{
			if (*ptr->obj < *ptr->parent->obj)//jest po lewym dzieckiem
			{
				ptr->parent->child_left = ptr->child_left;
				ptr->child_left->parent = ptr->parent;
				delete ptr;
				ptr = NULL;

			}
			else//jest po prawym dzieckiem
			{
				ptr->parent->child_right = ptr->child_right;
				ptr->child_right->parent = ptr->parent;
				delete ptr;
				ptr = NULL;

			}
		}
	}
		//3 - ma prawego potomka
	else if (ptr->child_right != NULL && ptr->child_left == NULL)
	{
		if (ptr == root)
		{
			root = ptr->child_right;
			delete ptr;
			ptr = NULL;
		}
		else
		{
			if (*ptr->obj < *ptr->parent->obj)//jest po lewym dzieckiem
			{
				ptr->parent->child_left = ptr->child_left;
				ptr->child_left->parent = ptr->parent;
				delete ptr;
				ptr = NULL;
			}
			else//jest po prawym dzieckiem
			{
				ptr->parent->child_right = ptr->child_right;
				ptr->child_right->parent = ptr->parent;
				delete ptr;
				ptr = NULL;
			}
		}
	}
		//4 - ma dwoch potomkow
	else
	{
			BST_node<T>* temp = ptr->child_right;
			while (temp->child_left != NULL)//znajdz najmniejszy z najwiekszych
				temp = temp->child_left;
			T* pom = new T;
			memcpy(pom, temp->obj, 1*sizeof(T));
			remove(temp->obj);
			ptr->obj = pom;
	}
	
}

template <typename T> void Binary_Search_Tree<T>::inorder(BST_node<T>* sub_root)
{
	if (sub_root == NULL)
		return;
	inorder(sub_root->child_left);
	sub_root->print();
	inorder(sub_root->child_right);
}
template <typename T> void Binary_Search_Tree<T>::preorder(BST_node<T>* sub_root)
{
	if (sub_root == NULL)
		return;
	sub_root->print();
	inorder(sub_root->child_left);
	inorder(sub_root->child_right);
}
template <typename T> void Binary_Search_Tree<T>::subclear(BST_node<T>* sub_root)
{
	if (sub_root == NULL)
		return;
	clear(sub_root->child_left);
	clear(sub_root->child_right);
	delete sub_root;
	sub_root = NULL;

}
template <typename T> void Binary_Search_Tree<T>::clear(BST_node<T>* sub_root)
{
	subclear(sub_root);
	root = NULL;
}

template <typename T> int Binary_Search_Tree<T>::get_height(BST_node<T>* sub_root)
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
		return height_left +1;
	else
		return height_right+1;
}
int main()
{
	Binary_Search_Tree <test_class> *Drzewo = new Binary_Search_Tree<test_class>;
	
	test_class* test;
	BST_node<test_class>* nowy;

	for (int i = 1; i <= 3; i++)
	{
		test = new test_class(i);
		nowy = new BST_node<test_class>;
		nowy->obj = test;
		Drzewo->add(nowy);

		test = new test_class((-1*i));
		nowy = new BST_node<test_class>;
		nowy->obj = test;
		Drzewo->add(nowy);
	}

	test = new test_class(6);
	nowy = new BST_node<test_class>;
	nowy->obj = test;
	Drzewo->add(nowy);
	//^ręczne wpisanie^
	Drzewo->inorder(Drzewo->root);
	cout << endl;
	Drzewo->preorder(Drzewo->root);
	cout << endl;
	Drzewo->print_tree();
	nowy = Drzewo->find_obj(new test_class(3));
	//Drzewo->remove(new test_class(1));
	cout << endl << Drzewo->get_height(Drzewo->root);
	Drzewo->clear(Drzewo->root);
	cout << endl << Drzewo->get_height(Drzewo->root);
	delete Drzewo;
	return 0;
}

