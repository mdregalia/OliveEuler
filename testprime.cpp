#include <iostream>
#include "Prime.h"

using namespace std;

int main(){

	Prime myprime;

	myprime.generatexprimes(25);
	myprime.generatexprimes(25);
	myprime.generateupto(42);
	myprime.generateupto(43);

	for (int i = 0; i < myprime.orderedprimes.size(); i++){
		cout << myprime.orderedprimes[i] << "\n";
	}

	return 0;
}