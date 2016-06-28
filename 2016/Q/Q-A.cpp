// 2016 Qualification Round, Problem 1
// Counting Sheep
// https://code.google.com/codejam/contest/6254486

/*
Input: The first line of the input gives the number of test cases, T.
T test cases follow. Each consists of one line with a single integer N, the number Bleatrix has chosen.
*/

/*
Output: For each test case, output one line containing Case #x: y,
where x is the test case number (starting from 1) and y is the last number that Bleatrix will name before falling asleep,
according to the rules described in the statement.
*/

//#include "windows.h"
#include <iostream>

int getLastNumber(int N) {
	int m = 0;
	int x = 0;
	do{
		x += N;
		int y = x;
		while(y){
			m |= 1 << (y%10);
			y /= 10;
		}
	}while(m < (1 << 10) - 1);
	return x;
}

int main()
{
	using namespace std;
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << "Case " << i << ": ";
		if(N==0){cout << "INSOMNIA" << endl;}
		else{cout << getLastNumber(N) << endl;}
	}
	return 0;
}