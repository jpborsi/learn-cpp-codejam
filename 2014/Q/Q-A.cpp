// 2014 Qualification Round, Problem 1
// Magic Trick
// https://code.google.com/codejam/contest/2974486

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. 
Each test case starts with a line containing an integer: the answer to the first question. 
The next 4 lines represent the first arrangement of the cards: each contains 4 integers, separated by a single space. 
The next line contains the answer to the second question, and the following four lines contain the second arrangement in the same format.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1).

If there is a single card the volunteer could have chosen, y should be the number on the card.
If there are multiple cards the volunteer could have chosen, y should be "Bad magician!", without the quotes.
If there are no cards consistent with the volunteer's answers, y should be "Volunteer cheated!", without the quotes.
*/

#include <iostream>
using namespace std;

int getNumberOnCard(int a1, int a2, int m1[4][4], int m2[4][4]){
	int* row1 = m1[a1-1];
	int* row2 = m2[a2-1];
	int numPossible = 0, lastPossibleCard;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++){
			if(row1[i]==row2[j]){
				numPossible++;
				lastPossibleCard = row1[i];
			}
		}
	}
	switch(numPossible){
		case 0: return -2;
		case 1: return lastPossibleCard;
		default: return -1;
	}
}

int main(){
	int T, a1, a2;
	int m1[4][4], m2[4][4];
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> a1;
		for(int j = 0; j < 4; j++){for(int k = 0; k < 4; k++){cin >> m1[j][k];}}
		cin >> a2;
		for(int j = 0; j < 4; j++){for(int k = 0; k < 4; k++){cin >> m2[j][k];}}
		cout << "Case #" << i << ": ";
		int r = getNumberOnCard(a1,a2,m1,m2);
		switch(r){
			case -1: cout << "Bad magician!" << endl;
				break;
			case -2: cout << "Volunteer cheated!" << endl;
				break;
			default: cout << r << endl;
				break;
		}
	}
	return 0;
}