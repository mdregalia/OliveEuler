#include <iostream>
#include <math.h>
#include <vector>

#define MYINT 10000

using namespace std;

int divisors(int);

int main(){

	int divisum[MYINT];
	long mainsum = 0;
	//vector<int> tosum;

	//just not using the zeroth place

	for (int i = 1; i < MYINT; i++){
		//num[i] = i;
		divisum[i] = divisors(i);
	}

	//now we have the array filled

	for (int i = 1; i < MYINT; i++){
		if(divisum[i] > i){ //so it only counts it once
			if (divisum[i] < MYINT){ //can't go beyond the bounds
				if (divisum[divisum[i]] == i){
					//then it is a pair!
					mainsum += i + divisum[i];

				}
			}
		}
	}

	cout << mainsum;

	return 0;
}

int divisors(int n){
	int r = floor( sqrt(n) ); // n rounded to the greatest integer r so that r*r<=n
	//could do some cool prime way but just going to go through and sum all of them

	int sum = 1;

	for (int i = 2; i < r; i++){
		if ( !(n % i) ){
			sum+= i + (n/i);
		}
	}
	if ( !(n % r) ){
		sum += r;
	}

	return sum;

}