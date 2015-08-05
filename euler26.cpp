#include <iostream>

#define DECPLACE 10000

using namespace std;


int main(){

	int maxrepeat = 1;
	int denomofmax = 1;

	for(int i = 1; i < 1000; i++){
		//division
		char drray[DECPLACE+1];
		int dplace = 0;
		int goesinto = i;
		int startingplace = 1;

		for (int k = 0; k < DECPLACE; k++){
			drray[k] = '0';
		}

		drray[DECPLACE] = '\0';

		while (dplace < DECPLACE){
			int mult = 0;

			//need to make the place we start at bigger by a factor of ten
			startingplace *= 10;

			//if we need to make it a lot bigger
			while (goesinto > startingplace){
				startingplace *= 10;
				if (dplace >= DECPLACE){
					// can't go beyond array
					break;
				}
				//drray[dplace] = '0';
				//cout << "0\n";
				dplace++;
			}

			//find out how many times that it goes into the current thing
			for (int j = 2; j <= 10; j++){
				if (goesinto * j > startingplace){
					mult = j - 1;
					break;
				}
			}

			//actually do the math
			startingplace = startingplace - (mult * goesinto);

			//saves result in the array
			if (dplace >= DECPLACE){
				break;
			}
			drray[dplace] = mult + 48;
			//cout << mult << '\n';
			dplace ++;

			//stop if it has cleanly divided out
			if (startingplace == 0){
				break;
			}
		}

		///FOLLOWING IS FOR PRINTING
		/*cout << i << "   ";

		for (int k = 0; k < DECPLACE; k++){
			cout << drray[k];
		}
		cout << "\n";*/

		//Pattern analysis time

		for (int k = 2; k < 2000; k++){ //assuming pattern can be between 2 and 100

			//ignoring leading nonsense
			int startint = 7;
			//start by assuming current pattern is valid
			int validpat  = 1;

			for (int j = 0; j < i; j++){

				int newplace = startint + j;
				int compare = drray[newplace];
				while (newplace < DECPLACE){ //needs to stay within range
					if (compare != drray[newplace]){
						//if it does not repeat in this pattern
						validpat = 0;
						break;
					}
					//want to check the next place that should be equal to this place
					newplace += k;

				}
			}

			if (validpat == 1){
				if (k > maxrepeat){
					maxrepeat = k;
					denomofmax = i;
					cout << "larger length: " << k << ", denom value: "<< i << "\n";
				}

				//if it worked for a smaller string, it should not count for a larger string
				break;
			}
		}

	}

	cout << maxrepeat << ", d of 1/d is: " <<denomofmax << "\n";

	return 0;
}




