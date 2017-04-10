//2010 Qualification Round, Problem 2
//Fair Warning
//code.google.com/codejam/contest/433101

/*
Input: The first line of the input gives the number of test cases, C. C lines follow. Each starts with a single integer N, which is followed by a space and then N space-separated integers ti, the number of slarboseconds since Great Event i occurred.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the minimum number of slarboseconds until ti + y is a multiple of the largest possible integer factor T for all i.
*/

//g++ Q-B.cpp -lgmpxx -lgmp -o Q-B.o

#include <iostream>
#include <cstring>
#include <gmp.h>
#include <vector>

using namespace std;

char* getSeconds(int N, vector<string> seconds){
	//cout << seconds.size() << endl;
	mpz_t ZERO;
	mpz_init(ZERO);
	
	mpz_t *inputs = (mpz_t*)malloc(N*sizeof(mpz_t));
	mpz_t min;
	mpz_init(min);
	mpz_set_si(min, 0);
	char *outString = new char[51];
	mpz_get_str(outString,10,min);
	for(int i = 0; i<N; i++){
		mpz_init_set_str(inputs[i], seconds[i].c_str(), 10);
	 	if(mpz_sgn(min) == 0 || mpz_cmp(inputs[i],min) < 0){
	 		mpz_set(min,inputs[i]);
	 	}
	}
	mpz_t gcd, temp;
	mpz_init(gcd);
	mpz_init(temp);
	for(int i = 0; i<N; i++){
		mpz_sub(temp, inputs[i], min);
		if(mpz_sgn(gcd) == 0 && mpz_sgn(temp) > 0){
			mpz_set(gcd, temp);
		}else{
			mpz_gcd(gcd, gcd, temp);
		}
	}

	if(mpz_cmp_si(gcd, 1) == 0){
		return "0";
	}

	mpz_t a,b;
	mpz_init(a);
	mpz_mod(a, min, gcd);
	if(mpz_sgn(a) == 0){
		return "0";
	}
	mpz_init(b);
	mpz_sub(b, gcd, a);
	// 	mpz_init_set_str(inputs[i], seconds[i].c_str(), 10);
	// 	if(mpz_cmp(min,0) == 0 || mpz_cmp(inputs[i],min) < 0){
	// 		mpz_set(min,inputs[i]);
	// 	}
	// }
	// mpz_t gcd;
	// mpz_init(gcd);
	// for(int i = 0; i<N; i++){

	// }
	// mpz_t result;
	// mpz_init(result);
	// char *outString = new char[51];
	// mpz_get_str(outString,10,min);
	// return outString;
	mpz_get_str(outString,10,b);
	return outString;
}

int main(){
	int C, N;
	string s;
	vector<string> seconds;
	cin >> C;
	//cout << C;
	for(int i = 1; i <= C; i++){
		cin >> N;
		seconds.clear();
		for(int j = 0; j < N; j++){
			cin >> s;
			seconds.push_back(s);
		}
		//cout << seconds.size() << endl;
		char* result = getSeconds(N,seconds);
		cout << "Case #" << i << ": " << result << endl;
	}
	return 0;
}