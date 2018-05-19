//2017 Round 2, Problem A
//Fresh Chocolate

#include <iostream>
#include <cmath>

using namespace std;


int freshChoc(int P, int N, int* G){
	int modCounts[4] = {};
	for(int i=0; i<N; i++){
		modCounts[G[i]%P]++;
	}
	if(P==2){
		return modCounts[0] + ceil(1.0*(N-modCounts[0])/2);
	}else if(P==3){
		int big = max(modCounts[1],modCounts[2]);
		int small = min(modCounts[1],modCounts[2]);
		return modCounts[0] + small + ceil(1.0*(big-small)/3);
	}else{
		int big = max(modCounts[1],modCounts[3]);
		int small = min(modCounts[1],modCounts[3]);
		int leftover = 0;
		if(modCounts[2]%2!=0){
			if(big-small>1){
				big -= 2;
			}else if(big!=small){
				leftover--;
			}
		}
		leftover += ceil(1.0*(big-small)/4);
		return modCounts[0] + ceil(1.0*modCounts[2]/2) + small + leftover;
	}
}

int main(){
	int T, P, N;
	int G[100] = {};
	cin >> T;
	for(int i=1; i<=T; i++){
		cin >> N >> P;
		for(int j=0; j<N; j++){
			cin >> G[j];
		}
		cout << "Case #" << i << ": " << freshChoc(P, N, G) << endl;
	}
}