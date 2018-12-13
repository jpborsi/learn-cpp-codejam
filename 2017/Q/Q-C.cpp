#include <iostream>
#include <cmath>
#include <stdio.h>
#include <map>
using namespace std;

typedef long long int lli;

void solve(lli stalls, lli people){
	auto reverseCmp = [](const lli &a, const lli &b) -> bool {return a>b;};
	map<lli, lli, decltype(reverseCmp)> sizes(reverseCmp);
	sizes[stalls] =  1;
	lli currentCount = 0;
	lli x0, x1;
	while(currentCount < people){
		auto max = sizes.begin();
		lli blockSize = max->first;
		lli count = max->second;
		sizes.erase(blockSize);
		x0 = (blockSize-1)/2 + (blockSize-1)%2;
		x1 = (blockSize-1)/2;
		if(sizes.find(x0) == sizes.end()){
			sizes[x0] = 0;
		}
		sizes[x0] += count;
		if(sizes.find(x1) == sizes.end()){
			sizes[x1] = 0;
		}
		sizes[x1] += count;
		currentCount += count;
	}
	cout << x0 << " " << x1 << endl;
}

int main()
{
	int T;
	long long int N, K;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> K;
		cout << "Case #" << i << ": ";
		solve(N, K);
	}
	return 0;
}