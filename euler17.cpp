/*first nine: one, two, three, four, five, six, seven, eight, nine = 3 + 3 + 5 + 4 + 4 + 3 + 5 + 5 + 4 = 36
ten through 19 = ten, eleven, twelve, thirteen, fourteen, fifteen, sixteen, seventeen, eighteen, nineteen = 70
twenties: 6*10+36
thirties: thirty = 6, 6*10+36
forties: forty = 5, 5*10+36
fifties: fifty= 5, 5*10+36
sixties: sixty= 5, 5*10+36
seventies: seventy = 7, 7*10+36
eighties: eighty = 6, 6*10+36
nineties: ninety = 6, 6*10+36
***first 99 total: xxx
one hundreds: one hundred = 10, 10 + 13*99 + xxx
two hundreds: 10 + 13*99 + xxx
three hundreds: 12 + 15*99 + xxx
four hundreds: 11 + 14*99 + xxx
five hundreds: 11 + 14*99 + xxx
six hundreds: 10 + 13*99 + xxx
seven hundreds: 12 + 15*99 + xxx
eight hundreds: 12 + 15*99 + xxx
nine hundreds: 11 + 14*99 + xxx
***100-999 total: yyy
***one thousand: 11 
total: xxx + yyy + 11*/

#include <iostream>

using namespace std;

int main(){

	long xxx = 36 + 70 + 6*10+36 +6*10+36 + 5*10+36 + 5*10+36 +5*10+36 +7*10+36 + 6*10+36 +6*10+36;
	long yyy =  10 + 13*99 + xxx +10 + 13*99 + xxx +12 + 15*99 + xxx + 11 + 14*99 + xxx + 11 + 14*99 + xxx + 10 + 13*99 + xxx + 12 + 15*99 + xxx+ 12 + 15*99 + xxx+11 + 14*99 + xxx;
	cout << xxx + yyy +11 << endl;

	return 0;
}