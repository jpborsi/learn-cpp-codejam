#include <iostream>

using namespace std;

void solve(int N, int K){
	if(K%N!=0){
		cout << "IMPOSSIBLE" << endl;
		return;
	}else{
		cout << "POSSIBLE" << endl;
	}
	int value = K/N;
	for(int i=0; i<N; ++i){
		for(int j=0; j<N; ++j){
			cout << value++ << " ";
			if(value > N){value = 1;}
		}
		cout << endl;
		if(--value == 0){value = N;}
	}
}

int main()
{
	int T, N, K;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> N >> K;
		cout << "Case #" << i << ": ";
		solve(N, K);
	}
	return 0;
}