#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){

	unsigned long long int arr[10];
	int count = 0;
	int stop = 0;

	for (int i = 0; i < 10; i++){
		arr[i] = 1;
	} //fills the array

	for (int i = 1; i < 30; i++){ //represents the digits
		cout << "\n" << i << "\n";
		for (int j = 1; j < 10; j++){
			arr[j] *= j;

			//check digits
			stringstream ss;
			string lenstr;
			ss << arr[j];
			lenstr = ss.str();

			cout << j << " ^ " << i <<" = "<< arr[j] << " len: " << lenstr.length() <<"\n";

			if (lenstr.length() == i){
				count++;
				cout << count << "\n";
			}
			else if (j == 9 && lenstr.length() < i){
				stop = 1;
			}
		}
		if (stop){
			break;
		}
	}

	cout << count << "\n";

	return 0;
}