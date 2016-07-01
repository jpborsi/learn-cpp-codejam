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
#include <stdlib.h>

using namespace std;

int getGameState(char* board[4]){
	int Xwin = (1<<11)-1, Owin = (1<<11)-1, fill = 0;
	int Xt = 0, Ot = 0;
	for(int i=0;i<4;i++){
		int m = 1;
		for(int j=0;j<4;j++){
			//cout << i << "," << j << endl;
			Xt += m*1*(board[i][j] == 'X' || board[i][j] == 'T');
			Xt += m*2*(board[j][i] == 'X' || board[i][j] == 'T');
			Ot += m*1*(board[i][j] == 'O' || board[i][j] == 'T');
			Ot += m*2*(board[i][j] == 'O' || board[i][j] == 'T');
			fill |= (board[i][j]=='.');
			m *= 2;
		}
		Xt += m*1*(board[i][i] == 'X' || board[i][i] == 'T');
		Xt += m*2*(board[3-i][3-i] == 'X' || board[3-i][3-i] == 'T');
		Ot += m*1*(board[i][i] == 'O' || board[i][i] == 'T');
		Ot += m*2*(board[3-i][3-i] == 'O' || board[3-i][3-i] == 'T');
		Xwin &= Xt;
		Owin &= Ot;
		cout << Xt << "," << Xwin << endl;
	}

	if(Xwin>0){return 2;}
	if(Owin>0){return 3;}
	if(!fill){return 1;}
	return 0;
}

int main(){
	int T;
	char* board[4];
	cin >> T;
	for(int i = 1; i <= T; i++){
		for(int j = 0; j<4; j++){
			board[j] = (char*) malloc(4*sizeof(char));
			cin >> board[j];
		}
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