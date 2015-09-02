#include <iostream>
#include <vector>

#include "bignum.h"

using namespace std;

int main(){

	int maxsum = 0;

	for (int i = 2; i < 100; i++){ //base

		for (int j = 2; j < 100; j++){ //exponent
			Bignum a(i);

			a = a.expon(j);

			//now sum it
			int tempsum = 0;

			for (int k = 0; k < a.nums.size(); k++ ){
				tempsum += a.nums[k];
			}

			if (tempsum > maxsum){
				maxsum = tempsum;
			}
		}

	}

	cout << maxsum << "\n";

	/*Big num test run
	Bignum a;
	Bignum b;
	Bignum c;
	Bignum d;

	a.nums.push_back(0);
	a.nums.push_back(5);
	a.nums.push_back(8);

	b.nums.push_back(9);
	b.nums.push_back(7);
	b.nums.push_back(9);

	a.printnum();
	cout << "+";
	b.printnum();
	
	cout << "=";

	a = a.multnum(b);

	a.printnum();

	cout << "\n";*/

	return 0;


}

