#include <iostream>
#include <cstring>
#include <sstream>

using namespace std;

int main(){
	int count = 0;
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;

	for (int i = 1; i < 300000; i++){
		stringstream mine;
		string longstring;
		mine << i;
		longstring = mine.str();
		int newlen = longstring.length() + count;
		if (count < 10 && newlen >= 10){
			one = longstring[10 - count - 1] - 48;
			//cout << one << " i is: "<< i <<"\n";
		}
		else if (count < 100 && newlen >= 100){
			two = longstring[100 - count - 1] - 48;
			//cout << one << " i is: "<< i <<"\n";
		}
		else if (count < 1000 && newlen >= 1000){
			three = longstring[1000 - count - 1] - 48;
			//cout << one << " i is: "<< i <<"\n";
		}
		else if (count < 10000 && newlen >= 10000){
			four = longstring[10000 - count - 1] - 48;
			//cout << one << " i is: "<< i <<"\n";
		}
		else if (count < 100000 && newlen >= 100000){
			five = longstring[100000 - count - 1] - 48;
			//cout << one << " i is: "<< i <<"\n";
		}
		else if (count < 1000000 && newlen >= 1000000){
			six = longstring[1000000 - count - 1] - 48;
			//cout << one << " i is: "<< i <<"\n";
		}
		
		count = newlen;

	}

	int myint;

	myint = one * two * three * four * five * six;

	cout << one << " " << two << " " << three << " " << four << " " << five << " " << six << "\n";

	cout << myint << "\n";

}