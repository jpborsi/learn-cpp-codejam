#include <iostream>
#include <map>
#include <queue>
#include <utility>

using namespace std;

const int MAX_COORD = 1073741824;

map<pair<int, int>, string> TABLE;
map<pair<pair<int, int>, int>, string> FULL;

int quadrant(int X, int Y){
	return (X<0) + 2*(Y<0);
}

string convert(string original, int quadrant){
	if(quadrant == 0){
		return original;
	}else if(quadrant == 1){
		string result = "";
		for(char c: original){
			if(c=='N'){result += 'N';}
			if(c=='S'){result += 'S';}
			if(c=='E'){result += 'W';}
			if(c=='W'){result += 'E';}
		}
		return result;
	}else if(quadrant == 2){
		string result = "";
		for(char c: original){
			if(c=='N'){result += 'S';}
			if(c=='S'){result += 'N';}
			if(c=='E'){result += 'E';}
			if(c=='W'){result += 'W';}
		}
		return result;
	}else{
		string result = "";
		for(char c: original){
			if(c=='N'){result += 'S';}
			if(c=='S'){result += 'N';}
			if(c=='E'){result += 'W';}
			if(c=='W'){result += 'E';}
		}
		return result;
	}
}

void setup(){
	FULL[make_pair(make_pair(0,0),1)] = "";
	queue<pair<pair<int, int>, int>> coords;
	coords.push(make_pair(make_pair(0,0), 1));

	while(!coords.empty()){
		pair<pair<int, int>, int> currentEntry, nextEntry;
		currentEntry = coords.front();
		pair<int, int> currentCoord, nextCoord;
		int jump, nextJump, X, Y;
		tie(currentCoord, jump) = currentEntry;
		coords.pop();
		tie(X, Y) = currentCoord;
		nextJump = 2*jump;
		string currentString = FULL[currentEntry];
		string nextString;

		//NORTH
		if(Y+jump <= MAX_COORD){
			nextCoord = make_pair(abs(X),abs(Y+jump));
			nextEntry = make_pair(nextCoord, nextJump);
			nextString = convert(currentString + 'N', quadrant(X, Y+jump));
			if(TABLE.find(nextCoord) == TABLE.end()){
				TABLE[nextCoord] = nextString;
			}
			if(FULL.find(nextEntry) == FULL.end()){
				FULL[nextEntry] = nextString;
				coords.push(nextEntry);
			}
		}

		//SOUTH
		if(Y-jump >= -MAX_COORD){
			nextCoord = make_pair(abs(X), abs(Y-jump));
			nextEntry = make_pair(nextCoord, nextJump);
			nextString = convert(currentString + 'S', quadrant(X, Y-jump));
			if(TABLE.find(nextCoord) == TABLE.end()){
				TABLE[nextCoord] = nextString;
			}
			if(FULL.find(nextEntry) == FULL.end()){
				FULL[nextEntry] = nextString;
				coords.push(nextEntry);
			}
		}

		//EAST
		if(X+jump <= MAX_COORD){
			nextCoord = make_pair(abs(X+jump), abs(Y));
			nextEntry = make_pair(nextCoord, nextJump);
			nextString = convert(currentString + 'E', quadrant(X+jump, Y));
			if(TABLE.find(nextCoord) == TABLE.end()){
				TABLE[nextCoord] = nextString;
			}
			if(FULL.find(nextEntry) == FULL.end()){
				FULL[nextEntry] = nextString;
				coords.push(nextEntry);
			}
		}

		//WEST
		if(X-jump >= -MAX_COORD){
			nextCoord = make_pair(abs(X-jump), abs(Y));
			nextEntry = make_pair(nextCoord, nextJump);
			nextString = convert(currentString + 'W', quadrant(X-jump, Y));
			if(TABLE.find(nextCoord) == TABLE.end()){
				TABLE[nextCoord] = nextString;
			}
			if(FULL.find(nextEntry) == FULL.end()){
				FULL[nextEntry] = nextString;
				coords.push(nextEntry);
			}
		}
	}
}

string solve(int X, int Y){
	pair<int, int> lookup_coord = make_pair(abs(X), abs(Y));
	auto search = TABLE.find(lookup_coord);
	if(search != TABLE.end()){
		int quadrant = (X<0) + (Y<0)*2;
		return convert(search->second, quadrant);
	}else{
		return "IMPOSSIBLE";
	}
}

int main(){
	setup();
	int T, X, Y;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> X >> Y;
		cout << "Case #" << i << ": " << solve(X,Y) << endl;
	}
	return 0;
}