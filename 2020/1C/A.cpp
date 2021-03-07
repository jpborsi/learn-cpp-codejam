#include <iostream>
#include <string>

using namespace std;

void solve(int X, int Y, string M){
	int count = 0;
	for(char c : M){
		if(abs(X)+abs(Y) <= count){
			cout << count << endl;
			return;
		}
		if(c == 'S'){
			Y--;
		}else if(c == 'W'){
			X--;
		}else if(c == 'N'){
			Y++;
		}else if(c == 'E'){
			X++;
		}
		count++;
	}
	if(abs(X)+abs(Y) <= count){
		cout << count << endl;
	}else{
		cout << "IMPOSSIBLE" << endl;
	}
	return;

}

int main(){
	int T, X, Y;
	string M;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> X >> Y;
		cin >> M;
		cout << "Case #" << i << ": ";
		solve(X, Y, M);
	}
}