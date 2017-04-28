//2015 Round 1B, Problem A
//Counter Culture
//https://code.google.com/codejam/contest/8224486/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T lines follow. Each has one integer N, the number you must reach.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum number of numbers you need to say.
*/

long long int getNumbersToSay(string N){

	return 0;
}

int main(){
	int T;
	string N;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N;
		cout << "Case #" << i << ": " << getNumbersToSay(N) << endl;
	}
}