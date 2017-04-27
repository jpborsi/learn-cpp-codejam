//2013 Round 1A, Problem A
//Bullseye
//code.google.com/codejam/contest/2418487

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a line containing two space separated integers: r and t.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the maximum number of black rings that Maria can draw.
*/

#include <iostream>

using namespace std;

bool canPaint(long long int startingRings, long long int amountOfPaint, long long int possible){
	return amountOfPaint > 2*possible*possible + 4*startingRings*possible + 4*possible;
}

long long int getRings(int R, int P){
	int checkRings = 2;
	while(canPaint(R,P,checkRings)){
		checkRings <<= 1;
	}
	return checkRings;
}

int main(){
	int T, R, P;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> R >> P;
		cout << "Case #" << i << ": " << getRings(R,P) << endl;
	}
}