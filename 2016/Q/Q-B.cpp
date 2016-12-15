// 2016 Qualification Round, Problem 2
// Revenge of the Pancakes
// code.google.com/codejam/contest/6254486

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow.
Each consists of one line with a string S, each character of which is either + (which represents a pancake that is initially happy side up)
or - (which represents a pancake that is initially blank side up).
The string, when read left to right, represents the stack when viewed from top to bottom.
*/

/*
Output: For each test case, output one line containing Case #x: y,
where x is the test case number (starting from 1) and y is the minimum number of times
you will need to execute the maneuver to get all the pancakes happy side up.
*/

#include <iostream>

using namespace std;

int flips(bool* array, int N){
	int numFlips = 0;
	bool currentState = array[0];
	for(unsigned i = 1; i < N; ++i){
		if(array[i] != currentState){
			numFlips++;
			currentState = array[i];
		}
	}
	numFlips += currentState;
	return numFlips;
}

int getMinFlips(string S) {
	bool array [S.length()];
	for(unsigned i = 0; i < S.length(); ++i){
		array[i] = (S.at(i) == '-');
	}
	return flips(array, S.length());
}

int main()
{
	int T;
	string S;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> S;
		cout << "Case #" << i << ": " << getMinFlips(S) << endl;
	}
	return 0;
}