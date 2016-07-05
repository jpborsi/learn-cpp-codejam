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

int getMatches(string pattern, string* language, int L, int D){
	int numMatches = 0;
	for (int i = 0; i < D; ++i){
		int wordPos = 0;
		for(int j = 0; j < pattern.length(); ++j){
			if(pattern[j] == '('){
				bool matchSubPattern = false;
				while(pattern[++j]!=')'){
					if(pattern[j]==language[i][wordPos]){matchSubPattern = true;}
				}
				if(!matchSubPattern){break;}
			}else{
				if(pattern[j]!=language[i][wordPos]){break;}
			}
			if(++wordPos==L){numMatches++;}
		}
	}
	return numMatches;
}

int main(){
	int L, D, N;
	cin >> L >> D >> N;
	string language[D];
	for(int i = 0; i < D; i++){
		cin >> language[i];
	}
	for(int i = 1; i <= N; i++){
		string pattern;
		cin >> pattern;
		cout << "Case #" << i << ": " << getMatches(pattern, language, L, D) << endl;
	}
}