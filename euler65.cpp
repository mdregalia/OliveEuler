#include <iostream>
#include "bignum.h"

#define MAXNUM 100

using namespace std;

vector<int> fractions;

int main(){

	int mult_i = 1;
	fractions.push_back(2);


	//make array of 1000
	for (int i = 1; i < MAXNUM; i++){
		if (i % 3 == 2){
			fractions.push_back(2*mult_i);
			mult_i++;
		}
		else{
			fractions.push_back(1);
		}
	}

	Bignum numer (1);
	Bignum numprev;
	Bignum denom (fractions[MAXNUM - 1]);
	denom.printnum();
	cout << "\n";
	Bignum finaldenom;

	for (int i = 2; i <= MAXNUM; i++){
		if (i == MAXNUM){
			finaldenom = denom;
		}
		Bignum adding(fractions[MAXNUM - (i)]);
		//adding.printnum();
		//cout << "\n";
		numprev = numer;
		numer = denom; //numer should always be 1
		denom = adding.multnum(denom);
		denom = denom.addnum(numprev);
	}
	
	denom.printnum();
	cout << "/";
	finaldenom.printnum();

	cout << "\n";

	int mysum = denom.sumdigits();

	cout << "sum: " << mysum << "\n"; 

	return 0;
}

/* HAVE TO MODIFY BIGINT to accept more than one digit*/