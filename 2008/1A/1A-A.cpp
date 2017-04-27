//2008 Round 1A, Problem A
//Minimum Scalar Product
//code.google.com/codejam/contest/32016/dashboard

/*
Input: The first line of the input file contains integer number T - the number of test cases. For each test case, the first line contains integer number n. The next two lines contain n integers each, giving the coordinates of v1 and v2 respectively.
*/

/*
Output:
For each test case, output a line "Case #X: Y" where X is the test case number, starting from 1, and Y is the minimum scalar product of all permutations of the two given vectors.
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long int msp(vector<long long int> v1, vector<long long int> v2){
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	reverse(v2.begin(),v2.end());
	long long int sum = 0;
	for(int i = 0 ; i < v1.size(); i++){
		sum += v1[i]*v2[i];
	}
	return sum;
}

int main(){
	int T, N;
	vector<long long int> v1, v2;
	v1.reserve(800);
	v2.reserve(800);

	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N;
		v1.clear();
		v2.clear();
		for(int j = 0; j < N; j++){
			long long int temp;
			cin >> temp;
			v1.push_back(temp);
		}
		for(int j = 0; j < N; j++){
			long long int temp;
			cin >> temp;
			v2.push_back(temp);
		}
		cout << "Case #" << i << ": " << msp(v1,v2) << endl;
	}
}