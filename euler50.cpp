#include <iostream>
#include "Prime.h"

#define MAX 1000000

using namespace std;

int main(){

	Prime myprimes;
	myprimes.generateupto(MAX);

	int longest = 0;
	int sumoflongest = 0;

	for (int start = 0; start < myprimes.orderedprimes.size(); start++){
		int current = 0;
		int sum = 0;
		for (int i = start; i < myprimes.orderedprimes.size(); i++){
			current++;
			sum += myprimes.orderedprimes[i];
			if (sum < MAX){
				if (myprimes.checkifprime(sum)){
					if (current > longest){
						longest = current;
						sumoflongest = sum;
					}
				}
			}
			else{
				break;
			}
		}
	}

	cout << sumoflongest << " " << longest << "\n";

	return 0;
}