#ifndef PRIME_H
#define PRIME_H

#include <unordered_map>
#include <vector>

using namespace std;

class Prime{
public:
	int largest;
	vector<long> orderedprimes;

	void generateupto(long); //generates up to the prime or number of a certain value
	void generatexprimes(long); // generates up to a certain number of primes
	long checkifprime(long); //for user to call to see if a certain number is called
	int isprime(long);
	Prime();
	~Prime();

private:
	unordered_map<long, int> primemap;

};

#endif