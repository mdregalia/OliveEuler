#ifndef TREE_H
#define TREE_H

#include "Node.h"

class Tree{

public:
	Tree();
	~Tree();
	void setuptree();
	Node *root;
	int buildarray[5050]; //15 + 14
	int sumall(Node*); //finds the sum of all the subtrees
	void traverse();
	//void findpath(); //after traversing, uses the root node

};

#endif