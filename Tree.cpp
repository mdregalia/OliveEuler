#include "Tree.h"
#include <iostream>

using namespace std;

Tree::Tree(){
	root = 0; //NULL
	//cout<<"here";
	setuptree();
	cout << sumall(root);
	traverse();
}

Tree::~Tree(){
	cout << "In tree destructor.\n";
	delete root;
	//root = 0; //NULL
}

void Tree::setuptree(){ //builds tree from bottom up
	cout << "HERE";

	int len = 16;

	//make root here
	Node* prevarray[len];
	Node* currentarray[len];
	//root = new Node(buildarray[0]);
	int place = 119; //last number in the array
	Node * currentnode;

	for (int i = 0; i < len; i++){
		prevarray[i] = 0; //'NULL';
		currentarray[i] = 0; //'NULL';
	}

	//return; //test

	for (int i = 14; i >= 0; i--){ //moves through each layer //13 should be zero
		for (int j = 0; j < len; j++){ //sets up the current and previous array
			prevarray[j] = currentarray[j];
			currentarray[j] = 0; // 'NULL';
		}

		int pointarrayplace = 0;
		for (int j = place; j >= place - i; j--){ //moves within the layer, sets child nodes to existing nodes
			currentnode = new Node (buildarray[j]); //used to be place
			currentnode->leftchild = prevarray[pointarrayplace];
			currentnode->rightchild = prevarray[pointarrayplace + 1];

			//cout << pointarrayplace << " " << currentnode << "\n";
			
			currentarray[pointarrayplace] = currentnode;//currentarray[pointarrayplace] = currentnode; //seg faults here

			//cout<<"Layer is: "<< i << " J is: " << j << " Array place: " << pointarrayplace << "\n";
			pointarrayplace++;

			//root = currentnode;
		}
		place = place - i - 1;
	}

	root = currentnode; //last node is the root node

}

int Tree::sumall(Node* mynode){ //changes nodes
	if (mynode->rightchild == 0 && mynode->leftchild == 0){
		//bottom of tree then
		mynode->sum = mynode->value;
		return mynode->sum;

	}
	else if (mynode->sum > -1){ //it's already set 
		return mynode->sum;
	}
	else{ //not set and not null
		int sum1 = sumall(mynode->rightchild);
		int sum2 = sumall(mynode->leftchild);

		if (sum1 > sum2){
			mynode->sum = sum1 + mynode->value;
			mynode->rightorleft = 1;
		}
		else{
			mynode->sum = sum2 + mynode->value;
			mynode->rightorleft = 0;
		}

		return mynode->sum;
	}
}

void Tree::traverse(){
	//make it iterative
	Node * currentnode = root;
	for(int i = 0; i < 14; i++){
		if (currentnode->rightorleft == 1) {
			currentnode = currentnode->rightchild;
			cout<< "Right" << currentnode->value << "\n" ;
		}
		else{
			currentnode = currentnode->leftchild;
			cout<< "Left" << currentnode->value << "\n" ;
		}
	}

}





