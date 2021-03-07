#include <iostream>
#include <algorithm>
#include <map>
#include <tuple>

typedef long long int ll;

using namespace std;

void solve(ll D, string P){
	map<ll, int> damages;
	ll currentDamage = 1;
	ll totalDamage = 0;
	int numShots = 0;
	for(char c : P){
		if(c=='C'){
			currentDamage *= 2;
		}else{
			numShots++;
			damages[currentDamage]++;
			totalDamage += currentDamage;
		}
	}

	if(numShots>D){
		cout << "IMPOSSIBLE"; return;
	}else if (totalDamage<=D){
		cout << "0"; return;
	}

	int numHacks = 0;
	while(totalDamage > D){
		ll max = damages.rbegin()->first;
		totalDamage -= max/2;
		damages[max]--;
		damages[max/2]++;
		if(damages[max]==0){damages.erase(max);}
		numHacks++;
	}
	cout << numHacks;
	return;
	
}

int main(){
	int T;
	ll D;
	string P;
	cin >> T;
	for(int q=1; q<=T; ++q){
		cin >> D >> P;
		cout << "Case #" << q << ": ";
		solve(D, P);
		cout << endl;
	}
}