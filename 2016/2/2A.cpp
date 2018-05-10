//2016 Round 2, Problem A
//A Rather Perplexing Showdown

#include <iostream>
#include <string>
#include <tuple>

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
	bool operator== (const PlayerCounts&b){
		return rock == b.rock && paper == b.paper && scissors == b.scissors;
	}
	friend ostream& operator<<(ostream &os, const PlayerCounts&b);
};

ostream& operator<<(ostream &os, const PlayerCounts&b){
	char buffer[100];
	sprintf(buffer, "%d,%d,%d", b.rock, b.paper, b.scissors);
	return os << buffer;
}

string results[13][3];
PlayerCounts counts[13][3];

tuple<string,string,string> update(string s1, string s2, string s3){
	return make_tuple(s1+s2,s1+s3,s2+s3);
}

PlayerCounts count(string s){
	int P=0,R=0,S=0;
	for(char c : s){
		switch(c){
			case 'P':
				P++;
				break;
			case 'R':
				R++;
				break;
			case 'S':
				S++;
				break;
		}
	}
	return PlayerCounts(R,P,S);

}

void init(){
	results[0][0] = 'P';
	results[0][1] = 'R';
	results[0][2] = 'S';
	for(int i = 1; i<13; i++){
		auto tmp = update(results[i-1][0],
			results[i-1][1],
			results[i-1][2]);
		results[i][0] = get<0>(tmp);
		results[i][1] = get<1>(tmp);
		results[i][2] = get<2>(tmp);
		counts[i][0] = count(results[i][0]);
		counts[i][1] = count(results[i][1]);
		counts[i][2] = count(results[i][2]);
	}
	//cout << results[2][0] << endl;
	//cout << results[2][1] << endl;
	//cout << results[2][2] << endl;
	//cout << counts[2][0] << endl;
	//cout << counts[2][1] << endl;
	//cout << counts[2][2] << endl;
}

string solve(int N, int R, int P, int S){
	PlayerCounts candidate(R,P,S);
	if(counts[N][0] == candidate){
		return results[N][0];
	}else if(counts[N][1] == candidate){
		return results[N][1];
	}else if(counts[N][2] == candidate){
		return results[N][2];
	}else{
		return "IMPOSSIBLE";
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