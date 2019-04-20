#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

string solveMaze(int N, string P){
    string mySolution;
    for(char c : P){
        if(c=='S'){
            mySolution += 'E';
        }else{
            mySolution += 'S';
        }
    }
    assert(mySolution.length() == 2*N-2);
    return mySolution;
}

int main()
{
	int T;
	int N;
    string P;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
        cin >> P;
		cout << "Case #" << i << ": " << solveMaze(N, P) << endl;
	}
	return 0;
}