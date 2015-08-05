#include <iostream>
#include <fstream>
#include <string>

//for all card layers, 1 means player 1, 2 means player 2, 0 means neither

int straightflush(int * onecardnum, int * twocardnum, int * onesuits, int * twosuits){
	bool suits1 = true;
	bool suits2 = true;

	bool cards1 = true;
	bool cards2 = true;

	int s1 = onesuits[0];
	int s2 = twosuits[0];

	for (int i = 1; i < 5; i++){
		if (onesuits[i] != s1){
			suits1 = false;
		}
		if (twosuits[i] != s2){
			suits2 = false;
		}
	}

	for (int i = 1; i < 5){
		if (onecardnum[i] != onecardnum[i - 1] + 1){
			cards1 = false;
		}
		if (twocardnum[i] != twocardnum[i - 1] + 1){
			cards2 = false;
		}
	}

	if (suits1 && suits2 && cards1 && cards2){
		if (onecardnum[4] > twocardnum[4]){
			return 1;
		}
		else{
			return 2;
		}
	}
	else if (suits1 && cards1){
		return 1;
	}
	else if (suits2 && cards2){
		return 2;
	}
	else{
		return 0;
	}
}

int fourofakind(int * onecardnum, int * twocardnum){

	int c10 = onecardnum[0];
	int c11 = onecardnum[4];
	int c10count = 0;
	int c11count = 0;

	int c20 = twocardnum[0];
	int c21 = twocardnum[4];
	int c20count = 0;
	int c21count = 0;

	for (int i = 0; i < 5; i++){
		if (onecardnum[i] == c10){
			c10count++;
		}
		else if (onecardnum[i] == c11){
			c11count++;
		}

		if (twocardnum[i] == c20){
			c20count++;
		}
		else if (twocardnum[i] == c21){
			c21count++;
		}
	}

	if (c10count == 4){
		if (c20count == 4){
			if (c10 > c20){
				return 1;
			}
			else{
				return 2;
			}
		}
		if (c21count == 4){
			if (c10 > c21){
				return 1;
			}
			else{
				return 2;
			}
		}
		else{
			return 1;
		}
	}

	else if (c11count == 4){
		if (c20count == 4){
			if (c11 > c20){
				return 1;
			}
			else{
				return 2;
			}
		}
		if (c21count == 4){
			if (c11 > c21){
				return 1;
			}
			else{
				return 2;
			}
		}
		else{
			return 1;
		}
	}
	else if (c20count == 4){
		return 2;
	}
	else if (c21count == 4){
		return 2;
	}
	else{
		return 0;
	}
}

int fullhouse(int * onecardnum, int * twocardnum){ //verify
	int c10 = onecardnum[0];
	int c11 = onecardnum[4];
	int c10count = 0;
	int c11count = 0;

	int c20 = twocardnum[0];
	int c21 = twocardnum[4];
	int c20count = 0;
	int c21count = 0;

	for (int i = 0; i < 5; i++){
		if (onecardnum[i] == c10){
			c10count++;
		}
		else if (onecardnum[i] == c11){
			c11count++;
		}

		if (twocardnum[i] == c20){
			c20count++;
		}
		else if (twocardnum[i] == c21){
			c21count++;
		}
	}

	if (c10count + c11count == 5){
		if (c20count + c21count == 5){
			if (c10count == 3 && c20count == 3){
				if (c10 > c20){
					return 1;
				}
				else{
					return 2;
				}
			}
			if (c10count == 3 && c21count == 3){
				if (c10 > c21){
					return 1;
				}
				else{
					return 2;
				}

			}
			if (c11count == 3 && c20count == 3){
				if (c11 > c20){
					return 1;
				}
				else{
					return 2;
				}

			}
			if (c11count == 3 && c21count == 3){
				if (c11 > c21){
					return 1;
				}
				else{
					return 2;
				}

			}
		}
		else{
			return 1;
		}


	}
	else if (c20count + c21count == 5){
		return 2;
	}
	else{
		return 0;
	}

}

int flush(int * onecardnum, int * twocardnum, int * onesuits, int * twosuits){
	int s1 = onesuits[0];
	int s2 = twosuits[0];
	bool s1bool = true;
	bool s2bool = true;

	for (int i = 1; i < 5; i++){
		if (onesuits[i] != s1){
			s1bool = false;
		}
		if (twosuits[i] != s1){
			s2bool = false;
		}
	}

	if (s1bool && s2bool){
		for(int i = 4; i >= 0; i--){
			if (onecardnum[i] > twocardnum[i]){
				return 1;
			}
			else if (twocardnum[i] > onecardnum[i]){
				return 2;
			}
		}

	}
	else if (s1bool){
		return 1;

	}
	else if (s2bool){
		return 2;
	}
	else{
		return 0;
	}

}

int straight(int * onecardnum, int * twocardnum){
	bool c1 = true;
	bool c2 = true;

	for(int i = 1; i < 5; i++){
		if (onecardnum[i] != onecardnum[i-1] + 1){
			c1 = false;
		}
		if (twocardnum[i] != twocardnum[i-1] + 1){
			c2 = false;
		}
	}
	if (c1 && c2){
		if (onecardnum[0] > twocardnum[1]){
			return 1;
		}
		else{
			return 2;
		}
	}
	else if (c1){
		return 1;
	}
	else if (c2){
		return 2;
	}
	else{
		return 0;
	}
}

int threeofakind(int * onecardnum, int * twocardnum){
	//because it's sorted there should be three in a row

	bool found1 = false;
	bool found2 = false;
	int f1num = 0;
	int f2num = 0;

	for (int i = 0; i < 3; i ++){
		int s1 = onecardnum[i];
		int s2 = twocardnum[i];
		bool three1 = true;
		bool three2 = true;

		for(int j = i + 1; j < 3 + i; j++ ){
			if (onecardnum[j] != s1 ){
				three1 = false;
			}
			if (twocardnum[j] != s2 ){
				three2 = false;
			}
		}

		if ( three1 == true){
			f1num = onecardnum[i];
			found1 = true;
		}

		if ( three2 == true){
			f2num = twocardnum[i];
			found2 = true;
		}

	}

	//now if statement for returning

	/*int s1[3];
	s1[0] = onecardnum[0];
	s1[1] = onecardnum[1];
	s1[2] = onecardnum[2];

	int s1count[3] = {0, 0, 0};

	int s2[3];
	s2[0] = twocardnum[0];
	s2[1] = twocardnum[1];
	s2[2] = twocardnum[2];

	int s2count[3] = {0, 0, 0};

	for (int i = 0; i < 5; i++){
		for (int j = 0; j < 3; j++){
			if (onecardnum[i] == s1[j]){
				s1cound[j]++;
			}
			if (twocardnum[i] == s2[j]){
				s2cound[j]++;
			}
		}
	}

	bool found1 = false;
	bool found2 = false;

	for(int )

	//search for a set of three
	//compare pair, then compare highest
	*/
}

int twopair(){

}

int onepair(){

}



int winner(string cardline){
	//set up hand arrays
	//p1 has a card number array, and a suit array
	//p2 has both arrays as well
	//sort both according to order of card array

	//13 levels, check both at each level, if one is at the level and not the other a winner is formed
	//if at same level look at high card or pair or whatever

	int winner = straightflush();
	if (winner != 0){
		return winner;
	}

	winner = fourofakind();
	if (winner != 0){
		return winner;
	}


	//


}

int main(){

	int player1 = 0;
	int player2 - 0;

	ifstream myfile("p054_poker.txt");
	string line;

	if (myfile){
		while (getline(myfile,line)){

		}
	}
}