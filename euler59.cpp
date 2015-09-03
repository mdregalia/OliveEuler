#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdlib.h>

using namespace std;

int main(){

	string line;

	int sum = 0;

 	ifstream myfile ("p059_cipher.txt");

 	//ofstream myfile2 ("e59output.txt");

 	//myfile2.open();

 	vector<int> todecode;

 	//form vector of ints to decode
 	if (myfile.is_open()){
   		
   		while ( getline (myfile,line,',') ){
			
   			int tempint = atoi(line.c_str());

			todecode.push_back(tempint);
    	}

    	myfile.close();
 	}

 	//for (int i = 97; i <= 122; i++){
 	//	for(int j = 97; j <= 122; j++){
 	//		for (int k = 97; k <= 122; k++){ //picks the three letters

 	int i = 103, j = 111, k = 100;

 				string newstr = "";

 				for(int q = 0; q < (int) todecode.size(); q++){
 					
 					if (q % 3 == 0){
 						sum += todecode[q] ^ i;
 						newstr += (char) (todecode[q] ^ i);

 					}
 					else if (q % 3 == 1){
 						sum += todecode[q] ^ j;
 						newstr += (char) (todecode[q] ^ j);
 					}
 					else{
 						sum += todecode[q] ^ k;
 						newstr += (char) (todecode[q] ^ k);
 					}
 				}

 				cout << i << " " << j << " " << k << "\n" <<newstr << "\n";
 				cout << sum << "\n";

 	//		}
 	//	}
 	//}

 	//myfile2.close();

	return 0;
}


/*
Save file as vector array

use XOR and append each converted character to a string - converting all of them
regex search the string for words like "the", "project", "euler", "congrats", "xor", "decrypt", "password"
if regex search comes up with something, output code and output string to file



*/