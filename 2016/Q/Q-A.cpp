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

//#include "stdafx.h"
#include <iostream>

int getLastNumber(int N) {
	return 0;
}

int main()
{
	using namespace std;
	int T, N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << "Case " << i << ": " << getLastNumber(N) << endl;
	}
}