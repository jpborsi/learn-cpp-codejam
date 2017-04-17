//2008 Qualification Round, Problem B
//Train Timetable
//code.google.com/codejam/contest/32013

/*
Input: The first line of input gives the number of cases, N. N test cases follow.
Each case contains a number of lines. The first line is the turnaround time, T, in minutes. The next line has two numbers on it, NA and NB. NA is the number of trips from A to B, and NB is the number of trips from B to A. Then there are NA lines giving the details of the trips from A to B.

Each line contains two fields, giving the HH:MM departure and arrival time for that trip. The departure time for each trip will be earlier than the arrival time. All arrivals and departures occur on the same day. The trips may appear in any order - they are not necessarily sorted by time. The hour and minute values are both two digits, zero-padded, and are on a 24-hour clock (00:00 through 23:59).

After these NA lines, there are NB lines giving the departure and arrival times for the trips from B to A.
*/

/*
Output:
For each test case, output one line containing "Case #x: " followed by the number of trains that must start at A and the number of trains that must start at B.
*/

#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

string getTrainsRequired(int T, int NA, int NB, vector<string> departA, vector<string> departB, vector<string> arriveA, vector<string> arriveB){
	return "6 Words";
}

int main(){
	int N, T, NA, NB;
	vector<string> departA, departB, arriveA, arriveB;
	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> T >> NA >> NB;
		string depart, arrive;
		for(int j = 0; j < NA; j++){
			cin >> depart >> arrive;
			departA.push_back(depart);
			arriveB.push_back(arrive);
		}
		for(int j = 0; j < NB; j++){
			cin >> depart >> arrive;
			departB.push_back(depart);
			arriveA.push_back(arrive);
		}
		string result = getTrainsRequired(T, NA, NB, departA, departB, arriveA, arriveB);
		cout << "Case #" << i << ": " << result << endl;
	}
}