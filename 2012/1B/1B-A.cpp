//2012 Round 1B, Problem A
//Safety in Numbers
//https://code.google.com/codejam/contest/1836486/dashboard

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow, one per line. Each line starts with an integer N, the number of contestants, followed by a space, followed by N integers s0, s1, ..., sN-1, separated by single spaces. The integer si is the point value assigned to contestant i by the judges.
*/

/*
Output: For each test case, output one line containing "Case #x: " followed by N real numbers: mis. The value x is the case number (starting from 1). The value mi is the smallest percentage of audience votes required for contestant i to definitely avoid elimination.

Answers within an absolute or relative error of 10-5 of the correct answer will be accepted.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_solution(int N, vector<int> scores){
	int j = 0;
	for(int i : scores){
		j+=i;
	}
	vector<int> sortedScores = scores;
	sort(sortedScores.begin(),sortedScores.end());
	reverse(sortedScores.begin(),sortedScores.end());

	int numberOfSafePeople = 0;
	int threshold = 2*j;
	int total_points = 2*j;

	for(int i : sortedScores){
		//cout << total_points << " " << N << " " << numberOfSafePeople << endl;
		//cout << i << " > " << 1.0*total_points/(N-numberOfSafePeople) << endl;
		if(i > 1.0*total_points/(N-numberOfSafePeople)){
			numberOfSafePeople++;
			total_points-=i;
			threshold = i;
		}else{
			break;
		}
	}

	int numberOfBottomFeeders = N-numberOfSafePeople;
	double percents[N];
	for(int i = 0; i < scores.size(); i++){
		if(scores[i]>=threshold){
			percents[i] = 0.0;
		}else{
			percents[i] = 100*(1.0*total_points/numberOfBottomFeeders - 1.0*scores[i])/j;
		}
	}
	char result[12];
	for(double d : percents){
		sprintf(result,"%.6f ",d);
		cout << result;
	}
	cout << endl;
}

int main(){
	int T, N, tmp;
	vector<int> scores;
	cin >> T;
	for(int i = 1; i <= T;i++){
		cin >> N;
		scores.clear();
		for(int j=0;j<N;j++){
			cin >> tmp;
			scores.push_back(tmp);
		}
		cout << "Case #" << i << ": ";
		print_solution(N,scores);
	}
}