// 2015 Qualification Round, Problem 2
// Infinite House of Pancakes
// code.google.com/codejam/contest/6224486

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow.
Each consists of one line with D, the number of diners with non-empty plates, followed by another
line with D space-separated integers representing the numbers of pancakes on those diners' plates.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1)
and y is the smallest number of minutes needed to finish the breakfast.
*/

#include <iostream>
#include <assert.h>
#include <cmath>
using namespace std;

int numberOfMinutes(int* array, int D){
	int minMinutes = 1001;
	for(int x = 1; x <= 1000; x++){
		int sumMoves = 0;
		for(int i = 0; i < D; i++){
			sumMoves += max(0,int(ceil(1.0*array[i]/x - 1)));
		}
		if(sumMoves + x < minMinutes){
			minMinutes = sumMoves + x;
		}
	}
	assert(minMinutes < 1001);
	return minMinutes;
}

int main() {
	int T, D;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> D;
		int array [D];
		for(int j = 0; j < D; j++){
			cin >> array[j];
		}
		cout << "Case #" << i << ": " << numberOfMinutes(array,D) << endl;
	}
	return 0;
}