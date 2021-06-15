/*
Author: Laurence Madsen
Class: CSI-281
Assignment: Assignment 3
Date Assigned: 9/28/18
Due Date: 10/19/18
Description: AVL tree checker
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the
definition and consequences of plagiarism and acknowledge that the assessor
of this assignment may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of
academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking
service (which may then retain a copy of this assignment on its
database for the purpose of future plagiarism checking)
*/
#include "tree.h"
int main()
{
	int numTrees;
	int insert;
	int test;
	ifstream input("test.txt");
	input >> numTrees;

	// gets the number of trees
	for (int i = 1; i <= numTrees; i++){
		tree * root = new tree();
		root->leftChild = nullptr;
		root->rightChild = nullptr;
		cout << "Tree " << i << " : ";
	// creates tree and calls function to check if it's an avl tree
		input >> insert;
		for (int j = 0; j < insert; j++){
			input >> test;
			if (j != 0){
				root->fill(test);
			}
			else{
				root->value = test;
			}
		}
		cout << root->avlCheck() << endl;
	}
	system("pause");
	return 0;
}