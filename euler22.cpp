#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

//need to make alphabetical

using namespace std;

bool mysort(string a, string b){
	if(a.compare(b) < 0){
		return true;
	}
	else{
		return false;
	}
}

int main(){

	ifstream myfile;
	string myname;
	unsigned long mainsum = 0;

	vector<string> names;

	myfile.open("p022_names.txt");

	int namepos = 1; //does it start at one or zero?

	while(getline(myfile, myname, ',')){
		myname = myname.substr(1, myname.size() - 2);
		//now we have the name, have to figure out where it is
		names.push_back(myname);
	}

	sort(names.begin(), names.end(), mysort);

	//need to sort here


	for (int i = 0; i < names.size(); i++){
		
		string myname = names[i];

		long unsigned namesum = 0;

		for(int i = 0; i < myname.size(); i++){
			namesum += myname[i] - 64;
		}

		cout << namesum << "\n";

		mainsum += namesum * namepos;

		namepos++;
	}




	cout << mainsum << '\n';
	myfile.close();

	return 0;
}

