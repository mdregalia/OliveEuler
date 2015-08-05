#include <iostream>
#include <cstring>
#include <sstream>

#define END 9999

using namespace std;

int main(){

	int max = 0;

	for (int i = 0; i < END; i++){

		stringstream mystream;
		string result;
		int j = 1;

		//creates the string
		while (result.length() < 9){
			mystream << i*j;
			result = mystream.str();
			j++;
		}
		
		//now if it is the right length then calculate it
		if (result.length() == 9){
			int allnine = 1;
			for(j = 1; j <= 9; j++){
				int found = 0;
				//find each in list
				for(int k = 0; k <= 9; k++){
					if (result[k] == j + 48){
						found = 1;
					}
				}

				if (found == 0){
					allnine = 0;
				}
			} 
			if (allnine == 1){ //then all were found
				int testmax;
				mystream >> testmax;
				cout << result << " i is: "<< i << "\n";
				if (testmax > max){
					max = testmax;
				}
			}
		}

	}

	cout << max << "\n";

	return 0;
}