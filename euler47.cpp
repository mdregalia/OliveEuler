#include <iostream>
#include "Prime.h"

using namespace std;

int main(){

	Prime myprimes;
	myprimes.generateupto(1000000);

	int consec = 0;
	int last = 0;

	for (int i = 16; i < 1000000; i++){
		int j = 0;
		int pfac = 0;
		int enough = 0;
		while (myprimes.orderedprimes[j] < i/2){
			if (i % myprimes.orderedprimes[j] == 0){
				pfac++;
				if (pfac == 4){
					enough = 1;
					last = i;
					consec++;
					break;
				}
			}
			j++;
		}
		if (enough == 0){
			consec = 0;
		}
		else if (consec == 4){
			cout << i << "\n";
			break;
		}
	}

	return 0;
}