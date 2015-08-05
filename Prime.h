#ifndef PRIME_H
#define PRIME_H

#include <unordered_map>
#include <vector>

using namespace std;

class Prime{
public:
	int largest;
	vector<int> orderedprimes;

	void generateupto(int); //generates up to the prime or number of a certain value
	void generatexprimes(int); // generates up to a certain number of primes
	int checkifprime(int); //for user to call to see if a certain number is called
	int isprime(int);
	Prime();
	~Prime();

private:
	unordered_map<int, int> primemap;

};

#endif