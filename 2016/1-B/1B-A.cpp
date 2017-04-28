//2016 Round 1B, Problem A
//Getting the Digits
//https://code.google.com/codejam/contest/11254486/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each consists of one line with a string S of uppercase English letters.
*/

/*
Output: For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is a string of digits: the phone number.
*/

#include <iostream>
#include <string>

using namespace std;

int occurrencesOf(char c, string s){
	int n = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i]==c){
			n++;
		}
	}
	return n;
}

string getPhoneNumber(string s){
	int n0 = occurrencesOf('Z',s);
	int n2 = occurrencesOf('W',s);
	int n4 = occurrencesOf('U',s);
	int n6 = occurrencesOf('X',s);
	int n8 = occurrencesOf('G',s);
	int n5 = occurrencesOf('F',s) - n4;
	int n7 = occurrencesOf('V',s) - n5;
	int n9 = occurrencesOf('I',s) - n5 - n6 - n8;
	int n1 = occurrencesOf('O',s) - n2 - n4 - n0;
	int n3 = occurrencesOf('H',s) - n8;
	string r = "";
	for(int i = 0; i < n0; i++){
		r+= "0";
	}
	for(int i = 0; i < n1; i++){
		r+= "1";
	}
	for(int i = 0; i < n2; i++){
		r+= "2";
	}
	for(int i = 0; i < n3; i++){
		r+= "3";
	}
	for(int i = 0; i < n4; i++){
		r+= "4";
	}
	for(int i = 0; i < n5; i++){
		r+= "5";
	}
	for(int i = 0; i < n6; i++){
		r+= "6";
	}
	for(int i = 0; i < n7; i++){
		r+= "7";
	}
	for(int i = 0; i < n8; i++){
		r+= "8";
	}
	for(int i = 0; i < n9; i++){
		r+= "9";
	}
	return r;
}

int main(){
	int T;
	string s;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> s;
		cout << "Case #" << i << ": " << getPhoneNumber(s) << endl;
	}
}