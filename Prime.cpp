#include "Prime.h"

#include <iostream>
#include <vector>
#include <math.h>


Prime::Prime(){
	primemap[2];
	orderedprimes.push_back(2);
	primemap[3];
	orderedprimes.push_back(3);
	primemap[5];
	orderedprimes.push_back(5);
	primemap[7];
	orderedprimes.push_back(7);
	largest = 7;

	//generate up to where we can use the 6i plus or minus one
	//set the builder one
}

int Prime::isprime(int n){ //tells if an individual number is prime or not, used in generation
	if (n % 3 == 0 || n % 2 == 0){
		return 0;
	}
	else {
		int r = floor( sqrt(n) ); // n rounded to the greatest integer r so that r*r<=n
		int f = 5;
		while (f <= r){
			if (n % f == 0){
				return 0;
			}
			if (n % (f + 2) == 0){
				return 0;
			}
			f = f + 6;
		}
		return 1;
	}
}

int Prime::checkifprime(int n){ //if a user wants to see if a specific number is prime
	if (n > largest){
		generateupto(n);
	}
	
	if (primemap.find(n) == primemap.end()){
		return 0;
	}
	else{
		return 1;
	}
}

void Prime::generateupto(int n){
	if (n < largest){
		return;
	}
	else{
		for (int i = largest + 1; i <= n ; i++){
			if (isprime(i)){
				primemap[i];
				orderedprimes.push_back(i);
				largest = i;
			}
		}
	}
}

void Prime::generatexprimes(int n){
	int numprimes = orderedprimes.size();
	int current = largest + 1;
	while (numprimes < n){
		if (isprime(current)){
			primemap[current];
			orderedprimes.push_back(current);
			largest = current;
			numprimes++;
		}
		current++;
	}
}

Prime::~Prime(){	
}