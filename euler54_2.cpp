#include <iostream>
#include <string>
#include <fstream>

using namespace std;

mergesort(int *numarray, char *suitarray){

}

partition(){
	
}

int main(){
	
	char suit[10];
	int number[10];

	string line;

	ifstream pokerfile ("p054_poker.txt");

	//put each line into array
	if (pokerfile.is_open()){
		while (getline(pokerfile, line)){
			// puts the line into an array
			for (int i = 0; i < 29; i = i + 3){
				int check = line[i] - 48;

				suit[ (i / 3) ] = line[i + 1];
				
				if (check >= 2 && check < 10){
					number[ (i / 3) ] = check;
				}
				else if (check == 65 - 48){ //A
					number [ (i / 3) ] = 14;
				}
				else if (check == 75 - 48){ //K
					number [ (i / 3) ] = 13;
				}
				else if (check == 81 - 48){ //Q
					number [ (i / 3) ] = 12;
				}
				else if (check == 74 - 48){ //J
					number [ (i / 3) ] = 11;
				}
				else{ //10
					number [ (i / 3) ] = 11;
				}
				cout << suit[i/3] <<" "<< number[i/3] << "\n";
			}

			//now we must sort the array



		}
	}

	pokerfile.close();

	return 0;

}