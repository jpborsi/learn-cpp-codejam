// 2015 Qualification Round, Problem 1
// Standing Ovation
// https://code.google.com/codejam/contest/6224486

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. 
Each consists of one line with Smax, the maximum shyness level of the shyest person in the audience, followed by a string of Smax + 1 single digits. 
The kth digit of this string (counting starting from 0) represents how many people in the audience have shyness level k. 
For example, the string "409" would mean that there were four audience members with Si = 0 and nine audience members with Si = 2 (and none with Si = 1 or any other value). 
Note that there will initially always be between 0 and 9 people with each shyness level.

The string will never end in a 0. Note that this implies that there will always be at least one person in the audience.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum number of friends you must invite.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int numberOfFriends(int Smax, char* S){
	int sum = 0, shyness = 0, maxDif = 0;
	for(shyness; shyness <= Smax; shyness++){
		maxDif = max(maxDif,shyness-sum);
		sum += *S++ - '0';	
	}
	return maxDif;
}

int main() {
	int T, Smax;
	char* S = (char*) malloc(1001*sizeof(char));
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> Smax >> S;
		cout << "Case #" << i << ": " << numberOfFriends(Smax,S) << endl;
	}
	return 0;
}