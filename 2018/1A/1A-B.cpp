//2018 Round 1A, Problem B
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

class Cashier{
	long M; long S; long P;
public:
	Cashier(long mi, long si, long pi){
		M = mi;
		S = si;
		P = pi;
	}
	Cashier(){
		M = 0;
		S = 0;
		P = 0;
	}
	bool isValid(long b){ return b <= M; }
	long long int time(long b){ return S*b + P; }
	long maxHandled(long long int time){
		long long int served = (time-P)/S;
		if( served > M){ return M;}
		else if( served < 0){ return 0;}
		else{return served;}
	}
};

bool isPossible(int R, long B, int C, Cashier *cashiers, long long int time){
	vector<long> possibleBitsHandled;
	for(int i = 0; i<C; i++){
		possibleBitsHandled.push_back(cashiers[i].maxHandled(time));
	}
	sort(possibleBitsHandled.begin(),possibleBitsHandled.end());
	reverse(possibleBitsHandled.begin(), possibleBitsHandled.end());
	long bitsHandled = 0;
	int cashiersUsed = min(R,C);
	for(int i = 0; i<cashiersUsed; i++){
		bitsHandled += possibleBitsHandled[i];
	}
	//cout << bitsHandled << " > " << B << " = " << (bitsHandled > B) << endl;
	return bitsHandled >= B;
}

long long int getMinTime(int R, long B, int C, Cashier *cashiers) {
	long long int max = 1152921504606846976;
	//cout << max << endl;
	long long int min = 0;

	for(int i = 0; i<60; i++){
		long long int test = (max + min)/2;
		//cout << min << ", " << max << ", " << test << endl;
		assert(min!=test);
		assert(max!=test);
		if(isPossible(R, B, C, cashiers, test)){
			max = test;
		}else{
			min = test;
		}
		assert(min!=max);
	}
	if(isPossible(R,B,C,cashiers,max)){
		return max;
	}else{
		return min;
	}

	return 0;
}

int main()
{
	int T, R, C;
	long B;
	Cashier cashiers[1000];
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> R >> B >> C;
		for(int j=0; j<C; j++){
			long M,S,P;
			cin >> M >> S >> P;
			cashiers[j] = Cashier(M, S, P);
		}
		cout << "Case #" << i << ": ";
		long long int minTime = getMinTime(R,B,C,cashiers);
		cout << minTime << endl;
	}
	return 0;
}