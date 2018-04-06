#include <iostream>
#include <string>
using namespace std;

int getMinFlips(string s, int K) {
	int numPancakes = s.size();
	int numFlips = 0;
	for(int i = 0; i < numPancakes-K+1; i++){
		if (s[i] == '-'){
			numFlips++;
			for(int j = 0; j < K; j++){
				if(s[i+j] == '-'){
					s[i+j] = '+';
				}else{
					s[i+j] = '-';
				}
			}
		}
	}
	for(int i = 0; i < numPancakes; i++){
		if (s[i] == '-'){ return -1; }
	}
	return numFlips;
}

int main()
{
	int T, K;
	string s;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> s;
		cin >> K;
		cout << "Case #" << i << ": ";
		int minFlips = getMinFlips(s,K);
		if(minFlips==-1){cout << "IMPOSSIBLE" << endl;}
		else{cout << minFlips << endl;}
	}
	return 0;
}