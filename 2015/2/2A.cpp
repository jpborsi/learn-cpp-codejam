//2015 Round 2, Problem A
//Pegman

#include <iostream>
#include <vector>

#ifdef DEBUG
#define debug(x) cout << x << endl
#else
#define debug(x) {}
#define NDEBUG
#endif
#include <cassert>

#define IMPOSSIBLE "IMPOSSIBLE"

using namespace std;

int solve(int R, int C, char map[][100]){
	vector<int> singleCharRows, singleCharColumns;
	int neededSwaps = 0;
	for(int i=0; i<R; i++){
		int first,last;
		for(int j=0; j<C; j++){
			if(map[i][j] != '.'){
				neededSwaps += (map[i][j]=='<');
				first = j;
				j=C;
			}
		}
		for(int j=C-1; j>=0; j--){
			if(map[i][j] != '.'){
				neededSwaps += (map[i][j]=='>');
				last = j;
				j=-1;
			}
		}
		if(first == last){
			singleCharRows.push_back(i);
		}
	}
	for(int i=0; i<C; i++){
		int first,last;
		for(int j=0; j<R; j++){
			if(map[j][i] != '.'){
				neededSwaps += (map[j][i]=='^');
				first = j;
				j=R;
			}
		}
		for(int j=R-1; j>=0; j--){
			if(map[j][i] != '.'){
				neededSwaps += (map[j][i]=='v');
				last = j;
				j=-1;
			}
		}
		if(first == last){
			singleCharColumns.push_back(i);
		}
	}
	for(int r : singleCharRows){
		for(int c: singleCharColumns){
			if(map[r][c]!='.'){
				return -1;
			}
		}
	}
	return neededSwaps;
}

int main(){
	int T, R, C;
	char map[100][100];
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> R >> C;
		for(int j=0; j<R; ++j){
			string line;
			cin >> line;
			for(int k=0; k<C; ++k){
				map[j][k] = line[k];
			}
		}
		cout << "Case #" << i << ": ";
		int result = solve(R,C,map);
		if(result==-1){ cout << IMPOSSIBLE << endl;}
		else{ cout << result << endl;}
	}
}