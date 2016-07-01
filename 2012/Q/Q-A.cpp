// 2012 Qualification Round, Problem 1
// Speaking In Tongues
// https://code.google.com/codejam/contest/1460488

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow, one per line.
Each line consists of a string G in Googlerese, made up of one or more words containing the letters 'a' - 'z'.
There will be exactly one space (' ') character between consecutive words and no spaces at the beginning or at the end of any line.
*/

/*
Output: For each test case, output one line containing "Case #X: S" where X is the case number and S is the string that becomes G in Googlerese.
*/

#include <iostream>
#include <stdlib.h>
#include <cstring>

using namespace std;

const char key[] = "yhesocvxduiglbkrztnwjpfmaq";

string translate(string googlerese){
	string out;
	for(int i = 0; i<googlerese.size(); ++i){
		if (googlerese[i] == ' '){
			out += ' ';
		}else{
			out += key[googlerese[i]-'a'];
		}
	}
	return out;
}

int main(){
	int T;
	string googlerese;
	cin >> T;
	cin.ignore();
	for(int i = 1; i <= T; i++){
		getline(cin,googlerese);
		cout << "Case #" << i << ": " << translate(googlerese) << endl;
	}
	return 0;
}