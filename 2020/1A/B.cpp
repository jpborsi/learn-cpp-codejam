#include <iostream>
#include <stack>
#include <utility>
using namespace std;

void solve(int N){
	if(N <= 30){
		for(int i=0; i<N; ++i){
			cout << i+1 << " 1" << endl;
		}
		return;
	}
	N-=30;
	stack<pair<int, int>> moves;
	bool left = true;
	int fullRows = 0;
	for(int row = 30; row > 1; --row){
		int rowSize = (1<<(row-1));
		if(N >= rowSize){
			//cout << row << " " << rowSize+1 << " " << rowSize+1 << endl;
			if(row!=1){
				if(left){
					for(int i=1; i<=row; ++i){
						moves.push(make_pair(row, i));
					}
				}else{
					for(int i=row; i>0; --i){
						moves.push(make_pair(row, i));
					}
				}
				left = !left;
				N -= rowSize;
			}
			fullRows++;
		}else{
			//cout << row << " " << rowSize+1 << " 1"<< endl;
			if(left){
				moves.push(make_pair(row,1));
			}else{
				moves.push(make_pair(row,row));
			}
		}
	}
	if(N>0){fullRows++;}
	moves.push(make_pair(1,1));
	while(!moves.empty()){
		pair<int, int> move = moves.top();
		cout << move.first << " " << move.second << endl;
		moves.pop();
	}
	for (int i = 0; i < fullRows; ++i){
		cout << 31 + i << " 1" << endl;
	}
}

int main()
{
	int T, N;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> N;
		cout << "Case #" << i << ": " << endl;
		solve(N);
	}
	return 0;
}