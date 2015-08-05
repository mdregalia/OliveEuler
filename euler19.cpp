#include <iostream>

using namespace std;

int main(){

	int day = 1+365;
	int sundaycount = 0;

	for (int i = 1901; i < 2001; i++){
		// 7 % # = 0 is a sunday

		//jan
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
		//feb
		if ((i % 4 == 0) && ( (!(i % 100 == 0)) || (i % 400 == 0) )){ //divisible by 4, and not the 100 year unless year is divisble by 400
			day += 29;
		}
		else{
			day += 28;
		}
		if (!(day % 7)){
			sundaycount++;
		}
		//mar
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
		//apr
		day += 30;
		if (!(day % 7)){
			sundaycount++;
		}
		//may
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
		//june
		day += 30;
		if (!(day % 7)){
			sundaycount++;
		}
		//july
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
		//aug
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
		//sept
		day += 30;
		if (!(day % 7)){
			sundaycount++;
		}
		//oct
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
		//nov
		day += 30;
		if (!(day % 7)){
			sundaycount++;
		}
		//dec 
		day += 31;
		if (!(day % 7)){
			sundaycount++;
		}
	}
	cout << sundaycount;

}