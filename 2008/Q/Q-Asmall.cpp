// 2008 Qualification Round, Problem 1
// Saving the Universe
// code.google.com/codejam/contest/32013

/*
Input: The first line of the input file contains the number of cases, N. N test cases follow.

Each case starts with the number S -- the number of search engines. 
The next S lines each contain the name of a search engine. 
Each search engine name is no more than one hundred characters long and contains only uppercase letters, lowercase letters, spaces, and numbers. 
There will not be two search engines with the same name.

The following line contains a number Q -- the number of incoming queries. 
The next Q lines will each contain a query. Each query will be the name of a search engine in the case.
*/

/*
Output: For each input case, you should output: "Case #X: Y",
where X is the number of the test case and Y is the number of search engine switches
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int getNumSwitches(string* engines, string* queries, int S, int Q){
	unordered_map<string, int> engine_ids;
	for (int i = 0; i < S; ++i)
	{
		engine_ids[engines[i]] = i;
	}
	int numSwitches = 0;
	int maps_accessed = 0;
	for (int i = 0; i < Q; ++i){
		maps_accessed |= 1 << engine_ids[queries[i]];
		if (maps_accessed == (1 << S)-1){
			maps_accessed = 1 << engine_ids[queries[i]];
			numSwitches++;
		}
	}
	return numSwitches;
}

int main(){
	int N, S, Q;
	string* engines;
	string* queries;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S;
		engines = new string[S];
		cin.ignore();
		for (int j = 0; j < S; ++j)
		{
			getline(cin,engines[j]);
		}
		cin >> Q;
		queries = new string[Q];
		cin.ignore();
		for (int j = 0; j < Q; ++j)
		{
			getline(cin,queries[j]);
		}
		cout << "Case #" << i << ": " << getNumSwitches(engines, queries, S, Q) << endl;
	}
	return 0;
}