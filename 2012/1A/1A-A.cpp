//2012 Round 1A, Problem A
//Password Problem
//code.google.com/codejam/contest/1645485/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a line containing two integers, A and B. A is the number of characters that I have already typed, and B is the total number of characters in my password.

This is followed by a line containing A real numbers: p1, p2, ..., pA. pi represents the probability that I correctly typed the ith letter in my password. These real numbers will consist of decimal digits and at most one decimal point. The decimal point will never be the first or the last character in a number.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the expected number of additional keystrokes I need, not counting the letters I have typed so far, and assuming I choose the optimal strategy. y must be correct to within an absolute or relative error of 10-6.
*/

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

char* getKeys(int A, int B, vector<double> prob){
	int justFingRetypeIt = B+2;
	int lettersLeft = B-A+1;
	double bestSolution = justFingRetypeIt;
	double probCorrect = 1;
	for(int i = 0; i < A; i++){
		int keystrokes = lettersLeft + 2*(A-i);
		if(keystrokes > justFingRetypeIt){
			probCorrect *= prob[i];
			continue;
		}
		double thisSolution = probCorrect*keystrokes + (1-probCorrect)*(keystrokes+justFingRetypeIt-1);
		//cout << thisSolution << " " << probCorrect << " " << keystrokes << endl ;
		if(thisSolution < bestSolution){
			bestSolution = thisSolution;
		}
		probCorrect *= prob[i];
	}
	double thisSolution = probCorrect*lettersLeft + (1-probCorrect)*(lettersLeft+justFingRetypeIt-1);
	//cout << thisSolution << " " << probCorrect << " " << lettersLeft << endl ;
	if(thisSolution < bestSolution){
		bestSolution = thisSolution;
	}
	char* result = (char*)malloc(15*sizeof(char));
	sprintf(result,"%.6f",bestSolution);
	return result;
}

int main(){
	int T, A, B;
	vector<double> prob;
	prob.reserve(100000);
	cin >> T;
	for(int i = 1; i<= T; i++){
		cin >> A >> B;
		prob.clear();
		for(int j = 0; j < A; j++){
			double temp;
			cin >> temp;
			prob.push_back(temp);
		}
		cout << "Case #" << i << ": " << getKeys(A, B, prob) << endl;
	}
}