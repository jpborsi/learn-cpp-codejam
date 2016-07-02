// 2010 Qualification Round, Problem 1
// Snapper Chain
// code.google.com/codejam/contest/433101

/*
Input: The first line of the input gives the number of test cases, T. T lines follow. Each one contains two integers, N and K.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) 
and y is either "ON" or "OFF", indicating the state of the light bulb.
*/

#include <iostream>

using namespace std;

int isLightOn(int N, int K){
	return 0;
}

int main(){
	int T;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> K;
		cout << "Case #" << i << ": ";
		switch(isLightOn(N,K)){
			case 0: cout << "OFF" << endl; break;
			case 1: cout << "ON" << endl; break;
		}
	}
	return 0;
}