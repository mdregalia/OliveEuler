#include <iostream>
#include <math.h>

using namespace std;

int main(){

	int sumofsum = 0;

	for (int i = 10; i < 1000000; i++){

		//gets the number of digits for the for loops
		int digits = 0;
		int temp = i;
		while(temp > 0){
			temp = temp/10;
			digits++;
		}

		temp = i;

		int digsum = 0;
		//holds the sum of the fifth power of the digits 
		for (int j = 0; j < digits; j++){
			digsum += pow(temp % 10, 5);
			temp = temp/10;
		}

		if (digsum == i){
			cout<< i << "\n";
			sumofsum += i;
		}
	}

	cout << sumofsum << "\n";

	return 0;
}
