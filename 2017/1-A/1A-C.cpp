#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int getMinTurns(int HD, int AD, int HK, int AK, int B, int D) {
	int numOfTurnsToKill = min(HK/B+1,HK/AD);
	if(AK*numOfTurnsToKill < HD){
		return numOfTurnsToKill;
	}
	if(AK - D >= HD || 2*AK - 3*D >= HD){
		return -1;
	}
	int numberOfCures = ceil(1.0*numOfTurnsToKill/(HD-AK));
	int numberOfDebuffs = (AK - (HD/numOfTurnsToKill))/D;
	return numOfTurnsToKill + numberOfCures + numberOfDebuffs;
}

int main()
{
	int T, HD, AD, HK, AK, B, D;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> HD >> AD >> HK >> AK >> B >> D;
		cout << "Case #" << i << ": ";
		int minTurns = getMinTurns(HD,AD,HK,AK,B,D);
		if(minTurns==-1){cout << "IMPOSSIBLE" << endl;}
		else{cout << minTurns << endl;}
	}
	return 0;
}