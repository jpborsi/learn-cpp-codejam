//2017 Round 1B, Problem B

#include <iostream>
#include <string>
#include <map>
#include <set>

using namespace std;

string illegalStrings[] = {"RR","OO","YY","GG","BB","VV",
"RO","OR","RV","VR","OY","YO","OG","GO","OV","VO","YG","GY",
"BG","GB","BV","VB","GV","VG"};
set<string> illegal(illegalStrings,illegalStrings+24);

bool check(string s){
	if (s.length() <= 1){
		return true;
	}
	for(int i = 0; i < s.length()-1; i++){
		if(illegal.find(s.substr(i,2)) != illegal.end()){
			return false;
		}
	}
	string connect = "";
	connect += s[0];
	connect += s[s.length()-1];
	if(illegal.find(connect) != illegal.end()){
		return false;
	}
	return true;
}

string getArrangement(int N, int R, int O, int Y, int G, int B, int V){
	if(R < G || Y < V || B < O){
		return "IMPOSSIBLE";
	}
	if(R > N/2 || B > N/2 || Y > N/2){
		return "IMPOSSIBLE";
	}

	int placedR = 0;
	int placedY = 0;
	int placedB = 0;
	string s = "";
	for(int i = 0; i < O; i++){
		s += "BO";
		placedB++;
	}
	if(O > 0 && s.length() < N){
		s+= "B";
		placedB++;
	}
	for(int i = 0; i < V; i++){
		s+= "YV";
		placedY++;
	}
	if(V > 0 && s.length() < N){
		s+= "Y";
		placedY++;
	}
	for(int i = 0; i < G; i++){
		s+= "RG";
		placedR++;
	}
	if(G > 0 && s.length() < N){
		s+= "R";
		placedR++;
	}
	if(s.length()==N && check(s)){
		return s;
	}
	if(s.length()==0){
		if(R > B && R > Y){
			s = "R";
			placedR++;
		}else if(B > Y){
			s = "B";
			placedB++;
		}else{
			s = "Y";
			placedY++;
		}
	}
	map<char,int> leftToPlace;
	leftToPlace['B'] = B - placedB;
	leftToPlace['R'] = R - placedR;
	leftToPlace['Y'] = Y - placedY;
	while(s.length() < N){
		//cout << s << endl;
		char firstChar = s[0];
		char lastChar = s[s.length()-1];
		//cout << firstChar << lastChar << endl;
		//cout << leftToPlace[firstChar] << leftToPlace[lastChar] << endl;
		if(lastChar=='B'){
			if(leftToPlace['Y']>leftToPlace['R'] || (leftToPlace['Y']==leftToPlace['R']&&firstChar=='Y')){
				s += 'Y';
				leftToPlace['Y'] = leftToPlace['Y']-1;
			}else{
				s += 'R';
				leftToPlace['R'] = leftToPlace['R']-1;
			}
		}else if(lastChar=='Y'){
			if(leftToPlace['B']>leftToPlace['R']|| (leftToPlace['B']==leftToPlace['R']&&firstChar=='B')){
				s += 'B';
				leftToPlace['B'] = leftToPlace['B']-1;
			}else{
				s += 'R';
				leftToPlace['R'] = leftToPlace['R']-1;
			}
		}else{
			if(leftToPlace['B']>leftToPlace['Y']|| (leftToPlace['B']==leftToPlace['Y']&&firstChar=='B')){
				s += 'B';
				leftToPlace['B'] = leftToPlace['B']-1;
			}else{
				s += 'Y';
				leftToPlace['Y'] = leftToPlace['Y']-1;
			}
		}
	}
	if(check(s)){

		return s;
	}else{
		//cout << "ERROR" << endl;
		return "IMPOSSIBLE";
	}
}

int main(){
	int T;
	int N, R, O, Y, G, B, V;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> R >> O >> Y >> G >> B >> V;
		cout << "Case #" << i << ": " << getArrangement(N, R, O, Y, G, B, V) << endl;
	}
}