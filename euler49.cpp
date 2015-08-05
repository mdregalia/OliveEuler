#include <iostream>
#include "Prime.h"

using namespace std;

int checkpermute(int a, int b, int c){
	//this is for four digits
	int arraya[10] = {0,0,0,0,0,0,0,0,0,0};
	int arrayb[10] = {0,0,0,0,0,0,0,0,0,0};
	int arrayc[10] = {0,0,0,0,0,0,0,0,0,0};

	for(int i = 0; i < 4; i++){
		//cout << a << " " << b << " " << c <<"\n";
		arraya[a % 10]++;
		arrayb[b % 10]++;
		arrayc[c % 10]++;
		a /= 10;
		b /= 10;
		c /= 10;
	}

	for (int i = 0; i < 10; i++){
		if (arraya[i] != arrayb[i] || arraya[i] != arrayc[i]){
			return 0;
		}
	}

	return 1;

}

int main(){

	int count = 0;

	Prime myprimes;

	myprimes.generateupto(10000);

	//find the place of the first prime over 1000
	int i = 0;
	while (myprimes.orderedprimes[i] < 1000){
		i++;
	}

	//iterate through the primes
	for( int j = i ; j < myprimes.orderedprimes.size(); j++){
		//iterate through the possible differences
		int currentprime = myprimes.orderedprimes[j];

		int valid = 0;

		for (int k = 50; k < 5000; k += 2){
			if (currentprime + 2*k >= 10000){
				break;
			}
			if (myprimes.checkifprime(currentprime + k)){
				if (myprimes.checkifprime(currentprime + k + k)){
					if (checkpermute(currentprime, currentprime + k, currentprime + k + k )){
						valid = 1;
						cout << currentprime << currentprime + k << currentprime + k + k << "\n" ;
						break;
					}
				}
			}
		}

		if (valid == 1){
			count++;
			if (count == 2){
				break;
			}
		}

	}


	return 0;
}