#include <iostream>
#include <string>
#include <sstream>
#include "Prime.h"

#define MAX 1000000
#define PADDING 6

using namespace std;

Prime myprimes;

//actual substitution of numbers within prime
bool countprimes(string myprime, int startplace, string position){ //returns true if 8
	int count = 1; //don't have to count the current one, we know that it works
	for (int k = myprime[startplace] - 48 + 1; k < 10; k++){
		for (int i = startplace; i < PADDING; i++){
			if (position[i - startplace] == '1'){ //then change the value at this place
				myprime[i] = k + 48; //THIS is not working
			}
		}

		//convert to an int and see if it's prime
		stringstream ss(myprime);
		int nextnum;
		ss >> nextnum;

		if(myprimes.checkifprime(nextnum)){
			cout << myprime << " " << nextnum <<"\n";
			count++;
		}
	}

	if (count >= 8){
		cout << position << "\n";
		return true;
	}

	return false;

}

//goes through until it finds a matching character as the first one
bool branch(string myprime, int startplace, string position){
	for (int i = position.size() + startplace; i < PADDING; i++){ //plus one because the first one never branches
		if (myprime[startplace] == myprime[i]){
			//cout << position << "0 " << position << "1\n";
			return (branch(myprime, startplace, position + "0") || branch(myprime, startplace, position + "1"));
		}
		else{
			position += "0";
		}
	}
	//if (startplace + position.size() == PADDING){ //then finally done
		if (countprimes(myprime, startplace, position) == true){
			return true;
		}
		else{
			return false;
		}
	//}
}

//puts in a prime, converts it to string, pads the front of it if it does not have enough digits
string stringify(int prime){
	stringstream ss;
	ss << prime;
	string mystr = ss.str();
	while (mystr.length() < 6){
		mystr = "0" + mystr;
	}
	return mystr;

}

int main(){

	//Prime myprimes;
	myprimes.generateupto(MAX);

	//cout << stringify(3) <<"\n";

	//cout << branch("000003",4,"1") <<"\n";
	cout << countprimes("000109",0,"111000") <<"\n";
	/*
	//commented out for testing purposes
	//starting at each prime in list of ordered primes
	for (int i = 0; i < myprimes.orderedprimes.size(); i++){

		string currentprime = stringify(myprimes.orderedprimes[i]);

		for (int j = 0; j < PADDING; j++){
			if (branch(currentprime,j,"1")){
				cout << currentprime <<"\n";
				break;
			}
		}
	}
	*/

	return 0;
}


//BIG QUESTION


//Pad all primes to x number of digits as max - 1
//FOR start at each Prime in list of ordered primes
	//FOR start at each digit
		//if digit is a one
		//branch out, with all combinations of numbers that are the same within the prime, first one must always be changed though
			//check each final branch, subbing in different numbers
			//return true if the final branch has 8 primes
	//if returned a true then print current prime and break




	//FOR move through starting at each digit
		//IF digit is 0 one or two
			//FOR move through including digits that are the same as the first one - need to branch out here with the options
				//replace the current included digits moving through greater numbers up to ten, see how many are primes