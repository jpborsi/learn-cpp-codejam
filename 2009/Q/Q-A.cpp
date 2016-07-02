// 2009 Qualification Round, Problem 1
// Alien Language
// code.google.com/codejam/contest/90101

/*
Input: The first line of input contains 3 integers, L, D and N separated by a space. D lines follow, each containing one word of length L. 
These are the words that are known to exist in the alien language. N test cases then follow, each on its own line and each consisting of a pattern as described above. 
You may assume that all known words provided are unique.
*/

/*
Output: For each test case, output Case #X: K
where X is the test case number, starting from 1, and K indicates how many words in the alien language match the pattern.
*/

#include <iostream>
#include <stdlib.h>

using namespace std;

int getMatches(char* pattern, char** language){
	return 0;
}

int main(){
	int L, D, N;
	cin >> L >> D >> N;
	char language[D][L];
	for(int i = 0; i < D; i++){
		cin >> language[i];
	}
	for(int i = 1; i <= N; i++){
		char* pattern = (char*) malloc(L*28*sizeof(char));
		cin >> pattern;
		cout << "Case #" << i << ": " << getMatches(pattern, language) << endl;
	}
}