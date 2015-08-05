#include <iostream>
#include <math.h>

bool isprime(int);

int main(){
	double sum = 2;
	for(int i = 3; i < 2000000; i += 2){
		if ( isprime( i ) ){
			sum += i;
		}
	}
	std::cout.precision(20);
	std::cout << sum;

	return 0;
}

/*bool isprime(int q){
	for (int i = 3; i < q; i += 2){
		if ( !( q % i )) {
			return false;
		}
	}
	return true;
}*/

bool isprime(int n){
	if ( n == 1 ){
		return false;
	}
	else if ( n < 4 ){ 
		return true; //2 and 3 are prime
	}
	else if ( n % 2 == 0 ){
		return false;
	}
	else if ( n < 9){ 
		return true; //we have already excluded 4,6 and 8.
	}
	else if (n % 3 == 0){
		return false;
	}
	else {
		int r = floor( sqrt(n) ); // n rounded to the greatest integer r so that r*r<=n
		int f = 5;
		while( f <= r ){
			if (n % f == 0){
				return false; //(and step out of the function)
			}
			if ( n % ( f + 2 ) == 0){
				return false; //(and step out of the function)
			}
			f = f + 6;
		}
		return true;
	}
}