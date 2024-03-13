#include <string>
#include "../include/dynamic_arr.hpp"
#include "../include/test.hpp"
#include "../include/bst_node.hpp"
#include "../include/binary_search_tree.hpp"

int main()
{
	Binary_Search_Tree<Test> *Drzewo = new Binary_Search_Tree<Test>;

	Test *test;
	BST_node<Test> *nowy;

	for (int i = 1; i <= 3; i++)
	{
		test = new Test(i);
		nowy = new BST_node<Test>;
		nowy->obj = test;
		Drzewo->add(nowy);

		test = new Test((-1 * i));
		nowy = new BST_node<Test>;
		nowy->obj = test;
		Drzewo->add(nowy);
	}

	test = new Test(6);
	nowy = new BST_node<Test>;
	nowy->obj = test;
	Drzewo->add(nowy);
	//^ręczne wpisanie^
	Drzewo->inorder(Drzewo->root);
	std::cout << std::endl;
	Drzewo->preorder(Drzewo->root);
	std::cout << std::endl;
	Drzewo->print_tree();
	nowy = Drzewo->find_obj(new Test(3));
	std::cout << std::endl << Drzewo->get_height(Drzewo->root);
	Drzewo->clear(Drzewo->root);
	std::cout << std::endl << Drzewo->get_height(Drzewo->root) << std::endl;
	//delete Drzewo;
	return 0;
}
