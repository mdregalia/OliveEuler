#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void copyarray(string & B, int begin, int end, string & A){
	for (int k = begin; k < end; k++){
		A[k] = B[k];
	}
	//cout << A << "\n";
}

void topdownmerge(string & A, int begin, int middle, int end, string & B){
	int i0 = begin, i1 = middle;

	for (int j = begin; j < end; j++){
		if (i0 < middle && (i1 >= end || A[i0] <= A[i1])){
			B[j] = A[i0];
			//B += A[i0];
			i0 = i0 + 1;
		}
		else{
			B[j] = A[i1];
			//B += A[i1];
			i1 = i1 + 1;
		}
	}
	//cout << B << "\n";
	//return B;
}

void realmerge(string & A,int begin, int end, string & B){
	if (end - begin < 2){
		return;
	}
	int middle = (begin + end) / 2;
	realmerge(A, begin, middle, B);
	//cout << B << "\n";
	realmerge(A, middle, end, B);
	//cout << B << "\n";
	topdownmerge(A, begin, middle, end, B);
	//cout << B << "\n";
	copyarray(B, begin, end, A);
	//A = B;
	//cout << A << "\n";
}

void mergesort(string & A){
	string B = "AAAAAAAAAAAAA";
	realmerge(A,0,A.length(),B);
}

//void copyarray()


int main(){

	for (int i = 100; i < 10000000; i++){
		stringstream ss;
		string firstint;

		ss << i;
		firstint = ss.str();
		int valid = 1;
		//valid will become 0 if not valid
		//sort firstint here
		mergesort(firstint);
		//cout << firstint <<"\n";
		
		for (int j = 2; j < 7; j++){
			stringstream ssnew;
			string multint;
			ssnew << i*j;
			multint = ssnew.str();

			mergesort(multint);

			if (multint.compare(firstint) != 0){
				valid = 0;
			}


		}

		if (valid == 1){
			cout << "Solution: " << i <<"\n";
			break;
		}
	}

	return 0;
}