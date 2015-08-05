#ifndef NODE_H
#define NODE_H

class Node{
	public:
		Node(int);
		//~Node();
		int getvalue();
		int sum; //includes the current node
		int rightorleft;
		Node *rightchild;
		Node *leftchild;
	//private:
		int value;


};

#endif

/*
Two pointers to child nodes
nextchild holds 0 or 1 indicating left or right, starts with -1
int for current value
int for sum of sub, starts out with -1 again if it's uncalculated
delete sets pointers to null

how to make the tree?*/

//try to catch errors