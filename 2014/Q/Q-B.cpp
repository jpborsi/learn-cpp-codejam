// 2014 Qualification Round, Problem 2
// Cookie Clicker Alpha
// code.google.com/codejam/contest/2974486

/*
Input: The first line of the input gives the number of test cases, T. T lines follow.
Each line contains three space-separated real-valued numbers: C, F and X,
whose meanings are described earlier in the problem statement.

C, F and X will each consist of at least 1 digit followed by 1 decimal point followed by from 1 to 5 digits.
There will be no leading zeroes.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) 
and y is the minimum number of seconds it takes before you can have X delicious cookies.

We recommend outputting y to 7 decimal places, but it is not required. y will be considered correct if it is close enough to the correct number: within an absolute or relative error of 10-6.
See the FAQ for an explanation of what that means, and what formats of real numbers we accept.
*/

#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

double secondsBeforeCookies(double C, double F, double X) {
	double maxProduction = F*(X/C - 1);
	double p = 2.0;
	double time = 0.0;
	while( p < maxProduction) {
		time += C/p;
		p += F;
	}
	time += X/p;
	return time;
}

int main() {
	int T;
	double C, F, X;
	cin >> T;
	cout << fixed << setprecision(7);
	for(int i = 1; i <= T; i++){
		cin >> C >> F >> X;
		cout << "Case #" << i << ": " << secondsBeforeCookies(C,F,X) << endl;
	}
	return 0;
}