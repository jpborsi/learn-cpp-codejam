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
#include <sstream>

using namespace std;

string getTrainsRequired(int T, int NA, int NB, vector<string> departA, vector<string> departB, vector<string> arriveA, vector<string> arriveB){
	sort(departA.begin(),departA.end());
	sort(departB.begin(),departB.end());
	//sort(arriveA.begin(),arriveA.end());
	//sort(arriveB.begin(),arriveB.end());

	vector<string> availA, availB;

	char* s = (char*) malloc(5*sizeof(char));
	for(string a : arriveA){
		int hour = stoi(a.substr(0,2));
		int minute = stoi(a.substr(3,2));
		if(minute + T >= 60){
			hour++;
		}
		minute = (minute + T)%60;
		sprintf(s,"%02d:%02d",hour,minute);
		availA.push_back(string(s));
	}

	for(string b : arriveB){
		int hour = stoi(b.substr(0,2));
		int minute = stoi(b.substr(3,2));
		if(minute + T >= 60){
			hour++;
		}
		minute = (minute + T)%60;
		sprintf(s,"%02d:%02d",hour,minute);
		availB.push_back(string(s));
	}

	sort(availA.begin(),availA.end());
	sort(availB.begin(),availB.end());

	int startAtA = 0, startAtB = 0;
	auto itA = departA.begin();
	auto itB = departB.begin();
	auto arA = availA.begin();
	auto arB = availB.begin();

	

	while(itA != departA.end() || itB != departB.end()){
		if(itA!= departA.end() && (itB == departB.end() || *itA < *itB)){
			//cout << *itA << endl;
			//cout << "\t" << *arA << endl;
			if(arA != availA.end() && *itA >= *arA){
				itA++;
				arA++;
			}else{
				itA++;
				startAtA++;
			}
		}else{
			//cout << *itB << endl;
			//cout << "\t" << *arB << endl;
			if(arB != availB.end() && *itB >= *arB){
				itB++;
				arB++;
			}else{
				itB++;
				startAtB++;
			}
		}
	}

	stringstream result;
	result << startAtA << " " << startAtB;
	return result.str();
}

int main(){
	int N, T, NA, NB;
	vector<string> departA, departB, arriveA, arriveB;
	cin >> N;
	for(int i=1; i<=N; i++){
		departA.clear();
		departB.clear();
		arriveA.clear();
		arriveB.clear();
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