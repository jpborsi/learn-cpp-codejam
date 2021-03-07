#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <cassert>

using namespace std;

void solve(int U){
	string Q, R;
	map<char, int> results;
	set<char> notzero;
	set<char> allchars;
	for(int j=0; j<10000; ++j){
		cin >> Q >> R;
		results[R[0]]++;
		notzero.insert(R[0]);
		for(char C: R){ allchars.insert(C);}
	}
	vector<pair<int, char>> v;
	for(pair<char, int> kv : results){
		v.push_back(make_pair(kv.second, kv.first));
	}
	sort(v.begin(), v.end());
	string x = "";
	for(char C: allchars){
		if(notzero.find(C) == notzero.end()){
			x += C;
		}
	}
	x += v[8].second;
	x += v[7].second;
	x += v[6].second;
	x += v[5].second;
	x += v[4].second;
	x += v[3].second;
	x += v[2].second;
	x += v[1].second;
	x += v[0].second;
	cout << x << endl;
	return;
}

int main(){
	int T, U;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> U;
		cout << "Case #" << i << ": ";
		solve(U);
	}
}