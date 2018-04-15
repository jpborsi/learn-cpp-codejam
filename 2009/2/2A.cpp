//2009 Round 2, Problem A

#define tc(N) for(int t=1;t<=N;t++)
#define f(i,N) for(int i=0;i<N;i++)

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void swapElements(vector<int> v, int i, int j){
	int tmp = v[i];
	v[i] = v[j];
	v[j] = tmp;
}

bool goodToGo(vector<int> v){
	f(i,v.size()){
		if(v[i] > i) return false;
	}
	return true;
}

int getSwitches(int N, int matrix[][40]){
	vector<int> lastOne(N,0);
	f(i,N){
		int max = 0;
		f(j,N){
			if(matrix[i][j]){
				max = j;
			}
		}
		lastOne[i] = max;
	}
	int switches = 0;
	f(l,N){
		if(goodToGo(lastOne)) return switches;
		//f(i,N){ cout << lastOne[i];}
		//cout << endl;
		int i;
		for(i = 0; lastOne[i] <= i; i++){}
		//cout << i << endl;
		int upper = i;
		for(int j = i+1; lastOne[j] > i; j++){
			upper++;
		}
		//cout << upper << endl;
		for(int j = upper+1; j>i; j--){
			swap(lastOne[j],lastOne[j-1]);
			switches++;
		}
	}
	return switches;
}

int main(){
	int T,N;
	int matrix[40][40];
	cin >> T;
	tc(T){
		cin >> N;
		f(i,N){
			string s;
			cin >> s;
			f(j,N){
				matrix[i][j] = s[j] - '0';
			}
		}
		int switches = getSwitches(N, matrix);
		cout << "Case #" << t << ": " << switches << endl;
	}
	return 0;
}