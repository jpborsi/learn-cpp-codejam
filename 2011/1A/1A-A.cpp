//2011 Round 1A, Problem A
//FreeCell Statistics
//code.google.com/codejam/contest/1145485/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T lines follow. Each line contains 3 integers -- N, PD and PG
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is either "Possible" or "Broken".
*/

#include <iostream>
#include <cmath>

using namespace std;

bool possible(long long int N, int PD, int PG){
	if(PD > 0 && PG == 0){ return false; }
	if(PD < 100 && PG == 100){ return false; }
	if(N>=100){ return true; }
	for(int i = 1; i<=N; i++){
		if(floor(1.0*PD*i/100)==1.0*PD*i/100){
			return true;
		}
	}

	return false;
}

int main(){
	int T, PD, PG;
	long long int N;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> PD >> PG;
		if(possible(N,PD,PG)){
			cout << "Case #" << i << ": Possible" << endl;
		}else{
			cout << "Case #" << i << ": Broken" << endl;
		}
	}
}