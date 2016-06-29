// 2013 Qualification Round, Problem 1
// Tic-Tac-Toe-Tomek
// https://code.google.com/codejam/contest/2270488

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow.
Each test case consists of 4 lines with 4 characters each, with each character being 'X', 'O', '.' or 'T' (quotes for clarity only).
Each test case is followed by an empty line.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is one of the statuses given above. 
Make sure to get the statuses exactly right. 
When you run your code on the sample input, it should create the sample output exactly, including the "Case #1: ", the capital letter "O" rather than the number "0", and so on.
*/

#include <iostream>

using namespace std;

int getGameState(char board[4][4]){
	return 0;
}

int main(){
	int T;
	char board[4][4];
	cin >> T;
	for(int i = 1; i <= T; i++){
		for(int j = 0; j<4; j++){cin >> board[j];}
		cout << "Case #" << i << ": ";
		switch(getGameState(board)){
			case 0: cout << "Game has not completed" << endl; break;
			case 1: cout << "Draw" << endl; break;
			case 2: cout << "X won" << endl; break;
			case 3: cout << "O won" << endl; break;
		}
	}
	return 0;
}