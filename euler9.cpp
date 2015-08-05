#include <iostream>

using namespace std;

int main(){

	int a, b, c;
	int m, n, k;

	//a=k(m^2-n^2)
	//b=k(2mn)
	//c=k(m^2+n^2)

	for (m = 1; m < 1000; m++){
		for(n = m; n < 1000; n++){ //or is it one
			for(k = 1; k < 200; k++){
				a = k * (n * n - m * m);
				b = k * 2 * m * n;
				c = k * (m * m + n * n);
				if (a + b + c == 1000){
					cout<< a << " " << b << " " << c << " ";
				}
				else if(a + b + c > 1000){
					break; //k can't get any bigger
				}
			}
		}
	}

	return 0;
}

