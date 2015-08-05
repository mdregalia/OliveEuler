#include <iostream>
#include <math.h>

using namespace std;

int main(){

	int count = 0;

	int currentnum = 1;

	for (int i = 2; i > 0; i++){
		currentnum += i;
		count = 1;
		int square = floor(sqrt(currentnum));

		for (int j = 2; j < square; j++){
			if (!(currentnum % j)){
				count += 2;
			}
		}

		if (!(currentnum % square)){
			count++;
		}

		if (count > 500){
			cout.precision(30);
			cout << currentnum;
			break;
		}
	}
	return 0;
}

/*
with memo:
start by dividing by two, gives highest and lowest divisor
add all in list to current vector
keep incrementing until it reaches the square root at which point all will have been found

without memo:
find square root
start from mod two up to square root and increment trying each
make faster by not checking multiples of things that don't divide in

*/