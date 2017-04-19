//2015 Round 1-A, Problem A
//Mushroom Monster
//code.google.com/codejam/contest/4224486

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each will consist of one line containing a single integer N, followed by a line containing N space-separated integers mi; the number of mushrooms on Kaylin's plate at the start, and at 10-second intervals.
*/

/*
Output: For each test case, output one line containing "Case #x: y z", where x is the test case number (starting from 1), y is the minimum number of mushrooms Kaylin could have eaten using the first method of computation, and z is the minimum number of mushrooms Kaylin could have eaten using the second method of computation.
*/

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int getY(int N, int* array){
	int sum = 0;
	for(int i = 0; i < N - 1; i++){
		sum += max(array[i] - array[i+1],0);
	}
	return sum;
}

int getZ(int N, int* array){
	int max = 0;
	for(int i = 0; i < N - 1; i++){
		int test = array[i] - array[i+1];
		if(test > max){
			max = test;
		}
	}
	int sum = 0;
	for(int i = 0; i < N - 1; i++){
		int test = array[i];
		if(test < max){
			sum += test;
		}else{
			sum += max;
		}
	}
	return sum;
}

int main(){
	int T, N;
	int array [ 1000];
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> array[j];
		}
		cout << "Case #" << i << ": " << getY(N, array) << " " << getZ(N, array) << endl;
	}
}