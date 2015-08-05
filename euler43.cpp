#include <iostream>     // std::cout
#include <algorithm>    // std::next_permutation, std::sort
#include <cstring>
#include <sstream>

using namespace std;

int main () {
  unsigned long long myints[] = {0,1,2,3,4,5,6,7,8,9};

  unsigned long long sum = 0;

  sort (myints,myints + 10);

  //std::cout << "The 3! possible permutations with 3 elements:\n";
  do {
  	if ((myints[1] * 100 + myints[2] * 10 + myints[3]) % 2 == 0){
  		if ((myints[2] * 100 + myints[3] * 10 + myints[4]) % 3 == 0){
  			if ((myints[3] * 100 + myints[4] * 10 + myints[5]) % 5 == 0){
  				if ((myints[4] * 100 + myints[5] * 10 + myints[6]) % 7 == 0){
  					if ((myints[5] * 100 + myints[6] * 10 + myints[7]) % 11 == 0){
  						if ((myints[6] * 100 + myints[7] * 10 + myints[8]) % 13 == 0){
  							if ((myints[7] * 100 + myints[8] * 10 + myints[9]) % 17 == 0){
  								cout << myints[0] << myints[1] << myints[2] << myints[3] << myints[4] << myints[5] << myints[6] << myints[7] << myints[8] << myints[9] << "\n";
  								sum += 	myints[0] * 1000000000 + myints[1] * 100000000 + myints[2] * 10000000 + myints[3] * 1000000 + myints[4] * 100000 + myints[5] * 10000 + myints[6] * 1000 + myints[7] * 100 + myints[8] * 10 + myints[9];
  								cout.precision(20);
  								cout << sum << "\n";
  							}
  						}
  					}
  				}
  			}
  		}
  	}
  } while ( std::next_permutation(myints,myints+10) );

  cout.precision(20);

  cout << sum << "\n";

  return 0;
}