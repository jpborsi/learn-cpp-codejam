#include <iostream>
#include <algorithm>

using namespace std;

long long int SLICES[300];

long long int solve(int N, int D){
	sort(SLICES, SLICES+N);
	for(int i=0; i<N-D; ++i)
	if (D==2){
		for(int i=0; i<N-1; ++i){
			if(SLICES[i] == SLICES[i+1]){return 0;}
		}
		return 1;
	}
	if (D==3){
		for(int i=0; i<N-2; ++i){
			if(SLICES[i] == SLICES[i+1] && SLICES[i] == SLICES[i+2]){return 0;}
		}
		for(int i=0; i<N; ++i){
			for(int j=i+1; j<N; ++j){
				if(2*SLICES[i] == SLICES[j]){ return 1; }
			}
		}
		long long int maxslice = SLICES[N-1];
		for(int i=0; i<N-1; ++i){
			if(SLICES[i] == SLICES[i+1] && SLICES[i] < maxslice){
				return 1;
			}
		}
		return 2;
	}

	return 0;

}

int main(){
	int T, N, D;
	long long int A;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> N >> D;
		if(D > 3) return 1;
		for(int j=0; j<N; ++j){
			cin >> A;
			SLICES[j] = A;
		}
		cout << "Case #" << i << ": " << solve(N, D) << endl;
	}
}