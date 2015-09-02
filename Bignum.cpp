#include <iostream>
#include <vector>

#include "bignum.h"

using namespace std;

Bignum::Bignum(int digit){ //only defined for one digit
	while (digit > 0){
		nums.push_back(digit % 10);
		digit /= 10;
	}
}

Bignum::Bignum(){
	return;
}

Bignum::~Bignum(){
	return;
}

Bignum Bignum::addnum(Bignum othernum){

	//cout << "ADDING\n";

	Bignum newnum;
	int carry = 0;

	Bignum longer;
	Bignum shorter;

	if (othernum.nums.size() < nums.size()){
		longer.nums = nums;
		shorter.nums = othernum.nums;
	}
	else{
		longer.nums = othernum.nums;
		shorter.nums = nums;
	}
	
	for(int i = 0; i < longer.nums.size(); i++){
		if (i < shorter.nums.size()){

			//cout << othernum.nums[i] << " " << nums[i] << carry << "\n";

			int temp = longer.nums[i] + shorter.nums[i] + carry;

			//cout << temp << "\n";

			carry = temp/10;
			temp = temp % 10;
			newnum.nums.push_back(temp);
		}
		else{
			int temp = carry + longer.nums[i];
			carry = temp/10;
			temp = temp % 10;
			newnum.nums.push_back(temp);
		}
	}
	/*for (int i = othernum.nums.size(); i < nums.size() - othernum.nums.size(); i++){
		int temp = carry + nums[i];
		carry = temp/10;
		temp = temp % 10;
		newnum.nums.push_back(temp);
	}*/

	if (carry > 0){
		newnum.nums.push_back(carry);
	}

	return newnum;

}

Bignum Bignum::multnum(Bignum mult){
	
	Bignum lastnum;

	for (int i = 0; i < mult.nums.size(); i++){
    	
    	Bignum newnum;
        int carry = 0;
 
        for (int j = 0; j < i; j++){
            newnum.nums.push_back(0); //pad with enough zeros
        }

 		for (int j = 0; j < nums.size(); j++){
            int temp = nums[j]*mult.nums[i] + carry;
            carry = temp/10;
            newnum.nums.push_back(temp % 10);
        }
 
        if (carry > 0){
        	newnum.nums.push_back(carry);
    	}
 
        lastnum = lastnum.addnum(newnum);
    }
 
    return lastnum;
}

void Bignum::printnum(){
	for (int i = nums.size() - 1 ; i >= 0; i--){
		cout << nums[i];
	}

	return;
}

Bignum Bignum::expon(int expy){
	Bignum a;
	a.nums = nums;

	for (int i = 0; i < expy - 1; i++){
		a = a.multnum(*this);
	}

	//this->printnum();
	/*cout << "^" << expy << " ";
	a.printnum();
	cout << "\n";*/

	return a;
}





