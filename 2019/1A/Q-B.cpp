#include <iostream>
#include <string>
#include <stdio.h>
#include <assert.h>
#include <set>
#include <tuple>
#include <iterator>
#include <vector>
#include <cstdlib>

using namespace std;

void processCase(int N, int M){
	int queries[7] = {16, 9, 17, 13, 11, 7, 5};
	int* results = new int[7];
	for(int i=0; i<7; i++){
		for(int j=0; j<18; j++){
			cout << queries[i] << " ";
		}
		cout << endl;
		int x_i;
		int total = 0;
		for(int j=0; j<18; j++){
			cin >> x_i;
			total += x_i;
		}
		results[i] = total % queries[i];
	}

	int result = -1;

	for(int i=1; i<= 1000000; i++){
		bool good = true;
		for(int j=0; j<7; j++){
			if(i%queries[j] != results[j]){ 
				good = false;
				break;
			}
		}
		if(good){
			result = i;
			break;
		}
	}

	cout << result << endl;

	int verdict;
	cin >> verdict;
	if(verdict == -1){
		exit(0);
	}
	return;
}

int main()
{
	int T, N, M;
	cin >> T >> N >> M;
	for (int i = 1; i <= T; i++) {
		processCase(N, M);
	}
	return 0;
}

// int main(){
// 	set<tuple<int, int, int, int, int, int, int>> mods;
// 	for(int i=1; i<=1000000; i++){
// 		tuple<int, int, int, int, int, int, int> m = make_tuple(i % 16, i % 9, i % 17, i%13, i% 11, i%7, i%5);
// 		if(mods.find(m) != end(mods)){
// 			cout << i << endl;
// 		}
// 		mods.insert(m);
// 	}
// 	cout << mods.size() << endl;
// }