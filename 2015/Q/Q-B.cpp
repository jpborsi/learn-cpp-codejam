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

//Not a valid solution

#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <cmath>
using namespace std;

int numberOfMinutes(int* array, int D){
	sort(array, array+D, greater<int>());
	int numMinutes = 0;
	int greatest_stack = array[0];
	int threshold = ceil(1.0*greatest_stack/2);
	int numOfStacksToFlip = 0;
	for(int i = 0; i < D; ++i){
		if(greatest_stack <= 3){
			numMinutes += greatest_stack;
			return numMinutes;
		}else if(array[i] > threshold){
			numOfStacksToFlip += 1;
		}else{
			if(numOfStacksToFlip >= threshold){
				return numMinutes + greatest_stack;
			}else{
				numMinutes += numOfStacksToFlip;
				greatest_stack = threshold;
				threshold = ceil(1.0*threshold/2);
				numOfStacksToFlip = numOfStacksToFlip*2;
				if(array[i] > threshold){numOfStacksToFlip++;}
			}
		}

	}
	while(true){
		if(numOfStacksToFlip >= threshold || greatest_stack <= 3){
			return numMinutes + greatest_stack;
		}else{
			numMinutes += numOfStacksToFlip;
			greatest_stack = threshold;
			threshold = ceil(1.0*threshold/2);
			numOfStacksToFlip = numOfStacksToFlip*2;
		}
	}

	return numMinutes;
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