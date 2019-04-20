#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
#include <iterator>
#include <tuple>

using namespace std;

void outputJumps(int R, int C, int Roffset, int Coffset){
	
	deque<vector<pair<int, int>>> queue;
	for(int r=0; r<R; r++){
		for(int c= 0; c<C; c++){
			vector<pair<int,int>> initial;
			initial.push_back(make_pair(r,c));
			queue.push_back(initial);
		}
	}
	
	while(!queue.empty()){
		vector<pair<int, int>> current_chain = queue.front();
		queue.pop_front();
		for(int r = 0; r<R; r++){
			for(int c = 0; c<C; c++){
				if(current_chain.size() == R*C){
					cout << "POSSIBLE" << endl;
					for(int i=0;i<R*C;i++){
						cout << get<0>(current_chain[i])+Roffset << " " << get<1>(current_chain[i])+Coffset << endl;
					}
					return;
				}
				if(find(begin(current_chain),end(current_chain),make_pair(r,c)) != end(current_chain)){
					continue;
				}
				int r_prev, c_prev;
				tie(r_prev, c_prev) = current_chain.back();
				if(r == r_prev){ continue; }
				if(c == c_prev){ continue; }
				if(r-c == r_prev - c_prev){ continue; }
				if(r+c == r_prev + c_prev){ continue; }
				vector<pair<int, int>> new_chain(current_chain);
				new_chain.push_back(make_pair(r, c));
				queue.push_front(new_chain);
			}
		}
	}
	cout << "IMPOSSIBLE" << endl;
}

int main()
{
	int T, R, C;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> R >> C;
		cout << "Case #" << i << ": ";
		outputJumps(R, C, 1, 1);
	}
	return 0;
}