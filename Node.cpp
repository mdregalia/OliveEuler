#include "Node.h"
#include <iostream>

Node::Node(int val){
	value = val;
	sum = -1;
	rightorleft = -1; // 0 for left and 1 for right
	rightchild = 0; //NULL';
	leftchild = 0; //NULL';

};

/*Node::~Node(){


	if(rightchild){
		std::cout << "In rightchild destructor.\n";
		delete rightchild;
		rightchild = 0;
	}
	if(leftchild){
		delete leftchild;
		leftchild = 0;
	}

	//delete rightchild;
	//delete leftchild;
	//rightchild = 0;//NULL;
	//leftchild = 0; //NULL;
}*/

int Node::getvalue(){
	return value;
}