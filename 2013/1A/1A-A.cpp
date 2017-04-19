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
#include <gmp.h>

using namespace std;

char* getRings(int R, int P){
	char* result [20];
	mpz_t lower_limit, upper_limit;
	mpz_init(lower_limit);
	mpz_init_set_si(upper_limit, P);
	mpz_t span, halfSpan, midpoint;
	mpz_t ONE, TWO;
	mpz_init(span);
	mpz_init(halfSpan);
	mpz_init(midpoint);
	mpz_init_set_si(TWO, 2);
	mpz_init_set_si(ONE, 1);
	while(mpz_comp(lower_limit,upper_limit)<0){
		mpz_sub(span,upper_limit,lower_limit);
		mpz_cdiv_q(halfSpan,span,TWO);
		mpz_add(midpoint,lower_limit,halfSpan);
		if(mpz_comp(midpoint,lower_limit)){
			mpz_add(midpoint, lower_limit, ONE);
		}
		if(canPaint(midpoint,R,P)){
			
		}
	}
	mpz_get_str(result,10,lower_limit);
	return result;
}

int main(){
	int T, R, P;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> R >> P;
		cout << "Case #" << i << ": " << getRings(R,P) << endl;
	}
}