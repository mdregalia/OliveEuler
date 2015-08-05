#include <iostream>

using namespace std;

int main(){
	for (int i = 10; i < 100; i++){
		for (int j = i + 1; j < 100; j++){
		//int i = 49;
		//int j = 98;
			double base = (double) i / (double) j;
			//cout << base <<"\n";
			if ( i % 10 == j / 10){
				//cout << "here\n";
				int top = i / 10;
				int bottom = j % 10;
				double frac1 = (double) top / (double) bottom;
				//cout << frac1 << "\n";
				if ( base == frac1){
					cout << i << "/" << j <<"\n";
				}
			}
		}
	}
	return 0;
}