#include <iostream>
#include <string>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void solve(int N, int B, int F){
    string* result = new string[5];
    for(int query=0; query<5; query++){
        for(int i=0; i<N; i++){
            cout << ((i % 32) >> query) % 2;
        }
        cout << endl;
        cin >> result[query];
    }
    int* broken = new int[B];
    int numBroken = 0;
    for(int i=0; i<N; i++){
        int expectedIndex = i%32;

        int actualIndex = (result[0][i-numBroken] - '0')+
                            2*(result[1][i-numBroken] - '0') +
                            4*(result[2][i-numBroken] - '0') +
                            8*(result[3][i-numBroken] - '0') +
                            16*(result[4][i-numBroken] - '0');
        if(actualIndex != expectedIndex){
            broken[numBroken] = i;
            numBroken++;
        }
    }
    for(int i=0; i<B; i++){
        cout << broken[i] << " ";
    }
    cout << endl;
    int verdict;
    cin >> verdict;
    if(verdict==-1){
        exit(1);
    }
}

int main()
{
	int T, N, B, F;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> B >> F;
		solve(N, B, F);
	}
	return 0;
}