#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>

using namespace std;

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


int main(){

	int max = 0; 

	//int myints[] = {9, 8, 7, 6, 5, 4, 3, 2, 1;

	string myints = "123456789";//'987654321';

	//char anagrama[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '\n'};

	for (int i = 0; i < 10; i++){

	    do {
	        int newint = strtol(myints.c_str(), NULL, 10);
	        if (isprime(newint)){
	        	if (max < newint){
	        		max = newint;
	        	}
	        }


	    } while(std::next_permutation(myints.begin(), myints.end()));


	    //reduces it by one
	    myints = myints.substr(0, myints.size()-1);

	    if (max > 0){
	    	break;
	    }
	}

	cout << max;

	//}




	return 0;
}