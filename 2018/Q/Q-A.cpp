#include <iostream>
#include <string>
#include <math.h>
#include <assert.h>
using namespace std;

int getMinHacks(long D, string P) {
	int shotStrength [30] = {};
	int numShots = 0;
	int numCharges = 0;
	long totalDamage = 0;
	long currentStrength = 1;
	for(int i = 0; i < P.size(); i++){
		if(P[i] == 'C'){
			currentStrength *= 2;
			numCharges++;
		}else{
			shotStrength[numCharges]++;
			numShots++;
			totalDamage += currentStrength;
		}
	}
	if(numShots > D){ return -1; }
	else if(totalDamage <= D){ return 0; }

	int minHacks = 0;
	for(int i = 0; i < numShots*numCharges; i++){
		int maxJ = 0;
		for(int j = 0; j <= numCharges; j++){
			if(shotStrength[j]>0){
				maxJ = j;
			}
		}
		assert(maxJ > 0);
		shotStrength[maxJ]--;
		shotStrength[maxJ-1]++;
		int strengthDiff = 1 << (maxJ-1);
		totalDamage -= strengthDiff;
		minHacks++;
		if(totalDamage <= D){ return minHacks; }
	}
	assert(false);
	return -1;
}

int main()
{
	int T;
	long D;
	string P;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> D;
		cin >> P;
		cout << "Case #" << i << ": ";
		int minHacks = getMinHacks(D,P);
		if(minHacks==-1){cout << "IMPOSSIBLE" << endl;}
		else{cout << minHacks << endl;}
	}
	return 0;
}