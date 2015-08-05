#include <iostream>

using namespace std;

int main(){

	double place = 1;
	long double sum = 1;
	int spacing = 2;

	while (spacing < 1001){
		for (int i = 0; i < 4; i++){
			place += spacing;
			//cout<< place << "\n";
			sum += place;
		}
		spacing+=2;
	}
	cout.precision(15);
	cout << sum << "\n";

	return 0;
}