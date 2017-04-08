#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

long long int getSize(long long int N, long long int K){
	int level = floor(log(K)/log(2));
	long long int numberOfPeopleInLevel = pow(2,level);
	long long int numberOfSeatsInLevel = N - numberOfPeopleInLevel + 1;
	long long int goodSeatAmount = ceil(1.0*numberOfSeatsInLevel/numberOfPeopleInLevel);
	long long int badSeatAmount = floor(1.0*numberOfSeatsInLevel/numberOfPeopleInLevel);
	long long int numberOfGoodSeats = numberOfSeatsInLevel - badSeatAmount*numberOfPeopleInLevel;
	if(K - pow(2,level) + 1 <= numberOfGoodSeats){
		return goodSeatAmount;
	}else{
		return badSeatAmount;
	}
}

int main()
{
	int T;
	long long int N, K;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		long long int effectiveSize = getSize(N,K);
		//cout << effectiveSize << endl;
		cout << "Case #" << i << ": ";
		if(effectiveSize <= 1){
			cout << 0 << " " << 0 << endl;
		}else{
			long long int upper = ceil(1.0*(effectiveSize-1)/2);
			long long int lower = floor(1.0*(effectiveSize-1)/2);
			printf ("%lld %lld\n", upper, lower );
			//cout << ceil(1.0*(effectiveSize-1)/2) << " " << floor(1.0*(effectiveSize-1)/2) << endl;
		}
	}
	return 0;
}