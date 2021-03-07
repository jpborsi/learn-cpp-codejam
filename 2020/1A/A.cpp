#include <iostream>
#include <string>

using namespace std;

string patterns[50];

void solve(int N){
	string prefix = "";
	string suffix = "";
	string content = "";

	for(int i=0; i<N; ++i){
		string x = patterns[i];
		int firstStar = x.find("*");
		int lastStar = x.rfind("*");
		//cout << firstStar << " " << lastStar << endl;
		for(int j=0; j<firstStar; ++j){
			if(j < prefix.size() && prefix[j] != x[j]){
				cout << "*" << endl;
				return;
			}else if(j >= prefix.size()){
				prefix += x[j];
			}
		}

		for(int j=x.size()-1; j>lastStar; --j){
			int distanceFromEnd = x.size() - j;
			if(distanceFromEnd <= suffix.size() && suffix[suffix.size()-distanceFromEnd] != x[j]){
				cout << "*" << endl;
				return;
			}else if(distanceFromEnd > suffix.size()){
				suffix = x[j] + suffix;
			}
		}

		for(int j=firstStar+1; j<lastStar; ++j){
			if(x[j] != '*'){
				content += x[j];
			}
		}
	}
	//cout << prefix << " " << content << " " << suffix << endl;
	cout << prefix << content << suffix << endl;
	return;
}

int main()
{
	int T, N;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> N;
		for(int j=0; j<N; ++j){
			string S;
			cin >> S;
			patterns[j] = S;
		}
		cout << "Case #" << i << ": ";
		solve(N);
	}
	return 0;
}