#include <iostream>
#include <sstream>
#include <string>
#include "Prime.h"

int main(){
	Prime myprime;
	int count = 0;
	int sum = 0;

	myprime.generatexprimes(100000);
	for (int i = 5; i < myprime.orderedprimes.size(); i++){
		int valid = 1;

		stringstream ss;

		ss << myprime.orderedprimes[i];
		string temp1 = ss.str();
		string temp2 = temp1;

		while (temp1.length() > 0){
			temp1 = temp1.substr(1); //left side
			temp2 = temp2.substr(0, temp2.length() - 1); //right side
			stringstream ss1(temp1);
			stringstream ss2(temp2);
			int p1, p2;
			ss1 >> p1;
			ss2 >> p2;

			if (!myprime.checkifprime(p1) || !myprime.checkifprime(p2)){
				valid = 0;
				break;
			}
		}

		if (valid){
			count++;
			sum += myprime.orderedprimes[i];
			cout << myprime.orderedprimes[i] << "\n";
		}


	}

	cout << sum << " " << count << "\n";
}