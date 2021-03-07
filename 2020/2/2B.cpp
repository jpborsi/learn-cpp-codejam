#include <iostream>
#include <utility>

using namespace std;

int COMPUTERS[101];
pair<int, int> LINKS[1000];

void solve(int C, int D){
	for(int i=0;i<D;++i){
		int c1 = LINKS[i].first;
		int c2 = LINKS[i].second;
		int t1 = COMPUTERS[c1];
		int t2 = COMPUTERS[c2];
		//cout << c1 << " " << c2 << " " << t1 << " " << t2 << ": ";
		int latency = max(abs(t2-t1),1);
		cout << latency << " ";
	}
	cout << endl;

}

int main(){
	int T, C, D, U, V, X;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> C >> D;
		for(int j=2;j<=C;++j){
			cin >> X;
			COMPUTERS[j] = X;
		}
		for(int j=0;j<D;++j){
			cin >> U >> V;
			LINKS[j] = make_pair(U,V);
		}
		cout << "Case #" << i << ": ";
		solve(C, D);
	}
}