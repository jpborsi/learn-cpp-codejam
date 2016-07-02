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
#include <cmath>

using namespace std;

bool isLightOn(int N, int K){
	//cout << pow(2,N) << endl;
	//cout << (K - pow(2,N) - 1) << endl;
	if(K < pow(2,N) - 1){ return false;}
	return (K - (int)pow(2,N) + 1) % ((int)pow(2,N)) == 0;
}

int main(){
	int T, N, K;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> K;
		cout << "Case #" << i << ": ";
		if(isLightOn(N,K)){
			cout << "ON" << endl;
		}
		else{
			cout << "OFF" << endl;
		}
	}
	return 0;
}