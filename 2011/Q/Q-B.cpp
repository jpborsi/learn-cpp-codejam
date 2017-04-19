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
#include <string>
#include <set>
#include <map>
#include <vector>
#include <utility>
using namespace std;

vector<char> getResult(map<string, char> combinations, set<pair<char,char> > opposed, string invoked){
	string out = "";
	set<char> currentCharacters;
	int stringLength = 0;
	for(int i = 0; i < invoked.length(); i++){
		//cout << out << endl;
		if(stringLength == 0){
			out += invoked[i];
			currentCharacters.insert(invoked[i]);
			stringLength++;
		}else{
			string potentialCombination = "";
			potentialCombination += out[stringLength-1];
			potentialCombination += invoked[i];
			if(combinations.find(potentialCombination) != combinations.end()){
				out = out.substr(0,stringLength-1);
				out += combinations[potentialCombination];
				currentCharacters.clear();
				for(int k = 0; k < stringLength; k++){
					currentCharacters.insert(out[k]);
				}
			}else{
				for(char c : currentCharacters){
					if(opposed.find(make_pair(c,invoked[i])) != opposed.end()){
						out = "";
						currentCharacters.clear();
						stringLength = 0;
						break;
					}
				}
				if(!out.empty()){
					out += invoked[i];
					currentCharacters.insert(invoked[i]);
					stringLength++;
				}
			}
		}
	}
	vector<char> result;
	for(int i =0; i < stringLength; i++){
		result.push_back(out[i]);
	}
	return result;
}

int main(){
	int T, C, D, N;
	map<string, char> combinations;
	set<pair<char,char>> opposed;
	string invoked;
	string temp;
	cin >> T;
	for(int i = 1; i <= T; i++){
		combinations.clear();
		opposed.clear();
		cin >> C;
		for(int j = 0; j < C; j++){
			cin >> temp;
			combinations.insert(make_pair(temp.substr(0,2),temp[2]));
			string temp2 = "";
			temp2 += temp[1];
			temp2 += temp[0];
			combinations.insert(make_pair(temp2,temp[2]));
		}
		cin >> D;
		for(int j = 0; j < D; j++){
			cin >> temp;
			opposed.insert(make_pair(temp[0], temp[1]));
			opposed.insert(make_pair(temp[1], temp[0]));
		}
		cin >> N;
		cin >> invoked;
		vector<char> result = getResult(combinations, opposed, invoked);
		if(result.empty()){
			cout << "Case #" << i << ": " << "[]" << endl;
		}else{
			cout << "Case #" << i << ": " << "[";
			for(int j = 0; j < result.size()-1;j++){
				cout << result[j] << ", ";
			}
			cout << result[result.size()-1] << "]" << endl;
		}
	}
}