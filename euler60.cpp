#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <string>

#include "Prime.h"

using namespace std;

int concat(int a, int b){
	string catted = "";
	int ret;
	stringstream minea, mineb, minec;
	minea << a;
	catted = minea.str();
	mineb << b;
	catted += mineb.str();
	minec << catted;
	minec >> ret;
	return ret; 

}

int main(){

	int findnum = 5;

	Prime p;
	int limit = 10000;
	vector< vector<int> > outside;
	int maxsum = 0;
	bool found5 = 0;

	p.generateupto(limit);

	for (int i = 1; i < p.orderedprimes.size(); i++){

		unordered_map<int,bool> sublist; //change to hashmap

		for (int j = 0; j < i; j++){ //iterates through previous primes, to see if concat works

			int tempa = concat(p.orderedprimes[i],p.orderedprimes[j]);
			int tempb = concat(p.orderedprimes[j],p.orderedprimes[i]);

			if (p.isprime(tempa) && p.isprime(tempb)){
				//if both concats work, then add it to the following
				sublist[p.orderedprimes[j]];
			}
		}

		for (int j = 0; j < outside.size(); j++){ //iterates previous groups
		
			//if everything in list is in sublist, append copy with current number to the end
			bool allvalid = 1;

			for (int k = 0; k < outside[j].size(); k++){
				if (sublist.find(outside[j][k]) == sublist.end()){
					allvalid = 0;
				}
			}

			if (allvalid == 1){
				//add a copy of the set & the new addition to the current one
				//see if the length is 5 with the new one, and then set that as a found set, and sum them
				vector <int> copyv = outside[j];
				copyv.push_back(p.orderedprimes[i]);
				outside.push_back(copyv);

				if (copyv.size() == findnum){ //then it is a group of 5
					cout << "here!\n";
					cout << copyv.size()  << "\n";
					int tempsum = 0;

					for (int k = 0; k < findnum; k++){
						cout << copyv[k] <<" ";
						tempsum += copyv[k];
					}
					cout <<"\n";

					if (tempsum < maxsum && maxsum != 0){
						maxsum = tempsum;
						found5 = 1;
					}
					if (maxsum == 0){
						maxsum = tempsum;
						found5 = 1;
					}

				}
			}
		}
		
		//append a copy of every pair that was found to the main list
		for ( auto it = sublist.begin(); it != sublist.end(); ++it ){
			vector<int> tempv;
			tempv.push_back(it->first);
			tempv.push_back(p.orderedprimes[i]);
			outside.push_back(tempv);
		}

	}

	if (found5){
		cout << "MIN 5: " << maxsum <<"\n";
	}

	return 0;

}