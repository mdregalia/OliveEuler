#include <iostream>

#define LENGTH 20

using namespace std;

void pathfinder(int, int);

long paths[21];

int main(){
	for (int i = 0; i < 21; i++ ){
		paths[i] = 0;
	}


	pathfinder(LENGTH,LENGTH);

	long sum = 0;

	for (int i = 0; i < 21; i++){
		sum += paths[i]*paths[i];
	}
	//cout << paths*2 <<endl;
	cout<< sum << endl;
	return 0;
}

void pathfinder(int right, int down){
	/*if ((right == 0)&&(down == 0)){
		paths++;
		return;
	}*/
	if (right+down == LENGTH){
		paths[right]++;
		return;
	}
	if (right > 0){
		pathfinder(right-1,down);
	}
	if (down > 0){
		pathfinder(right, down - 1);
	}
}