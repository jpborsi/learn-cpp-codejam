#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <iterator>
#include <math.h>

using namespace std;

string commonSubstring(string x, string y){
	string result = "";
	//cout << x << " " << y << endl;
	for(int i=1; i<=min(x.length(),y.length()); i++){
		//cout << x[x.length()-i] << " " << y[y.length()-i] << " " << result << endl;
		if(x[x.length()-i] == y[y.length()-i]){
			result = x[x.length()-i] + result;
		}else{
			return result;
		}
	}
	return result;
}

int getSubsetWords(int N, string* W){
	set<int> paired_words;
	set<int> unpaired_words;
	set<string> substrings;
	while(true){
		int max_substring_length = 0;
		string max_substring = "";
		int p_i, p_j;
		for(int i=0; i<N; i++){
			if(paired_words.find(i) != end(paired_words)){ continue; }
			if(unpaired_words.find(i) != end(unpaired_words)){ continue; }
			for(int j=i+1; j<N; j++){
				if(paired_words.find(j) != end(paired_words)){ continue; }
				if(unpaired_words.find(j) != end(unpaired_words)){ continue; }
				string substring = commonSubstring(W[i], W[j]);
				//cout << substring << endl;
				while(substrings.find(substring) != end(substrings)){
					substring = substring.substr(1);
				}
				if(substring.length() > max_substring_length){
					max_substring_length = substring.length();
					max_substring = substring;
					p_i = i;
					p_j = j;
				}
			}
		}

		if(max_substring_length == 0){ break; }
		paired_words.insert(p_i);
		paired_words.insert(p_j);
		substrings.insert(max_substring);
	}
	return paired_words.size();
}

int main()
{
	int T, N;
	string* W = new string[1000];
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for(int j=0; j<N; j++){
			cin >> W[j];
		}
		cout << "Case #" << i << ": ";
		cout << getSubsetWords(N, W) << endl;
	}
	return 0;
}