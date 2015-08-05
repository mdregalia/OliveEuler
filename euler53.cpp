#include <iostream>

using namespace std;

long long factorial(int n){
	if (n == 1){
		return 1;
	}
	
	long long product = n;

	while (n > 1){
		n--;
		product *= n;
	}

	return product;
}

long long combinatorics(int n, int r){
	long long top = 1;
	//long long bottom = 1;
	int subtr = n - r;
	int lessthan = 1;

	for(int i = n; i > r; i--){
		top *= i;
		while (subtr >= lessthan){
			if ( top % subtr == 0){
				top /= subtr;
				subtr--;
			}
			else if (top % lessthan == 0){
				top /= lessthan;
				lessthan++;
			}
			else{ //neither one worked, then break out of the loop
				break;
			}

		}
	}

	//final division left over

	for ( int i = lessthan; i <= subtr; i++){
		top /= i;
	}

	//bottom = factorial(r);
	return top;
}

int main(){

	int count = 0;

	for (int n = 23; n <= 100; n++){
		for (int r = 2; r < n; r++){
			if (combinatorics(n, r) > 1000000){
				count += n - 1 - 2*(r - 1);
				break;
			}
		}
	}

	for (int i = 1; i <= 23; i++){
		cout << combinatorics (23,i) << "\n";
	}

	cout << combinatorics(23,10) << "\n";

	cout << count << "\n";

	return 0;
}


//calculate via mirroring properties
//move from top, then move from bottom
//fix it so it doesn't go beyond too quickly