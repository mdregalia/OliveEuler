#include <iostream>
#include "primes2.h"

using namespace std;

//include primes, use long prime class probably

int main(){

	long limit = 30000; //can change this

	double place = 1;
	int spacing = 2;
	long long primecount = 0;
	long long seencount = 1;
	int squarelen = 0;
	Prime myprimes;

	//myprimes.generateupto(limit*limit);

	//cout << "Generated\n";

	while (spacing < limit && squarelen == 0){ //can make this bigger
		for (int i = 0; i < 4; i++){
			place += spacing;
			
			if (place > 7){
				if (myprimes.isprime(place)){
					primecount++;
				}
			}
			else{
				if (myprimes.checkifprime(place)){
					primecount++;
				}
			}

			seencount++;

			if (primecount*10 < seencount){
				squarelen = spacing + 1; //I think 1 + the spacing gives the length of the square side
				break;
			}

		}
		spacing += 2;
	}
	//cout.precision(15);
	cout << squarelen << "\n";
	cout << primecount << " " << seencount <<"\n";

	return 0;
}
