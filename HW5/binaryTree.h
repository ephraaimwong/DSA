/**
 * @file binaryTree.h
 * @author iampo (3452838+ephraaimwong@users.noreply.github.com)
 * @brief 
 * @version 0.1
 * @date 2024-03-28
 * 
 * This header file defines a binary tree structure and provides functions for reading a tree from a LISP expression,
 * evaluating the tree to find a path with a target sum, and destroying the tree.
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include <iostream>
#include <fstream>
#include "myStack.h"
using namespace std;
/**
 * @brief Binary Tree Node
 * 
 * @tparam Type Generics since node can store int or char
 */
template<class Type> 
struct binTreeNode
{
	Type item; //Data stored in node
	binTreeNode<Type>* left, *right; //left right pointers 

	/**
	 * @brief Construct a new bin Tree Node object
	 * 
	 * @param item Data stored in node
	 * @param left Left pointer
	 * @param right Right Pointer
	 */
	binTreeNode(Type item = Type{}, binTreeNode<Type>* left = nullptr, binTreeNode<Type>* right = nullptr) : item(item), left(left), right(right) {}
};
/**
 * @brief Read binaryTree from LISP Expression
 * 
 * @tparam Type Generics since expression holds int and char
 * @param r Reference of Root node
 * @param infile Input file stream 
 */
template<class Type>
void readLISP(binTreeNode<Type>*& r, ifstream& infile) {
	char paren;
	infile >> paren;//read '('
	if (infile.peek() == ')') { //Base case, check for empty tree
		infile >> paren; return;
	}
	// recursive pre-order traversal, root>left>right 
	else {
		Type val;
		infile >> val; //read data
		r = new binTreeNode<Type>(val);
		readLISP(r->left, infile); //call on root->left  
		readLISP(r->right, infile); //call on root->right
		infile >> paren;
	}
}
/**
 * @brief Evaluates a binary tree to determine if there exists a path with a target sum.
 * 
 * @tparam Type Generics since node stores int and char
 * @param r Pointer to Root node(currently evaluated node)
 * @param runningSum Sum of node values along current path
 * @param targetSum Value that running sum should match
 * @param path Stack to store nodes along current path
 * @return true Path exists
 * @return false Path !exists
 */
template <class Type>
bool evaluate(binTreeNode<Type>* r, int runningSum, int targetSum, myStack<Type>& path) {
	if (r == nullptr) { return false; }//Base case: Reached Leaf Node
	runningSum += r->item;
	path.push(r->item);

	if(r->left == nullptr && r->right == nullptr){ //Leaf Node
		if (runningSum == targetSum) { return true; } //Path exists
		else { 
			path.pop(); //backtrack from leaf node
			return false; 
		}
	}

	bool evalL = evaluate(r->left, runningSum, targetSum, path); // evaluate left path
	bool evalR = evaluate(r->right, runningSum, targetSum, path); // evaluate right path
	if (evalL || evalR) { return true; } // if left or right has a path, return true

	path.pop(); //if either left or right not true, backtrack to root's parent node
	return false; // if no path is found throughout whole traversal

}
/**
 * @brief Recursively destroys binaryTree and deallocates memory
 * 
 * Traverses binaryTree in postorder fashion, left>right>root
 * 
 * @tparam Type Type of Data held by node
 * @param r Pointer to root node
 */
template<class Type>
void destroyTree(binTreeNode<Type>* r) {
	if (r == nullptr) { return; } //Base case: current node is nullptr (leaf node)
	destroyTree(r->left); // traverse and delete left subtree
	destroyTree(r->right); // traverse and delete right subtree
	delete r; //delete current node
}