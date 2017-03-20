//2012 Qualification Round, Problem 2
//Dancing with the Googlers
//code.google.com/codejam/contest/1460488

/*
Input
The first line of the input gives the number of test cases, T. T test cases follow. 
Each test case consists of a single line containing integers separated by single spaces. 
The first integer will be N, the number of Googlers, and the second integer will be S, 
the number of surprising triplets of scores. The third integer will be p, as described above. 
Next will be N integers ti: the total points of the Googlers.

Output:
For each test case, output one line containing "Case #x: y", 
where x is the case number (starting from 1) and y is the maximum number of Googlers 
who could have had a best result of greater than or equal to p.
*/

#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int getNumberOfGooglers(int totalGooglers, int surprisingTriplets, int scoreThreshold, int* scores){
	int numberOfSweetDancers = 0;
	int numberOfSurprisingDancers = 0;
	for(int i = 0; i < totalGooglers; i++){
		int thisScore = scores[i];
		if(thisScore == 0 && scoreThreshold != 0){}
		else if(thisScore >= scoreThreshold * 3 - 2){
			numberOfSweetDancers++;
		}else if(thisScore >= scoreThreshold * 3 - 4){
			numberOfSurprisingDancers++;
		}
	}
	return numberOfSweetDancers + min(numberOfSurprisingDancers, surprisingTriplets);
}

int main(){
	int T, N, S, P;
	int* scores = (int*)malloc(100*sizeof(int));
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> S >> P;
		for(int j = 0; j < N; j++){
			cin >> scores[j];
		}
		cout << "Case #" << i << ": " << getNumberOfGooglers(N,S,P,scores) << endl;
	}
}