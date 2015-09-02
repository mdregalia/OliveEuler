#ifndef BIGNUM_H
#define BIGNUM_H
#include <vector>

using namespace std;

class Bignum{


public:
	vector<int> nums;
	//stored in reverse order, smallest digit first

	Bignum(int); //one digit only
	Bignum();
	~Bignum();
	Bignum addnum(Bignum);
	Bignum multnum(Bignum); //however many digits
	void printnum();
	Bignum expon(int);

};

#endif