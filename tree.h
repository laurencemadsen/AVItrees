/*
Author: Laurence Madsen
Class: CSI-281
Assignment: Assignment 3
*/
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

struct tree {
	int value;
	tree * leftChild;
	tree * rightChild;

	// fills the trees
	void fill(int test) {
		if (test > value) {
			if (rightChild != nullptr) {
				rightChild->fill(test);
			}
			else {
				rightChild = new tree();
				rightChild->value = test;
			}
		}
		else {
			if (leftChild != nullptr) {
				leftChild->fill(test);
			}
			else {
				leftChild = new tree();
				leftChild->value = test;
			}
		}
	}

	// checks the tree to see if it's valid
	bool check() {
		if (leftChild != nullptr && rightChild != nullptr) {
			if (!leftChild->check()) {
				return false;
			}
			if (!rightChild->check()) {
				return false;
			}
			if (abs(leftChild->height() - rightChild->height()) > 1) {
				return false;
			}
			return true;
		}
		if (leftChild == nullptr && rightChild == nullptr) {
			return true;
		}
		if (leftChild == nullptr) {
			if (rightChild->height() != 1)
			{
				return false;
			}
			return true;
		}
		if (rightChild == nullptr) {
			if (leftChild->height() != 1) {
				return false;
			}
			return true;
		}
		return false;
	}

	// checks the height of the tree
	int height() {
		if (leftChild == nullptr && rightChild == nullptr) {
			return 1;
		}

		if (leftChild == nullptr) {
			return rightChild->height() + 1;
		}

		if (rightChild == nullptr) {
			return leftChild->height() + 1;
		}
		return max(leftChild->height(), rightChild->height()) + 1;
	}

	// outputs whether to REMOVE or to KEEP
	string avlCheck() {
		string command = "KEEP";
		if (!check()) {
			command = "REMOVE";
		}
		return command;
	}
};
