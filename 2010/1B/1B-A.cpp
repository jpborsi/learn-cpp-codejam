//2010 Round 1B, Problem A
//File Fix-it
//https://code.google.com/codejam/contest/635101/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each case begins with a line containing two integers N and M, separated by a space.

The next N lines each give the path of one directory that already exists on your computer. This list will include every directory already on your computer other than the root directory. (The root directory is on every computer, so there is no need to list it explicitly.)

The next M lines each give the path of one directory that you want to create.

Each of the paths in the input is formatted as in the problem statement above. Specifically, a path consists of one or more lower-case alpha-numeric strings (i.e., strings containing only the symbols 'a'-'z' and '0'-'9'), each preceded by a single forward slash. These alpha-numeric strings are never empty.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the number of mkdir you need.
*/

#include <set>
#include <vector>
#include <iostream>
#include <boost/algorithm/string.hpp>

using namespace std;

int getNumberOfMkDirs(set<string> existing, vector<string> desired){
	int commands = 0;
	for(string d : desired){
		vector<string> splits;
		split(splits, d, boost::is_any_of("/"));
		string s = "";
		for(string sp : splits){
			if(sp.empty()){continue;}
			//cout << sp << " " << s << endl;
			if(existing.find(s)==existing.end()){
				commands++;
				existing.insert(s);
			}
			s = s + "/" + sp;
		}
		if(existing.find(s)==existing.end()){
			commands++;
			existing.insert(s);
		}
	}
	return commands;
}

int main(){
	int T, N, M;
	set<string> existing;
	vector<string> desired;
	string tmp;
	cin >> T;
	for(int i=1;i<=T;i++){
		cin >> N >> M;
		existing.clear();
		existing.insert("");
		desired.clear();
		for(int j=0;j<N;j++){
			cin >> tmp;
			existing.insert(tmp);
		}
		for(int k=0;k<M;k++){
			cin >> tmp;
			desired.push_back(tmp);
		}
		cout << "Case #" << i << ": " << getNumberOfMkDirs(existing,desired) << endl;
	}
}