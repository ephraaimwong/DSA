/**
 * @file main.cpp
 * @author iampo (3452838+ephraaimwong@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "binaryTree.h"
#include <iostream>
using namespace std;
/**
 * @brief main prompts user for input.txt containing LISP expression
 * Re-prompt if invalid file
 * Builds tree from LISP Expression and determines if solution is possible, destroys tree.
 * 
 * @return int Exit status
 */
int main() {
	ifstream infile; //Input file stream
	string filename; //Name of input file
	do {
		cout << "Enter LISP file (All those parenthesis...): ";
		cin >> filename;
		infile.open(filename);
		if (!infile) { cerr << "Invalid file. Enter LISP file again: " << endl; } //reprompt user if invalid file
	} while (!infile);
	int targetSum; //Target Sum for Path

	while (infile >> targetSum) {
		binTreeNode<int>* root = new binTreeNode<int>(); //create new root node
		myStack<int> path, reversedPath; //create stack and reversed stack
		readLISP(root, infile);
		bool pathExists = evaluate(root, 0, targetSum, path); // Using binaryTree's evalute method to check if path with targetsum exists
		if (pathExists) {
			cout << endl << "Path in tree exists" << endl;
			//stack reversal
			while (!path.isEmpty()) {
				reversedPath.push(path.top()); //place path top element on reversedpath
				path.pop(); // remove path top element
			}
			while (!reversedPath.isEmpty()) {
				if (reversedPath.top() == 0) { reversedPath.pop(); } // removes the extra that gets printed "0"
				cout << reversedPath.top(); // print all elements of reversedpath from top to bottom of stack
				reversedPath.pop();
				if (!reversedPath.isEmpty()) {
					cout << " + "; // if another stack element exists, add " + " between each cout
				}
			}
			cout << " = " << targetSum << endl<<endl;
		} else {
			cout << "No such path exists, LISP is a pain anyway" << endl;
		}
		destroyTree(root); // destroy binaryTree before reading next line of file

	}
	infile.close();
	return 0;
}