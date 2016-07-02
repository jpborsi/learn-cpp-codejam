// 2011 Qualification Round, Problem 1
// Bot Trust
// https://code.google.com/codejam/contest/975485

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow.

Each test case consists of a single line beginning with a positive integer N, representing the number of buttons that need to be pressed.
This is followed by N terms of the form "Ri Pi" where Ri is a robot color (always 'O' or 'B'), and Pi is a button position.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1)
and y is the minimum number of seconds required for the robots to push the given buttons, in order.
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

int getMinSeconds(char* R, int* P, int N){
	int currentLocation[2] = {1,1};
	int timeSince[2] = {0,0};
	int totalTime = 0;
	for(int i = 0; i < N; i++){
		int color = (R[i]=='B');
		int distance = abs(P[i] - currentLocation[color]);
		if(timeSince[color] > distance){
			currentLocation[color] = P[i];
			timeSince[color] = 0;
			timeSince[1-color]++;
			totalTime++;
		}else{
			int t = distance - timeSince[color];
			currentLocation[color] = P[i];
			timeSince[color] = 0;
			timeSince[1-color] += 1+t;
			totalTime += 1+t;
		}
	}
	return totalTime;
}

int main(){
	int T, N;
	char* R;
	int* P;
	cin >> T;
	for(int i = 1; i<= T; i++){
		cin >> N;
		R = new char[N];
		P = new int[N];
		for(int j = 0; j<N; j++){
			cin >> R[j] >> P[j];
		}
		cout << "Case #" << i << ": " << getMinSeconds(R,P,N) << endl;
	}
}