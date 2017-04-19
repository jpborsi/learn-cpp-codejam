#include <iostream>
#include <map>
#include <stdlib.h>
using namespace std;

int getMaxPackages(int N, int P, int* grams, int* packages) {
	int numKits;
	if(N==1){
		for(int i = 0; i < P; i++){
			int testNum = int(1.0*packages[i]/(grams[i]*0.9));
			if(testNum > 0 && packages[i] < grams[i]*testNum){
				numKits++;
			}
		}
		return numKits;
	}

	for(int i = 0; i<P; i++){
		int testNum = int(1.0*packages[i]/(grams[i]*0.9));
		if(!testNum > 0 || packages[i] >= grams[i]*testNum){
				continue;
		}
		for(int j = 0; j < P; j++){

		}
	}

	free(servings);
	return 0;
}

int main()
{
	int T, N, P;
	int *grams = (int*)malloc(50*sizeof(int));
	int *packages = (int*)malloc(1000*sizeof(int));
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> P;
		for(int j = 0; j < N; j++){
			cin >> grams[j];
		}
		for(int k = 0; k < N*P; k++){
			cin >> packages[k];
		}
		cout << "Case #" << i << ": ";
		int maxPackages = getMaxPackages(N, P, grams, packages);
		cout << maxPackages << endl;
	}
	return 0;
}