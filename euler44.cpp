#include <iostream>
#include <vector>
#include <math.h>

#define MEE 10000

using namespace std;

vector <long long> yay; //holds many pentagonal numbers

bool find(long long looking){
	int begin = 0;
	int end = yay.size() - 1;

	//cout << "MEOW\n";

	if (looking == yay[begin]){
		return true;
	}
	if (looking == yay[end]){
		return true;
	}

	if (looking < yay[0]){
		//cout << "1\n";
		return false;
	}

	//cout << end << " " << yay[end] <<"\n";

	if (looking > yay[end]){
		cout << yay[end] << "\n" ;
		//cout << "2\n";
		return false;
	}

	cout << "HERE\n";

	while(begin < end){
		if (begin > end - 1){
			break;
		}
		int mid = (end + begin) / 2;
		//cout << yay[mid] << "\n";
		if (yay[mid] == looking){
			//cout << "found\n";
			return true;
		}
		else if (looking < yay[mid]){
			end = mid;
		}
		else{
			begin = mid; //BE CAREFUL, if you add one then you need to check it
		}
		//cout << begin << " " << end << " " << mid << "\n";
	}
	cout << yay[begin] << " " << yay[end] << "\n";
	return false;
}

bool findroots(double temp){
	double x1;
	double a = 1.5;
	double b = -0.5;
	double c = -1*temp;

	x1 = ((-1)*b + sqrt(b*b - 4*a*c)) / (2*a) ;
	//x2 = ((-1)*b - sqrt(b*b - 4*a*c)) / (2*a) ;
	//cout << sqrt(b*b - 4*a*c) << "\n";
	if (x1 == floor(x1)){
		return true;
	}
	else{
		return false;
	}
}

int main(){

	//vector <long long> yay; //holds many pentagonal numbers
	long long mindiff = 99999999;

	//int i = 1;
	for (long long i = 1; i < MEE; i++){
		yay.push_back(i * (3 * i - 1) / 2);
	}

	//now for the list analysis
	/*for (int i = 0; i < MEE - 2; i++){
		for (int j = i + 1; j < MEE - 1; j++){
			//cout << yay[i] + yay[j] << "\n";
			if (findroots(yay[j] - yay[i])){
				//cout << "level 1" << "\n";
				if (findroots(yay[j] + yay[i])){
					cout << "level 2" << "\n";
					if (yay[j] - yay[i] < mindiff){
						cout << yay[j] + yay[i] << "\n";
						mindiff = yay[j] - yay[i];
					}
				}
			}
		}
	}*/


	cout << find(8602840) << "\n";

	//cout << yay[7] << "\n";

	cout << mindiff << "\n";

	return 0;
}


/*
generate 500 pentagonal numbers
for loop start at one
next for loop start at previous posion +1
find sum and difference
binary search list to find sum and find difference
if sum is the smallest then save it
*/