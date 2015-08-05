#include <iostream>

#define MAXFLEN 2

using namespace std;

int main(){
	int fiba[MAXFLEN];
	int fibb[MAXFLEN]; //holds the oldest one

	//initialize the fibonnacis to all zeros
	for (int i = 0; i < MAXFLEN; i++){
		fiba[i] = 0;
		fibb[i] = 0;
	}

	fiba[MAXFLEN - 1] = 1;
	fibb[MAXFLEN - 1] = 1;
	long int acount = 2;

	while (true){
		if (fiba[0] != 0){
			//1000 digit exists
			break;
		}

		//addition
		int carry = 0;
		for (int i = MAXFLEN - 1; i >= 0; i--){
			int tempdigit = fiba[i] + fibb[i] + carry;
			if (tempdigit > 10){
				carry = tempdigit / 10;
				tempdigit = tempdigit % 10;
			}
			else{
				carry = 0;
			}

			//now shift a to b, and new to a
			fibb[i] = fiba[i];
			fiba[i] = tempdigit;
		}
		acount++;

	}

	for (int i = 0; i < MAXFLEN; i++){
		cout << fiba[i];
	}

	cout << "\n" << acount << "\n";
}

///EFFICIENT METHOD
/*#expand integer type to 1000 digits
#make 1000 digit lowest number*/
/* start with n=512 or something
find fibonnaci, if smaller than comparison, add 128 to n. continue until bigger
once bigger, do binary search between prev value of n and current to find smallest version of n
mid: if smaller than 1000 it becomes small end, if larger becomes right end, and if larger save as smallest
once binary points equal each other or one away, stop
*/