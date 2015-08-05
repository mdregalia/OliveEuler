#include <iostream>

using namespace std;

int main(){

	int maxcount = 1;
	int longnum = 1;

	for (int i = 2; i < 1000000; i++){
		//cout <<  i;
		long mynum = i;
		int count = 1; 
		while (mynum != 1){
			if (mynum % 2){ //odd
				mynum = 3 * mynum + 1;  
			}
			else{ //even
				mynum /= 2;
			}
			count++;
			//std::cout << " " << mynum;
		}
		if (count > maxcount){
			maxcount = count;
			longnum = i;
		}
		//std::cout << "\n";
	}

	cout<< longnum << " " << maxcount <<endl;

	return 0;
}