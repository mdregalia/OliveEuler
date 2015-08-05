#include <iostream>
#include "Prime.h"

using namespace std;

int main(){

	Prime myprimes;
	int largest = 0;
	int largesta = 0, largestb = 0;

	for (int i = -999; i < 1000; i++){
		for (int j = 2; j < 1000; j++){ //can modify faster by only using primes here, as for n = 0 it has to be prime
			int n = 0;
			int result = 0;
			do{
				result = n*n + i*n + j; 
				n++;
			}while(myprimes.checkifprime(result));
			if (n - 1 > largest){
				largest = n - 1;
				largesta = i;
				largestb = j;
			}
		}
	}

	cout << largest << " " << largesta*largestb <<"\n";

	return 0;
}