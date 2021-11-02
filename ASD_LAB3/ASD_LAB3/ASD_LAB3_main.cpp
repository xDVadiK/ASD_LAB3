#include <iostream>
#include "Binary_Search_Tree_for_LAB3.h"

using namespace std;

int main()
{
	cout << "Create a new binary search tree and fill it\n\n";
	Binary_Search_Tree* Tree = new Binary_Search_Tree();
	Tree->insert(20);
	Tree->insert(10);
	Tree->insert(30);
	Tree->insert(5);
	Tree->insert(15);
	Tree->insert(40);
	cout << "Let's run the iterator of traversing the tree in width and depth";
	cout << "\nDFT iterator: ";
	try
	{
		Iterator* dft_iterator = Tree->create_dft_iterator();
		while (dft_iterator->has_next())
		{
			cout << dft_iterator->next() << " ";
		}
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\nBFT iterator: ";
	try
	{
		Iterator* bft_iterator = Tree->create_bft_iterator();
		while (bft_iterator->has_next())
		{
			cout << bft_iterator->next() << " ";
		}
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\n\nTree Size: " << Tree->get_size_tree();
	cout << "\n\nLet's clear the tree and fill it with new values";
	Tree->clear_tree();
	Tree->insert(100);
	Tree->insert(90);
	Tree->insert(125);
	Tree->insert(45);
	Tree->insert(95);
	Tree->insert(110);
	Tree->insert(150);
	cout << "\n\nLet's run the iterator of traversing the tree in width and depth";
	cout << "\nDFT iterator: ";
	try
	{
		Iterator* dft_iterator = Tree->create_dft_iterator();
		while (dft_iterator->has_next())
		{
			cout << dft_iterator->next() << " ";
		}
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\nBFT iterator: ";
	try
	{
		Iterator* bft_iterator = Tree->create_bft_iterator();
		while (bft_iterator->has_next())
		{
			cout << bft_iterator->next() << " ";
		}
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\n\nLet's check if there are elements with keys 110 and 220 in our tree: \n";
	try
	{
		cout << "Element with key 110: ";
		if (Tree->contains(110)) 
		{
			cout << "True\n";
		}
		else cout << "False\n";
		cout << "Element with key 220: ";
		if (Tree->contains(220))
		{
			cout << "True\n";
		}
		else cout << "False\n";
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\nRemove the element with the key 110 and add the element with the key 220";
	try
	{
		Tree->remove(110);
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	Tree->insert(220);
	cout << "\n\nLet's run the iterator of traversing the tree in width and depth";
	cout << "\nDFT iterator: ";
	try
	{
		Iterator* dft_iterator = Tree->create_dft_iterator();
		while (dft_iterator->has_next())
		{
			cout << dft_iterator->next() << " ";
		}
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\nBFT iterator: ";
	try
	{
		Iterator* bft_iterator = Tree->create_bft_iterator();
		while (bft_iterator->has_next())
		{
			cout << bft_iterator->next() << " ";
		}
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}
	cout << "\n\nLet's check if there are elements with keys 110 and 220 in our tree: \n";
	try
	{
		cout << "Element with key 110: ";
		if (Tree->contains(110))
		{
			cout << "True\n";
		}
		else cout << "False\n";
		cout << "Element with key 220: ";
		if (Tree->contains(220))
		{
			cout << "True\n";
		}
		else cout << "False\n";
	}
	catch (const domain_error error)
	{
		cout << error.what();
		return 1;
	}

	return 0;
}