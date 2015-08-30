#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int samesuit(char *suitarray, int start){
	int p = 1;
	char match = suitarray[start];
	for (int i = 1 + start; i < 5 + start; i++){
		if (suitarray[i] != match){
			p = 0;
		}
	}

	return p;
}

int samestraight(int *nums, int start){
	int p = 1;
	int prev = nums[start];
	for (int i = 1 + start; i < 5 + start; i++){
		if (nums[i] != prev + 1){
			p = 0;
		}
		prev = nums[i];
	}

	return p;
}

//all hands return 1 for player 1, 2 for player 2, or 0 for neither
int straightflush(int *numarray, char *suitarray){
	int p1 = 0;
	int p2 = 0;
	int maxp1 = 0;
	int maxp2 = 0;

	if (samestraight(numarray,0) && samesuit(suitarray,0)){
		p1 = 1;
		maxp1 = numarray[4];
	}
	if (samestraight(numarray,5) && samesuit(suitarray,5)){
		p2 = 1;
		maxp1 = numarray[9];
	}
	if (p1 && p2){
		if (maxp1 < maxp2){
			return 2;
		}
		else{
			return 1;
		}
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	else{
		return 0;
	}
}

int fourofakind(int *numarray){
	int p1 = 0;
	int p2 = 0;
	int fourp1 = 0;
	int fourp2 = 0;
	int single1 = 0;
	int single2 = 0;

	int prev = 0;
	for (int i = 0; i < 2; i++){
		//for p1
		int tempp1 = 1;
		for (int j = 1; j < 5; j++){
			prev = numarray[j - 1];
			if (numarray[j] != prev){
				tempp1 = 0;
			}
		}
		if (tempp1 == 1){
			if (i == 0){
				single1 = numarray[4];
			}
			else{
				single1 = numarray[0];
			}
			fourp1 = numarray[i];
			p1 = 1;
		}

		//for p2
		int offset = 5;
		int tempp2 = 1;
		for (int j = 1 + offset; j < 5 + offset; j++){
			prev = numarray[j - 1];
			if (numarray[j] != prev){
				tempp2 = 0;
			}
		}
		if (tempp2 == 1){
			if (i == 0){
				single2 = numarray[4+offset];
			}
			else{
				single2 = numarray[0+offset];
			}
			fourp1 = numarray[i+offset];
			p2 = 1;
		}
	}

	if (p1 && p2){
		if (fourp1 > fourp2){
			return 1;
		}
		else if (fourp2 > fourp1){
			return 2;
		}
		else{
			if (single1 > single2){
				return 1;
			}
			else{
				return 2;
			}
		}
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	else{
		return 0;
	}
}

int fullhouse(int *numarray){
	//if it's a full house it's going to have three at the beginning, and two at the end
	int p1 = 0;
	int p2 = 0;
	int p1three = 0;
	int p2three = 0;
	int p1two = 0;
	int p2two = 0;

	if (numarray[0] == numarray[1] && numarray[0] == numarray[2] && numarray[3] == numarray[4]){
		p1 = 1;
		p1three = numarray[0];
		p1two = numarray[4];
	}
	else if (numarray[0] == numarray[1] && numarray[2] == numarray[3] && numarray[3] == numarray[4]){
		p1 = 1;
		p1three = numarray[4];
		p1two = numarray[0];
	}

	if (numarray[5] == numarray[6] && numarray[5] == numarray[7] && numarray[8] == numarray[9]){
		p2 = 1;
		p2three = numarray[5];
		p2two = numarray[8];
	}
	else if (numarray[5] == numarray[6] && numarray[7] == numarray[8] && numarray[7] == numarray[9]){
		p2 = 1;
		p2three = numarray[8];
		p2two = numarray[5];
	}

	if (p2 && p1){
		if (p2three > p1three){
			return 2;
		}
		else if (p1three > p2three){
			return 1;
		}
		else{
			if (p1two > p2two){
				return 1;
			}
			else{
				return 2;
			}
		}
	}
	else{
		return 0;
	}
}

int flush(char * suitarray, int * numarray){
	int p1 = 0;
	int p2 = 0;

	if (samesuit(suitarray, 0)){
		p1 = 1;
	}
	if (samesuit(suitarray, 0)){
		p2 = 1;
	}

	if (p1 && p2){
		for (int i = 4; i >= 0; i--){
			if (suitarray[i] < suitarray[i + 5]){
				return 2;
			}
			else if (suitarray[i] > suitarray[i + 5]){
				return 1;
			}
		}
		return 1;
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	else{
		return 0;
	}
}

int straight(int * numarray){
	int p1 = 0;
	int p2 = 0;

	p1 = samestraight(numarray,0);
	p2 = samestraight(numarray,5);

	if (p1 && p2){
		if (numarray[4] < numarray[9]){
			return 2;
		}
		else{
			return 1;
		}
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	//else{
		return 0;

}

int threeofakind(int * numarray){
	int p1 = 0;
	int p2 = 0;
	int p1a[3];
	int p2a[3];

	//for p1
	for (int i = 0; i < 3; i++){
		int threetry1 = numarray[i];
		int found1 = 1;

		int threetry2 = numarray[i + 5];
		int found2 = 1;		

		for (int j = 1; j < 3; j++){
			if (numarray[ j + i ] != threetry1){
				found1 = 0;
			}

			if (numarray[ j + i + 5] != threetry2){
				found2 = 0;
			}
		}

		if (found1 == 1){ //if there is a three of a kind at that row for p1
			p1 = 1;
			p1a[0] = threetry1;
			int place = 1;

			for (int j = 4; j >= 0; j-- ){
				if (numarray[j] != threetry1){
					p1a[place] = numarray[j];
					place++;
				}
			}
		}

		if (found2 == 1){ //if there is a three of a kind for that row for p2
			p2 = 1;
			p2a[0] = threetry2;
			int place = 1;

			for (int j = 4; j >= 0; j-- ){
				if (numarray[j + 5] != threetry2){
					p2a[place] = numarray[j + 5];
					place++;
				}
			}
		}
	}

	if (p1 && p2){
		for (int i = 0; i < 3; i++){ //no ties guaranteed in the question
			if (p1a[i] > p2a[i]){
				return 1;
			}
			if (p1a[i] < p2a[i]){
				return 2;
			}
		}
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	//else{
		return 0;
	//}
}

int twopair(int * numarray){
	int p1 = 0;
	int p2 = 0;
	int p1a[3];
	int p2a[3];

	if (numarray[4] == numarray[3] && numarray[2] == numarray[1]){
		p1a[0] = numarray[4];
		p1a[1] = numarray[2];
		p1a[2] = numarray[0];
		p1 = 1;
	}
	if (numarray[4] == numarray[3] && numarray[0] == numarray[1]){
		p1a[0] = numarray[4];
		p1a[1] = numarray[0];
		p1a[2] = numarray[2];
		p1 = 1;
	}
	if (numarray[2] == numarray[3] && numarray[0] == numarray[1]){
		p1a[0] = numarray[2];
		p1a[1] = numarray[0];
		p1a[2] = numarray[4];
		p1 = 1;
	}

	if (numarray[4 + 5] == numarray[3 + 5] && numarray[2 + 5] == numarray[1 + 5]){
		p2a[0] = numarray[4 + 5];
		p2a[1] = numarray[2 + 5];
		p2a[2] = numarray[0 + 5];
		p2 = 1;
	}
	if (numarray[4 + 5] == numarray[3 + 5] && numarray[0 + 5] == numarray[1 + 5]){
		p2a[0] = numarray[4 + 5];
		p2a[1] = numarray[0 + 5];
		p2a[2] = numarray[2 + 5];
		p2 = 1;
	}
	if (numarray[2 + 5] == numarray[3 + 5] && numarray[0 + 5] == numarray[1 + 5]){
		p2a[0] = numarray[2 + 5];
		p2a[1] = numarray[0 + 5];
		p2a[2] = numarray[4 + 5];
		p2 = 1;
	}

	if (p1 && p2){
		for (int i = 0; i < 3; i++){
			if (p1a[i] > p2a[i]){
				return 1;
			}
			if (p1a[i] < p2a[i]){
				return 2;
			}
		}
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	
	return 0;

}

int onepair(int * numarray){
	int p1 = 0;
	int p2 = 0;
	int p1a[4];
	int p2a[4];

	//for p1
	for (int i = 0; i < 4; i++){
		int threetry1 = numarray[i];
		int found1 = 1;

		int threetry2 = numarray[i + 5];
		int found2 = 1;		

		for (int j = 1; j < 2; j++){
			if (numarray[ j + i ] != threetry1){
				found1 = 0;
			}

			if (numarray[ j + i + 5] != threetry2){
				found2 = 0;
			}
		}

		if (found1 == 1){ //if there is a three of a kind at that row for p1
			p1 = 1;
			p1a[0] = threetry1;
			int place = 1;

			for (int j = 4; j >= 0; j-- ){
				if (numarray[j] != threetry1){
					p1a[place] = numarray[j];
					place++;
				}
			}
		}

		if (found2 == 1){ //if there is a three of a kind for that row for p2
			p2 = 1;
			p2a[0] = threetry2;
			int place = 6;

			for (int j = 4; j >= 0; j-- ){
				if (numarray[j + 5] != threetry2){
					p2a[place] = numarray[j + 5];
					place++;
				}
			}
		}
	}

	if (p1 && p2){
		for (int i = 0; i < 4; i++){ //no ties guaranteed in the question
			if (p1a[i] > p2a[i]){
				return 1;
			}
			if (p1a[i] < p2a[i]){
				return 2;
			}
		}
	}
	else if (p1){
		return 1;
	}
	else if (p2){
		return 2;
	}
	//else{
		return 0;
	//}
}

int nopair(int * numarray){
	for (int i = 4; i >= 0; i-- ){
		if (numarray[i] > numarray[i + 5]){
			return 1;
		}
		else if (numarray[i] < numarray[i + 5]){
			return 2;
		}
	}
	return 0; //to shut up the warnings, this should never happen in program
}



void merge(int *numarray, char *suitarray, int start, int end){
	int il = start;
	int middle = (end + start) / 2;
	int ir = middle;
	int temp[10];
	int tempsuit[10];

	for (int i = start; i < end; i++){
		//cout << "i " << i << " " << numarray[il] << " " << numarray[ir] << "\n";
		if ((ir >= end || numarray[il] <= numarray[ir]) && il < middle){
			temp[i] = numarray[il];
			tempsuit[i] = suitarray[il];
			il++;
		}
		else{
			temp[i] = numarray[ir];
			tempsuit[i] = suitarray[ir];
			ir++;
		}
	}
	//copy back to array
	for (int i = start; i < end; i++){
		numarray[i] = temp[i];
		suitarray[i] = tempsuit[i];
	}
}

void partition(int *numarray, char *suits, int start, int end){ //exclusive of end
	//basecase
	if (end - start <= 1){
		return;
	}
	//other cases, inclusive of end
	//cout << "start: " << start << "end: "<< end << "\n";
	int middle = (end + start)/2;
	partition(numarray,suits,start,middle);
	partition(numarray,suits,middle,end);
	merge(numarray,suits,start,end);
	//for (int i = start; i < end; i++){
		//cout << numarray[i] <<" ";
	//}
	//cout << "\n";
}

int main(){
	
	char suit[10];
	int number[10];

	int countp1 = 0;

	int sets = 0;

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
					number [ (i / 3) ] = 10;
				}
				//cout << suit[i/3] <<" "<< number[i/3] << "\n";
			}

			//now we must sort the array
			partition(number,suit,0,5);
			partition(number,suit,5,10);
			/*for (int k = 0; k < 10; k++){
				cout << number[k] << suit[k] << " ";
			}*/
			//cout << "\n";

			sets++;

			//if (sets > 30){
			//	break;
			//}


			int result;

			result = straightflush(number,suit);
			if (result == 1){
				//cout << "P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Straight Flush\n";
				continue;
			}

			result = fourofakind(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Four of a Kind\n";
				continue;
			}

			result = fullhouse(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Fullhouse\n";
				continue;
			}

			result = flush(suit,number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Flush\n";
				continue;
			}

			result = straight(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Straight\n";
				continue;
			}

			result = threeofakind(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Three of a kind\n";
				continue;
			}

			result = twopair(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Two pair\n";
				continue;
			}

			result = onepair(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "Pair\n";
				continue;
			}

			result = nopair(number);
			if (result == 1){
				//cout <<"P1 ";
				countp1++;
			}
			if (result != 0){
				//cout << "No Pair\n";
				continue;
			}
		}
	}

	pokerfile.close();

	cout << countp1 <<"\n";

	return 0;

}