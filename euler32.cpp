#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

using namespace std;

int main(){
	// 5. with itoa
	//char numstr[21]; // enough to hold all numbers up to 64-bits
	//result = name + itoa(age, numstr, 10);

	// 4. with IOStreams
	//std::stringstream sstm;
	//sstm << name << age;
	//result = sstm.str();

	//loop through for first and second and check with product, if its valid put in a vector
	//search the vector every time a valid one is found
	//keep sum of all of them

	vector<int> pandigits;
	for (int i = 1; i < 5000; i++){
		for (int j = i + 1; j < 5000; j++){

			//get the multiplier string out of it
			stringstream sstm;
			sstm << i << j << i*j;
			string result = sstm.str();

			//check if it's a candidate
			if (result.length() == 9){
				int valid = 1;

				//check if all 1 through nine exist in string
				for (int k = 1; k <= 9; k++){
					int found = 0;
					for (int l = 0; l < 9; l++){
						if (result[l] == k+48){
							found = 1;
						}
					}
					if (found == 0){ //not in string
						valid = 0;
						//no longer valid
					}
				}

				if (valid == 1){

					cout << i << " " << j << " " << i*j << "\n";
					//then it is valid
					int foundinvec = 0;
					//check vector and then add to vector
					for (int m = 0; m < pandigits.size(); m++){
						if (pandigits[m] == i*j){
							foundinvec = 1;
							break;
						}
					}
					if (foundinvec == 0){
						pandigits.push_back(i*j);
						cout << i << " " << j << " " << i*j << "\n";
					}
				}
			} 
		}
	}

	//cout <<"HERE"; 

 	double finalsum = 0;

 	

	for (int i = 0; i < pandigits.size(); i++){
		finalsum += pandigits[i];
	}
	
	cout <<"SUM: " << finalsum << "\n";



	return 0;
}