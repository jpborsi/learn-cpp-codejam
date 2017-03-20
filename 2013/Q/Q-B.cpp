//2013 Qualification Round, Problem 2
//Lawnmower
//code.google.com/codejam/contest/2270488

/*
Input: The first line of the input gives the number of test cases, T.
T test cases follow. Each test case begins with a line containing two integers: N and M.
Next follow N lines, with the ith line containing M integers ai,j each,
the number ai,j describing the desired height of the grass in the jth square of the ith row.

Output: For each test case, output one line containing "Case #x: y",
where x is the case number (starting from 1) and y is either the word "YES" 
if it's possible to get the x-th pattern using the lawnmower, or "NO", 
if it's impossible (quotes for clarity only).
*/

#include <iostream>
#include "boost/multi_array.hpp"

using namespace std;

typedef boost::multi_array<int, 2> array_type;
typedef array_type::index mi;

int* getRowMax(array_type a, const int N, const int M){
	int* result = (int*)malloc(N*sizeof(int));
	for(mi i = 0; i < N; i++){
		int max = 0;
		for(mi j = 0; j < M; j++){
			int val = a[i][j];
			if(val > max){
				max = val;
			}
		}
		result[i] = max;
	}
	return result;
}

int* getColMax(array_type a, const int N, const int M){
	int* result = (int*)malloc(M*sizeof(int));
	for(mi i = 0; i < M; i++){
		int max = 0;
		for(mi j = 0; j< N; j++){
			int val = a[j][i];
			if(val > max){
				max = val;
			}
		}
		result[i] = max;
	}
	return result;
}

bool isPossible(array_type a, const int N, const int M){
	int* rowmaxes = getRowMax(a,N,M);
	int* colmaxes = getColMax(a,N,M);
	for(mi i = 0; i < N; i++){
		for(mi j = 0; j < M; j++){
			int val = a[i][j];
			if(val < rowmaxes[i] && val < colmaxes[j]){
				return false;
			}
		}
	}
	free(rowmaxes);
	free(colmaxes);
	return true;
}

// void printArray(int* a, int N, int M){
// 	for(int i = 0; i < N; i++){
// 		for(int j = 0; j < M; j++){
// 			cout << a[M*i + j] << " ";
// 		}
// 		cout << endl;
// 	}
// }

int main(){
	int T, N, M;
	cin >> T;
	//int* a = (int*)malloc(100*100*sizeof(int));
	for(int i = 1; i <= T; i++){
		cin >> N >> M;
		array_type A(boost::extents[N][M]);
		for(mi j = 0; j < N; j++){
			for(mi k = 0; k < M; k++){
				cin >> A[j][k];
			}
		}
		if(i==3){
			//printArray(a, N, M);
		}
		cout << "Case #" << i << ": ";
		if(isPossible(A,N,M)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}