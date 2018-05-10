//2016 Round 2, Problem A
//A Rather Perplexing Showdown

#include <iostream>
#include <string>
#include <tuple>
#include <map>

#ifdef DEBUG
#define debug(x) cout << x << endl
#else
#define debug(x) {}
#endif

#define IMPOSSIBLE "IMPOSSIBLE"

using namespace std;

class PlayerCounts
{
	int rock, paper, scissors;
public:
	PlayerCounts(int R, int P, int S){
		rock = R;
		paper = P;
		scissors = S;
	}
	PlayerCounts(){
		rock = 0; paper = 0; scissors = 0;
	}
	PlayerCounts(string s);
	bool operator== (const PlayerCounts&b) const{
		return rock == b.rock && paper == b.paper && scissors == b.scissors;
	}
	bool operator< (const PlayerCounts &b) const{
		return rock < b.rock ||
			(rock == b.rock && paper < b.paper) ||
			(rock == b.rock && paper == b.paper && scissors < b.scissors); 
	}
	friend ostream& operator<<(ostream &os, const PlayerCounts&b);
};

ostream& operator<<(ostream &os, const PlayerCounts&b){
	return os << b.rock << "," << b.paper << "," << b.scissors;
}

PlayerCounts::PlayerCounts(string s){
	map<char, int> counts;
	for(char c : s){
		counts[c]++;
	}
	rock = counts['R'];
	paper = counts['P'];
	scissors = counts['S'];
}

map<PlayerCounts, string> lookupTable[13];

tuple<string,string,string> update(tuple<string,string,string> old){
	string s1,s2,s3;
	tie(s1,s2,s3) = old;
	return make_tuple(s1+s2, s1+s3, s2+s3);
}

void init(){
	string s1("P"), s2("R"), s3("S");
	for(int i = 1; i<13; i++){
		tie(s1,s2,s3) = update(forward_as_tuple(s1,s2,s3));
		lookupTable[i][PlayerCounts(s1)] = s1;
		lookupTable[i][PlayerCounts(s2)] = s2;
		lookupTable[i][PlayerCounts(s3)] = s3;
	}
}

string solve(int N, int R, int P, int S){
	PlayerCounts candidate(R,P,S);
	if(lookupTable[N].find(candidate) == lookupTable[N].end()){
		return IMPOSSIBLE;
	}else{
		return lookupTable[N][candidate];
	}
}

int main(){
	init();
	int T, N, R, P, S;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> N >> R >> P >> S;
		cout << "Case #" << i << ": " << solve(N, R, P, S) << endl;
	}
}