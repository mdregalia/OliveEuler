#include <iostream>
#include <math.h>

#define MYMAX 100

using namespace std;

int main(){

	//holds value of whatever
	int totunique = (99-12)*99;
	int possible = 99*99;
	int testing = 0;

	/*int totunique = (4-1)*4;
	int possible = 4*4;*/

	//find the overlappers
	for (int i = 2; i <= 3; i++){ //base
		//power of next within 100
		/*if (i == 4 || i == 8 || i == 9){
			continue;
			//don't want to double count
		}*/

		int powof[601];

		for (int j = 2; j < 601; j++){
			powof[j] = 0; //that power of has not been seen

			//unless in base version
			if (j <= MYMAX){
				powof[j] = 1;
			}
		}

		//now the duplicate version
		for (int j = 2; j < 7; j++){
			int newbase = pow(i,j);
			if (newbase <= MYMAX){
				//then we can count it
				cout << newbase << "\n";

				//find powers of duplicates
				for (int k = 2; k <= MYMAX; k++){
					int temp = j*k;
					if (powof[temp] == 0){
						powof[temp] = 1; //next time it will be a duplicate
						cout << i << " to the power of " << j << " * "<< k <<" = " << j*k << " has not yet been seen\n"; 
						totunique++;
					}
					else{
						testing++;
					}
				}
			}
		}
	}

	totunique += 50*4;
	testing += 49*4;

	cout << totunique << "\n";
	cout << possible << "\n";
	cout << possible - testing << "\n";

	return 0;
}