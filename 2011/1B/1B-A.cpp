//2011 Round 1B, Problem A
//RPI
//https://code.google.com/codejam/contest/1150485/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with a single line containing the number of teams N.

The next N lines each contain exactly N characters (either '0', '1', or '.') representing a schedule in the same format as the example schedule above. A '1' in row i, column j indicates team i beat team j, a '0' in row i, column j indicates team i lost to team j, and a '.' in row i, column j indicates team i never played against team j.
*/

/*
Output: For each test case, output N + 1 lines. The first line should be "Case #x:" where x is the case number (starting from 1). The next N lines should contain the RPI of each team, one per line, in the same order as the schedule.
*/

#include <vector>
#include <iostream>

using namespace std;

void printRpi(int N, vector<string> schedules){
	vector<int> wins;
	vector<int> games;
	vector<double> wp;
	vector<double> owp;
	vector<double> oowp;
	for(string s : schedules){
		int w = 0;
		int g = 0;
		for(int i =0;i<N;i++){
			if(s[i]=='1'){w++;}
			if(s[i]!='.'){g++;}
		}
		wins.push_back(w);
		games.push_back(g);
		wp.push_back(1.0*w/g);
	}
	for(int i=0;i<N;i++){
		int g = games[i];
		double sum=0;
		for(int j=0;j<N;j++){
			if(schedules[i][j]=='1'){
				sum += 1.0*wins[j]/((games[j]-1)*g);
			}else if(schedules[i][j]=='0'){
				sum += 1.0*(wins[j]-1)/((games[j]-1)*g);
			}
		}
		owp.push_back(sum);
	}
	for(int i=0;i<N;i++){
		int g = games[i];
		double sum = 0;
		for(int j=0;j<N;j++){
			if(schedules[i][j]!='.'){
				sum += owp[j]/g;
			}
		}
		oowp.push_back(sum);
	}
	char result[10];
	for(int i=0;i<N;i++){
		double rpi = 0.25*wp[i] + .5*owp[i] + .25*oowp[i];
		sprintf(result,"%.6f ",rpi);
		cout << result << endl;
	}

}

int main(){
	int T, N;
	string tmp;
	vector<string> schedules;
	cin >> T;
	for(int i=1;i<=T;i++){
		cin>>N;
		schedules.clear();
		for(int j=0;j<N;j++){
			cin >> tmp;
			schedules.push_back(tmp);
		}
		cout << "Case #" << i << ": " << endl;
		printRpi(N,schedules);
	}
}