#include <iostream>
#include <sstream>
#include <cstring>
#include <stdlib.h>

using namespace std;

int main(){

	unsigned long long sum = 1;

	for(unsigned long long i = 2; i <= 1000; i++ ){
		unsigned long long current = i;
		//cout << i - 1 << "\n";
		for(unsigned long long j = 0; j < i - 1; j++){
			stringstream mystream;
			string mystr;
			int len = 0;

			current *= i;
			mystream << current;
			mystr = mystream.str();
			len = mystr.length();
			if (len > 10){
				len = len - 10;
			}
			else{
				len = 0;
			}
			//cout << "substring " <<mystr.substr(len) << "\n";
			//cout << mystr << "\n";
			current = strtoll((mystr.substr(len)).c_str(),0,10);
			//cout << current << "\n";
		}
		//cout << current << "\n";
		sum += current;
		cout << "sum: " << sum << "\n";
		sum = sum % 10000000000;
	}

	cout << sum << "\n";
}