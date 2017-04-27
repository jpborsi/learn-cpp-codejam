//2013 Round 1A, Problem A
//Bullseye
//code.google.com/codejam/contest/2418487

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of a line containing two space separated integers: r and t.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the maximum number of black rings that Maria can draw.
*/

#include <iostream>

using namespace std;

bool canPaint(long long int startingRings, long long int amountOfPaint, long long int possible){
	//cout << possible << endl;
	//cout << possible*(2*startingRings + 2*possible - 1) << endl;
	return amountOfPaint >= (possible)*(2*startingRings+1) + 2*possible*(possible-1);
}

long long int getRings(long long int R, long long int P){
	long long int checkRings = 2;
	while(canPaint(R,P,checkRings)){
		checkRings <<= 1;
	}
	long long int a = checkRings >> 1;
	long long int b = checkRings;
	//cout << checkRings << endl;
	while(a!=b){
		//cout << a << ", " << b << endl;
		if(canPaint(R,P,b)){
			return b;
		}
		long long int midpoint = (b-a)/2 + a;
		if(canPaint(R,P,midpoint)){
			if(a == midpoint){ return a; }
			a = midpoint;
		}else{
			b = midpoint;
		}
	}
	return a;
}

int main(){
	int T;
	long long int R, P;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> R >> P;
		cout << "Case #" << i << ": " << getRings(R,P) << endl;
	}
}