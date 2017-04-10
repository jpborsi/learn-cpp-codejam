#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

string convert(int* mins, int N){
	string nums ("0123456789");
	string result ("");
	for(int i = 0; i < N; i++){
		result += nums[mins[i]];
	}
	return result;
}

string getLastTidyNumber(string N) {
	string nums ("0123456789");
	int overallMin = N[0] - '0';
	int mins [N.size()];
	for(int i = 0; i < N.size();i++){
		//cout << N[i] << " " << N[i] - '0' << endl;
		int val = N[i] - '0';
		if(val < overallMin){
			string result ("");
			for(int j = i-1; j > 0; j--){
				//cout << j << endl;
				if(mins[j-1] < mins[j]){
					mins[j] --;
					for(int k = 0; k < j+1; k++){
						result += nums[mins[k]];
					}
					for(int k = j+1; k < N.size(); k++){
						result += '9';
						
					}
					return result;
				}
			}
			if(mins[0] == 1){
				for(int i=0;i<N.size()-1;i++){
					result += '9';
				}
				return result;
			}else{
				result += nums[mins[0]-1];
				for(int i=1;i<N.size();i++){
					result += '9';
				}
			}
			return result;
		}else if(val > overallMin){
			overallMin = val;
			mins[i] = val;
		}else{
			mins[i] = overallMin;
		}
	}
	string result;
	for(int i=0;i<N.size();i++){
		result += '0' + mins[i];
	}
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