#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int getFirstError(int N, long* V) {
	vector<long> Veven;
	vector<long> Vodd;
	if(N%2 == 0){
		Veven.resize(N/2);
		Vodd.resize(N/2);
	}else{
		Veven.resize(N/2+1);
		Vodd.resize(N/2);
	}
	for(int i = 0; i < N; i++){
		if(i%2 == 0){
			Veven[i/2] = V[i];
		}else{
			Vodd[i/2] = V[i];
		}
	}
	sort(Veven.begin(),Veven.end());
	sort(Vodd.begin(),Vodd.end());
	for(int i = 0; i < N-1; i++){
		if(i%2 == 0){
			if(Veven[i/2] > Vodd[i/2]){
				return i;
			}
		}else{
			if(Vodd[i/2] > Veven[i/2+1]){
				return i;
			}
		}
	}
	return -1;
}

int main()
{
	int T, N;
	long V [100000] = {};
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for(int j = 0; j < N; j++){
			cin >> V[j];
		}
		cout << "Case #" << i << ": ";
		int firstError = getFirstError(N, V);
		if(firstError==-1){cout << "OK" << endl;}
		else{cout << firstError << endl;}
	}
	return 0;
}