#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <map>
using namespace std;

void printSolution(int R, int C, char* grid) {
	vector<int> emptyRows;
	int firstFullRow = -1;
	int lastFullRow = -1;
	map<int,char> map1;
	for(int i = 0; i < R; i++){
		map1.clear();
		for(int j = 0; j < C; j++){
			if(grid[i*C+j] != '?'){
				map1[j] = grid[i*C+j];
			}
		}
		if(map1.empty()){
			emptyRows.push_back(i);
		}else if(firstFullRow==-1){
			firstFullRow = i;
			lastFullRow = i;
			int j = 0;
			for(auto it = map1.begin(); it != map1.end(); ++it){
				for(int k = j; k < it->first; k++){
					grid[i*C+k] = it->second;
				}
				j = it->first+1;
			}
			for(int k = j; k < C; k++){
				grid[i*C+k] = grid[i*C+j-1];
			}
		}else{
			lastFullRow = i;
			int j = 0;
			for(auto it = map1.begin(); it != map1.end(); ++it){
				for(int k = j; k < it->first; k++){
					grid[i*C+k] = it->second;
				}
				j = it->first+1;
			}
			for(int k = j; k < C; k++){
				grid[i*C+k] = grid[i*C+j-1];
			}
		}
	}
	for(int i = 0; i < emptyRows.size(); i++){
		int row = emptyRows[i];
		if(row < firstFullRow){
			for(int j = 0; j<C; j++){
				grid[row*C+j] = grid[firstFullRow*C+j];
			}
		}
		else if(row > lastFullRow){
			for(int j = 0; j<C; j++){
				grid[row*C+j] = grid[lastFullRow*C+j];
			}
		}else{
			for(int j = 0; j<C; j++){
				grid[row*C+j] = grid[(row-1)*C+j];
			}
		}
	}
	for(int i = 0; i< R; i++){
		for(int j = 0; j< C; j++){
			cout << grid[i*C+j];
		}
		cout << endl;
	}
}

int main()
{
	int T, R, C;
	char *grid = (char*) malloc(25*25*sizeof(char));
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> R >> C;
		string s;
		for(int j = 0; j < R; j++){
			cin >> s;
			for(int k = 0; k < C; k++){
				grid[j*C+k] = s[k];
			}
		}
		cout << "Case #" << i << ": " << endl;
		printSolution(R,C,grid);
	}
	return 0;
}