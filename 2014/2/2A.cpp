//2014 Round 2, Problem A
//Data Packing

#include <iostream>
#include <algorithm>

using namespace std;

int solve(int N, int X, int* S){
	int first = 0, last = N-1;
	int count = 0;
	sort(S, S+N);
	reverse(S, S+N);
	//cout << N << endl;
	//for(int i=0;i<N;i++){cout << S[i] << endl;}
	while(first<last){
		if(S[first]+S[last] <= X){
			last--;
		}
		count++;
		first++;
	}
	if(first == last){
		count++;
	}
	return count;
}

int main(){
	int T, N, X;
	int S[10000];
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> N >> X;
		for(int j=0; j<N; ++j){
			cin >> S[j];
		}
		int disks = solve(N,X,S);
		cout << "Case #" << i << ": " << disks << endl;
	}
}