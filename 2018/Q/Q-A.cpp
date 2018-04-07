#include <iostream>
#include <string>
#include <math.h>
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
	for(int i = 0; i < 30; i++){
		int maxJ = 0;
		for(int j = 0; j < P.size(); j++){
			if(shotStrength[j]>0){
				maxJ = j;
			}
		}
		shotStrength[maxJ]--;
		totalDamage -= pow(2, maxJ-1);
		minHacks++;
		if(totalDamage <= D){ return minHacks; }
	}
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