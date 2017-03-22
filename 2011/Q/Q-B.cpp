//2011 Qualification Round, Problem 2
//Magicka
//code.google.com/codejam/contest/975485

/*
Input
The first line of the input gives the number of test cases, T. 
T test cases follow. Each test case consists of a single line, containing the following space-separated elements in order:

First an integer C, followed by C strings, each containing three characters: two base elements followed by a non-base element. 
This indicates that the two base elements combine to form the non-base element. 
Next will come an integer D, followed by D strings, each containing two characters: two base elements that are opposed to each other. 
Finally there will be an integer N, followed by a single string containing N characters: the series of base elements you are to invoke. 
You will invoke them in the order they appear in the string (leftmost character first, and so on), one at a time.

Output
For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) 
and y is a list in the format "[e0, e1, ...]" where ei is the ith element of the final element list. 
Please see the sample output for examples.
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

vector<string> getResult(int C, vector<string> combines, int D, vector<string> opposeds, int N, string invoked){
	unordered_map<string,string> combineMap = processCombines(C, combines);
	set<string> opposedSet = processOpposeds(D, opposeds);
	vector<char> result;
	map<char, int> currentlyContained;
	int i = 0;
	char newChar = invoked[i];
	while(true){
		if(result.empty()){
			result.push_back(newChar);
			currentlyContained.emplace(newChar, 1);
		}else{
			string checkCombine = "" + result.last() + newChar;
			
		}
		i++;
		if(i > N){ return result; }
	}
}

int main(){
	int T, C, D, N;
	vector<string> combine, opposed;
	combine.reserve(36);
	opposed.reserve(28);
	string invoked;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> C;
		string temp;
		for(int j = 0; j < C; j++){
			cin >> temp;
			combine.push_back(temp);
		}
		cin >> D;
		for(int j = 0; j < D; j++){
			cin >> temp;
			opposed.push_back(temp);
		}
		cin >> N;
		cin >> invoked;

		cout << "Case #" << i << ": [";
		vector<string> result = getResult(C, combine, D, opposed, N, invoked);
		if(result.size() == 0){
			cout << "]" << endl;
		}else{
			cout << result[1];
			for(vector<string>::size_type i = 1; i != result.size(); i++){
				cout << ", " << result[i];
			}
			cout << "]" << endl;
	}
}