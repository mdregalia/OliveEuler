#include <iostream>
#include <math.h>

#define ABUNLIM 28123

using namespace std;

int divisors(int n){
	int r = floor( sqrt(n) ); // n rounded to the greatest integer r so that r*r<=n
	//could do some cool prime way but just going to go through and sum all of them

	int sum = 1;

	for (int i = 2; i <= r; i++){
		//cout << "calculating " << n << " " << i << "\n";
		if ( !(n % i) ){
			sum+= i + (n/i);
			//cout << sum << "\n";
		}
	}
	if ( (r*r == n) && (r != 1)){
		sum -= r;
	}

	return sum;

}

int main(){

	//array of marks of abundance
	//array of marks if it is an abundance sum
	int abun[ABUNLIM];
	int abunsum[ABUNLIM];

	abun[0] = 0;
	abun[1] = 0;
	abunsum[0] = 0;
	abunsum[1] = 0;

	for (int i = 2; i < ABUNLIM; i++){
		int mine = divisors(i);
		//cout << "find abun " << i << " " << mine << "\n";
		if ( mine > i){
			//cout << i ;
			//break;
			abun[i] = 1; //it is abundant
		}
		else{
			abun[i] = 0; //not abundant
		}
		abunsum[i] = 0; //initializes next array
	}

	

	for(int i = 0; i < ABUNLIM; i++){
		//both must be abundant and within array bounds
		if (abun[i] == 1){
			for(int j = i; j < ABUNLIM; j++){
				if (abun[j] == 1){
					if (i + j < ABUNLIM){ //prevents segfault
						abunsum[i + j] = 1;
					}
				}
			}
		}
	}

	long totsum = 0;

	for (int i = 0; i < ABUNLIM; i++){
		if (abunsum[i] == 0){
			totsum += i;
		}
	}

	cout << totsum << "\n";
	

	//from 1 to 283333 or whatever
		//find sum of divisors (similar as before)
		//mark in array as abundant or non abundant
	//for loop of i=0 to end
		//if at i is abundant
			//for loop of j=i to end
				//if second is abundant
					//sum and mark at that sum
	//sum all unmarked in second array


	return 0;
}