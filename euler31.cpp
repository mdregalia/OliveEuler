#include <iostream>

using namespace std;

int main(){

	//200
	int ways = 1;

	int current = 0;
	//100
	for (int i = 0; i <= 2; i++){
		//current = i * 100;
		//50
		for(int j = 0; j <= 4; j++){
			//current += j * 50;
			//20
			for (int k = 0; k <= 10; k++){
				//current += k * 20;
				//10
				for (int l = 0; l <= 20; l++){
					//current += l * 10;
					//5
					for(int m = 0; m <= 40; m++){
						//current += m * 5;
						//2
						for (int n = 0; n <= 100; n++){
							current = n*2 + m*5 + l*10 + k*20 + j*50 + i*100;
							if (current <= 200){
								ways++;
							}
						}
					}
				}
			}
		}
	}

	cout << ways <<"\n";
}