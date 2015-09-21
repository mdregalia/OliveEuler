
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
 
using namespace std;

int getfirst2digits(int num){
 
    stringstream ss, ss2;
    string digits, digits2 = "00";
    int retint;
             
    ss << num;
    digits = ss.str();
 
    //cout << digits << "\n";
 
    digits2[0] = digits[0];
    digits2[1] = digits[1];
 
    //cout << digits[0] << digits[1] <<"\n";
 
    ss2 << digits2;
    ss2 >> retint;
             
    return retint;
 
}

int getlast2digits(int num){

    stringstream ss, ss2;
    string digits, digits2 = "00";
    int retint;
             
    ss << num;
    digits = ss.str();
 
    //cout << digits << "\n";
 
    digits2[0] = digits[2];
    digits2[1] = digits[3];
 
    //cout << digits[0] << digits[1] <<"\n";
 
    ss2 << digits2;
    ss2 >> retint;
             
    return retint;

}

vector< vector<int> > firsttwo;
vector< vector<int> > figurate;
int levels[6] = {0,0,0,0,0,0}; //is this allowed? holds what type was seen at that level
int sum = 0;
int start;
//other way to do this would be to have it correspond to the right place

int traverse(int digits, int layer){
    //can potentially add a check that it never goes below starting number - add later to speed up
    //assuming no repeats, hence seen
    //layer lags

    if (layer == 5){
        if (getlast2digits(digits) == start){
            sum += digits;
            cout << digits << "\n";
            return 1;
        }
        //else it doesn't match and it wasn't found
        return 0;
    }

    int nextlayer = getlast2digits(digits);
    int imax = firsttwo[nextlayer].size();

    int found = 0;

    for (int i = 0; i < imax; i++){
        int figplace = figurate[nextlayer][i];

        int doub = 0;

        //make sure it's a new type
        for (int j = 0; j <= layer; j++){
            if (levels[j] == figplace){
                doub = 1;
            }
        }

        if (doub == 0){
            levels[layer + 1] = figplace;
            found = traverse(firsttwo[nextlayer][i], layer + 1);
        }

        if (found == 1){
            sum += digits;
            cout << digits << "\n";
            return 1;
        }

    }

    //if it makes it this far, a loop was not found at these levels
    return 0;


}
 
int main(){
 
    //vector< vector<int> > firsttwo;
    //vector< vector<int> > figurate;
 
    for (int i = 0; i < 100; i++){
    	//the first ten won't be used
        vector<int> emptyvec;
        firsttwo.push_back(emptyvec);
        figurate.push_back(emptyvec);
    }
 
 
    //set up figurates in the vector
 
    for (int i = 10; i < 200; i++){ //adds in triangle
        int mynum;
 
        mynum = i * (i + 1) /2;
 
        if (mynum >= 1000 && mynum < 10000){
 			int store;

 			store = getfirst2digits(mynum);
 			firsttwo[store].push_back(mynum);
 			figurate[store].push_back(3);
 
        }
        if (mynum >= 10000){
            break;
        }
    }

    for (int i = 10; i < 200; i++){ //adds in square
        int mynum;
 
        mynum = i * i;
 
        if (mynum >= 1000 && mynum < 10000){
 			int store;

 			store = getfirst2digits(mynum);
 			firsttwo[store].push_back(mynum);
 			figurate[store].push_back(2);
 
        }
        if (mynum >= 10000){
            break;
        }
    }

    for (int i = 10; i < 200; i++){ //adds in pentagonal
        int mynum;
 
        mynum = i * (3*i - 1) /2;
 
        if (mynum >= 1000 && mynum < 10000){
 			int store;

 			store = getfirst2digits(mynum);
 			firsttwo[store].push_back(mynum);
 			figurate[store].push_back(5);
 
        }
        if (mynum >= 10000){
            break;
        }
    }

    for (int i = 10; i < 200; i++){ //adds in hexa
        int mynum;
 
        mynum = i * (2*i - 1);
 
        if (mynum >= 1000 && mynum < 10000){
 			int store;

 			store = getfirst2digits(mynum);
 			firsttwo[store].push_back(mynum);
 			figurate[store].push_back(6);
 
        }
        if (mynum >= 10000){
            break;
        }
    }

    for (int i = 10; i < 200; i++){ //adds in sept
        int mynum;
 
        mynum = i * (5*i - 3) /2;
 
        if (mynum >= 1000 && mynum < 10000){
 			int store;

 			store = getfirst2digits(mynum);
 			firsttwo[store].push_back(mynum);
 			figurate[store].push_back(7);
 
        }
        if (mynum >= 10000){
            break;
        }
    }

    for (int i = 10; i < 200; i++){ //adds in oct
        int mynum;
 
        mynum = i * (3*i - 2);
 
        if (mynum >= 1000 && mynum < 10000){
 			int store;

 			store = getfirst2digits(mynum);
 			firsttwo[store].push_back(mynum);
 			figurate[store].push_back(8);
 
        }
        if (mynum >= 10000){
            break;
        }
    }

    //start off on loop

    int found = 0;
    //int levels[6] = {0,0,0,0,0,0};

    for (int i = 10; i < 100; i++){
        int jmax = firsttwo[i].size();
        for (int j = 0; j < jmax; j++){

            levels[0] = figurate[i][j];
            start = getfirst2digits(firsttwo[i][j]);

            found = traverse(firsttwo[i][j],0);
            
            if (found){
                cout << sum << "\n";

                for (int k = 0; k < 6; k++){
                    cout << levels[k] << "\n";
                }
                break;
            }
        }
        
        if (found){
            break;
        }
    }
 
    return 0;
}
 
 
//use array to keep track if everything has been seen or not from







//make a vector of vectors
//position in the first vector is the front half of the number
//the vectors contained at each position in the first vector hold every number with those first two digits
//theres another vector of vectors that holds correspondingly what type it is
//recursively iterate through list, starting at the beginning of the first one
//don't go into the recursion of something where a type has been seen, like if there's already a square, don't go down that recursion path
//stop when it's six deep, and the last two digits match the first two
//also save the 60 one to github
//start an answer page
