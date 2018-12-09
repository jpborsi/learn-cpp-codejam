#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>

using namespace std;

int convert(string S, int index){
	assert(index < S.length());
	int result = S[index] - '0';
	assert(result < 10);
	assert(result >= 0);
	return result;
}

string nines(int length){
	assert(length >= 0);
	string result = "";
	for(int i=0; i<length; i++){
		result += '9';
	}
	return result;
}

bool isTidy(string N){
	if(N.length() == 1){ return true; }
	for(int i=1; i<N.length(); i++){
		if(N[i] < N[i-1]){
			return false;
		}
	}
	return true;
}

int firstMax(string N){
	assert(N.length()>0);
	int currentMax = 0;
	int currentIndex = -1;
	for(int i=0; i<N.length(); i++){
		int t = convert(N,i);
		if(t > currentMax){
			currentMax = t;
			currentIndex = i;
		}
	}
	assert(currentIndex >= 0);
	return currentIndex;
}

string getLastTidyNumber(string N) {
	if(isTidy(N)){ return N; }
	int startingNumber = convert(N, 0);
	for(int i=1; i<N.length(); i++){
		if(convert(N, i) < startingNumber){
			int fM = firstMax(N.substr(0,i));
			if(fM == 0 && startingNumber == 1){
				return nines(N.length()-1);
			}
			string result = N.substr(0,fM) + to_string(convert(N,fM)-1) + nines(N.length()-fM-1);
			assert(isTidy(result));
			return result;
		}
	}
	string result = to_string(startingNumber) + getLastTidyNumber(N.substr(1));
	assert(isTidy(result));
	assert(result.length() == N.length() || result.length() == N.length() - 1);
	return result;
}

int main()
{
	int T;
	string N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << "Case #" << i << ": ";
		cout << getLastTidyNumber(N) << endl;
	}
	return 0;
}