#include <iostream>

using namespace std;

void solve(int A, int B){
	for(int i=-10; i<=10; ++i){
		for(int j=-10; j<=10; ++j){
			cout << i << " " << j << endl;
			string s;
			cin >> s;
			if(s == "CENTER"){return;}
		}
	}

}

int main(){
	int T, A, B;
	cin >> T >> A >> B;
	for(int i=1; i<=T; ++i){
		solve(A,B);
	}
	return 0;
}