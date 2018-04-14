//2018 Round 1A, Problem C
#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

class Cookie{
	int W, H;
public:
	Cookie(){ W=0; H=0;}
	Cookie(int wi, int hi){ W = wi; H = hi; }
	double perim(){ return 2*W + 2*H; }
	double maxPerim(){ return 2*W + 2*H + 2*sqrt(W*W + H*H);}
	double minPerim(){return 2*H + 2*W + 2*min(W,H);}
};

double getMaxPerim(int N, long P, Cookie *cookies){
	double currentPerim = 0;
	for(int i=0; i<N; i++){
		currentPerim += cookies[i].perim();
	}
	double neededPerim = P - currentPerim;
	double minAddedPerim = cookies[0].minPerim() - cookies[0].perim();
	double maxAddedPerim = cookies[0].maxPerim() - cookies[0].perim();
	double marginalPerim = maxAddedPerim - minAddedPerim;

	int cookiesUsed = 0;
	for(int i=0; i<N; i++){
		if(neededPerim < minAddedPerim){
			break;
		}else{
			neededPerim -= minAddedPerim;
		}
		cookiesUsed++;
	}
	for(int i=0; i<cookiesUsed; i++){
		if(neededPerim < marginalPerim){
			return P;
		}else{
			neededPerim -= marginalPerim;
		}
	}
	return P-neededPerim;
}

int main()
{
	int T, N;
	long P;
	Cookie cookies[100];
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> P;
		for(int n=0;n<N;n++){
			int W, H;
			cin >> W >> H;
			cookies[n] = Cookie(W, H);
		}
		cout << "Case #" << i << ": ";
		double maxPerim = getMaxPerim(N, P, cookies);
		assert(maxPerim <= P);
		printf("%.6f", maxPerim);
		cout << endl;
	}
	return 0;
}