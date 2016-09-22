#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

#define DIGITS 10
#define GOAL 5

using namespace std;

unordered_map<string, unsigned long long> permutenum;
unordered_map<string, unsigned long long> mincube;
vector<string> potentialwinners, emptyvec; //learn stupid empty function!!!!
int maxcount = 0;
string codestring = "";
int lowest;


void calccubes(unsigned long long&, unsigned long long&);
void makehashstring(unsigned long long);

int main(){
	unsigned long long int cubei = 2;
	unsigned long long int cubeend = 100;

	while(true){
		calccubes(cubeend,cubei);
		if (potentialwinners.size() > 0){ //if there are cubes > 5
			unsigned long long mincubeint = 0;
			int test = 0;
			test = mincubeint -= 1; // try to get the largest int - does this work? //also does the double assignment work here too?
			for (int i = 0; i < potentialwinners.size(); i++){
				if (permutenum[potentialwinners[i]] == GOAL && mincube[potentialwinners[i]] < mincubeint){
					mincubeint = mincube[potentialwinners[i]];
					cout << i << " " << potentialwinners[i] << " " << mincube[potentialwinners[i]] << "\n";
				}
			}
			if (mincubeint == test){ //none are 5, all are at 6 or more
				potentialwinners = emptyvec;
			}
			else{
				cout << mincubeint << "\n";
				break;
			}
		}

		cout << cubeend << "\n";
		//break;


	}

	return 0;
}


void calccubes(unsigned long long &upto,unsigned long long &cuberoot){ //controls cubing and keeping track of the next things to cube
	cout << upto << " "<<cuberoot << "\n";
	unsigned long long temp = upto * upto * upto;
	cout << temp << "\n";
	for (unsigned long long int i = cuberoot; i < upto; i++){
		unsigned long long int value = i*i*i;
		makehashstring(value);
		if (cuberoot % 1000 > 100){
			cout << cuberoot << "\n";
		}
	}

	cuberoot = upto;
	upto *= 10;

}

void makehashstring(unsigned long long cubein){ //constructs it into a string
	//prep number of each
	vector<int> howmanyofeach;
	unsigned long long cubedividing = cubein;
	for (int i = 0; i < DIGITS; i++){
		howmanyofeach.push_back(0);
	}

	//get the number of each digit
	while (cubedividing > 0){
		int temp = cubedividing % DIGITS;
		cubedividing /= DIGITS;
		howmanyofeach[temp]++;
	}

	//now make a string TODO
	string permstr = "";
	for (int i = 0; i < DIGITS; i++){
		stringstream ss;
		string hashkey;
		ss << howmanyofeach[i];
		hashkey = ss.str();
		hashkey = (char) (i+48) + hashkey + "-";
		permstr += hashkey;
	}
	
	//keep track of it
	if (permutenum.count(permstr)){ //does this add this to the array???? what does this do
		//cout << "HERE" << "\n";
		permutenum[permstr]++;
	}
	else{
		//cout << "NOT" << "\n";
		permutenum[permstr] = 1;
		mincube[permstr] = cubein;
	}
	if (permutenum[permstr] == GOAL){
		potentialwinners.push_back(permstr);
		//cout << permstr << "\n";
		//cout << cubein << "\n";
	}
	if (permutenum[permstr] >= GOAL){
		cout << permstr << "\n";
	}

	//cout << permstr << "\n";


}


/*ideas
finite 10 digits - some number of each of those digits
unique 
hashmap of constructed strings to keep track of permutations
corresponding hashmap that holds smallest cube - or make a double/tuple class instead of a hash
*/


