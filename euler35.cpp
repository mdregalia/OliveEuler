#include <iostream>
#include <sstream>
#include <string>
#include "Prime.h"

using namespace std;

int main(){
	Prime myprimes;
	int circlecount = 0;

	myprimes.generateupto(1000000);

	for (int i = 2; i < 1000000; i++){
		int temp = i;
		int circle = 0;

		if (!myprimes.checkifprime(i)){ //if not prime in the first place
			continue;
		}

		//cout << i << "\n";

		//convert to string
		stringstream mystream;
		mystream << temp;
		string mystring = mystream.str();

		//checks here if it is circular
		while (true){
			//cout << temp << "\n";
			/*//convert to string
			stringstream mystream;
			mystream << temp;
			string mystring = mystream.str();*/

			//rotate it
			char firstchar = mystring[0];
			mystring = mystring.substr(1);
			mystring += firstchar;

			//convert back
			stringstream ss(mystring);
			ss >> temp;

			if (temp == i){ //then it has circled
				circle = 1;
				break;
			}
			if (!myprimes.checkifprime(temp)){ //then it is not prime and needs to stop rotating through
				break;
			}
		}
		if (circle){
			circlecount++;
		}

	}

	cout << circlecount << "\n";

	return 0;
}