#include <iostream>
#include "Bignum.h"

using namespace std;

int main(){

	int count = 0;
	Bignum top(1);
	Bignum bottom(2);
	Bignum mult2(2);

	int top2 = 1;
	int bottom2 = 2;
	//count holds the number of things that have more digits than their denominators

	for (int i = 2; i <= 1000; i++){
		//2 + fraction, and then flipped
		
		/*int temp2 = bottom2 * 2 + top2;
		top2 = bottom2;
		bottom2 = temp2;
		int fulltop2 = bottom2 + top2;

		cout << i << ": "<< fulltop2 << "/" << bottom2 << "\n";*/

		Bignum temp;

		temp = bottom.multnum(mult2);
		//bottom.printnum();
		//cout <<" * 2 = ";
		//temp.printnum();
		//cout << "\n\t+ ";
		//top.printnum();
		//cout <<" = ";
		temp = temp.addnum(top);
		//temp.printnum();
		//cout << "\n";
		top = bottom;
		bottom = temp;

		//full number
		Bignum fulltop = bottom.addnum(top);
		//cout << i << ": ";
		//fulltop.printnum();
		//cout << "/";
		//bottom.printnum();
		//cout << "\n";

		if (fulltop.nums.size() > bottom.nums.size()){
			count++;
		}
	}

	cout << count << "\n";

	return 0;
}