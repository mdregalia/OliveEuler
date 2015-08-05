#include <iostream>
#include <math.h>

using namespace std;


bool findroots(double a, double b, double c){
	double x1;

	x1 = ((-1)*b + sqrt(b*b - 4*a*c)) / (2*a) ;
	//x2 = ((-1)*b - sqrt(b*b - 4*a*c)) / (2*a) ;
	//cout << sqrt(b*b - 4*a*c) << "\n";
	if (x1 == floor(x1)){
		return true;
	}
	else{
		return false;
	}
}

int main(){

	int i = 144;

	while (true){
		long temp = i*(2*i - 1);
		bool tri = findroots(0.5,0.5,-1*temp);
		bool pent = findroots(1.5,-0.5, -1*temp);
		if (tri && pent){
			cout << temp << "\n";
			break;
		}
		i++;
	}

	//findroots(0.5,0.5,-40755);



	return 0;
}

/* iterate starting at n = 143 for hexaonal, solve for penta and triangle numbers.
 check that they are integers, if so it's valid. If not then don't count. 
 Stop at the first valid one*/