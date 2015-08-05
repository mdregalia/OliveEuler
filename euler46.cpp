#include <iostream>
#include "Prime.h"

using namespace std;

int main(){

	Prime myprimes;
	int i = 9;

	while (true){
		if (!myprimes.checkifprime(i)){
			int found = 0;
			int s = 1;
			while (2*s*s < i){
				int diff = i - 2*s*s;
				if (myprimes.checkifprime(diff)){
					found = 1;
					break;
				}
				s++;
			}
			if(!found){
				cout << i << "\n";
				break;
			}
		}

		i += 2;
	}

	return 0;
}