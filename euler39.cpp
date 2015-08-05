#include <iostream>
#include <math.h>

using namespace std;

//a+b+c <= 1000
//a^2 + b^2 + c^2

int main(){

	int ways[1001];
	int max = 0;
	int maxnum = 0;
	for (int i = 0; i < 1001; i++){
		ways[i] = 0;
	}

	for (int a = 1; a < 999; a++ ){
		for (int b = 1; b < 999; b++){
			double c1 = sqrt(a * a + b * b);
			double c2 = floor(c1);
			if (c1 == c2){ //then it is an integer value
				int sum = a + b + c1;
				if (sum <= 1000){ //now it's valid
					ways[sum]++;
					if (ways[sum] > max){
						max = ways[sum];
						maxnum = sum;
					}
				}
			}
		}
	}

	cout << max << " has a value of p: " << maxnum << "\n";

	return 0;
}