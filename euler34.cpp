#include <iostream>

using namespace std;

int factorial(int start){
	if (start <= 1){
		return 1;
	}
	else{
		return start*factorial(start-1);
	}
}

int digits(int num){
	int digits = 0;
	while(num > 0){
		num = num/10;
		digits++;
	}

	return digits;
}


int main(){

	double sum = 0;

	for(int i = 10; i < 1000000; i++){
		//int i = 145;
		int dig = digits(i);
		int temp = i;
		int thissum = 0;

		for (int j = 0; j < dig; j++){
			//cout << " fact of " << temp % 10 << " is " << factorial(temp % 10) << "\n";
			thissum += factorial(temp % 10);
			temp /= 10;
		}

		//cout << thissum;

		if (thissum == i){
			cout << i <<"\n";
			sum += i;
		}

	}

	cout << "final sum "<< sum << "\n";

	return 0;
}