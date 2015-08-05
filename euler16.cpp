#include <iostream>

using namespace std;

int main(){
	int digits[1000];

	for( int i = 0; i < 1000; i++){
		digits[i]=0;
	}

	digits[0]=1;
	
	for (int j = 0; j < 1000; j++){ //each multiplication by two
		int carry = 0;
		for (int i = 0; i < 1000; i++){
			int temp = digits[i];
			temp = temp*2 + carry;
			carry = temp/10;
			digits[i] = temp % 10;
		}
	}

	int powersum = 0;

	for (int i = 0; i < 1000; i++){
		powersum += digits[i];
	}

	cout <<  powersum << endl;

	return 0;
}