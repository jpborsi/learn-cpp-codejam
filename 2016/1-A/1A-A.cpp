//2016 Round 1-A, Problem A
//The Last Word
//code.google.com/codejam/contest/4304486

/*
Input:
The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with a string S.
*/

/*
Output:
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the winning last word, as described in the statement.
*/

#include <iostream>
#include <string>

using namespace std;

string getLastWord(string s){
	string result = s.substr(0,1);
	for(int i = 1; i < s.size(); i++){
		if(s[i] >= result[0]){
			result = s[i] + result;
		}else{
			result += s[i];
		}
	}
	return result;
}

int main(){
	int T;
	string s;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> s;
		cout << "Case #" << i << ": " << getLastWord(s) << endl;
	}
}