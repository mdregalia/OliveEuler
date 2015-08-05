#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(){
	int sumarray[260];
	int count = 0;
	int triangle = 1;

	//initialize
	//zero in sumarray means it is non triangular
	for (int i = 0; i < 260 ; i++){
		sumarray[i] = 0;
	}
	//calculate triangle numbers
	while (true){
		int temp = triangle * (triangle + 1) / 2;
		if (temp < 260){
			sumarray[temp] = 1;
		}
		else{
			break;
		}
		triangle++;
	}

	//now read in word by word
	ifstream myfile;
	string wordstr;

	myfile.open("p042_words.txt");

	while (getline(myfile,wordstr,',')){
		//cout << "HERE" <<"\n";
		int mysum = 0;
		for (int i = 1; i < wordstr.length() - 1; i++){
			mysum += wordstr[i] - 64;
		}

		if (sumarray[mysum] == 1){
			count++;
		}
	}

	myfile.close();

	cout << count << "\n";

	return 0;
}