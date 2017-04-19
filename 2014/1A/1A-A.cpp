//2014 Round 1A, Problem A
//Charging Chaos
//code.google.com/codejam/contest/2984486

/*
Input: The first line of the input gives the number of test cases, T. T test cases follow. Each test case consists of three lines. The first line contains two space-separated integers N and L. The second line contains N space-separated strings of length L, representing the initial electric flow from the outlets. The third line also contains N space-separated strings of length L, representing the electric flow required by Shota's devices.
*/

/*
Output: For each test case, output one line containing "Case #x: y", where x is the case number (starting from 1) and y is the minimum number of switches to be flipped in order for Shota to charge all his devices. If it is impossible, y should be the string "NOT POSSIBLE" (without the quotes). Please note that our judge is not case-sensitive, but it is strict in other ways: so although "not  possible" will be judged correct, any misspelling will be judged wrong. We suggest copying/pasting the string NOT POSSIBLE into your code.
*/

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <boost/multi_array.hpp>

typedef boost::multi_array<int,2> array_type;
typedef array_type::index mi;

using namespace std;

void flip(int i, vector<string>& outlets){
	for(int j = 0; j < outlets.size() ; j++){
		string s = outlets[j];
		if(s[i] == '1'){ s[i] = '0';}
		else{ s[i] = '1';}
		outlets[j] = s;
	}
}

bool isValid(vector<string> outlets, set<string> devices, string from, string to){
	for(int i = 0; i < from.length(); i++){
		if(from[i] != to[i]){
			for(int j = 0; j < outlets.size(); j++){
				if(outlets[j][i] == '1'){ outlets[j][i] = '0';}
				else{ outlets[j][i] = '1';}
			}
		}
	}
	for(string outlet : outlets){
		if(devices.find(outlet) == devices.end()){
			return false;
		}
	}
	return true;
}

int getMinFlips(int N, int L, std::vector<string> outlets, std::vector<string> devices){
	set<int> fixed_positions;
	int minFlips = 0;
	for(int i = 0; i < L; i++){
		int sum_outlets = 0, sum_devices = 0;
		for(int j = 0; j < N; j++){
			sum_outlets += outlets[j][i] == '1';
			sum_devices += devices[j][i] == '1';
		}
		//cout << sum_outlets << sum_devices << endl;
		if(sum_outlets != sum_devices && sum_outlets != N - sum_devices){
			return -1;
		}else if(sum_devices != N - sum_devices){
			fixed_positions.insert(i);
			if(sum_outlets != sum_devices){
				minFlips ++;
				flip(i, outlets);
			}
		}
	}
	//cout << minFlips << endl;
	//cout << minFlips << endl;
	//for(int i = 0; i < N; i++){
	//	cout << outlets[i] << " ";
	//}
	//cout << endl;
	set<string> deviceSet(devices.begin(), devices.end());
	int min = L+1;
	for(string outlet : outlets){
		bool isPossible = true;
		for(int i : fixed_positions){
			if(outlet[i]!=devices[0][i]){
				isPossible=false;
				break;
			}
		}
		//cout << isPossible << endl;
		if(isPossible && isValid(outlets, deviceSet, outlet, devices[0])){
			int distance = 0;
			for(int i = 0; i < L; i++){
				if(outlet[i]!=devices[0][i]){ distance ++; }
			}
			//cout << distance << endl;
			if(distance < min){
				min = distance;
			}
		}
	}
	if(min == L+1){
		return -1;
	}
	return minFlips + min;
}

int main(){
	int T, N, L;
	vector<string> outlets, devices;
	string temp;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> L;
		outlets.clear();
		devices.clear();
		for(int j = 0; j < N; j++){
			cin >> temp;
			outlets.push_back(temp);
		}
		for(int j = 0; j < N; j++){
			cin >> temp;
			devices.push_back(temp);
		}
		int minFlips = getMinFlips(N, L, outlets, devices);
		if(minFlips == -1){
			cout << "Case #" << i << ": NOT POSSIBLE" << endl;
		}else{
			cout << "Case #" << i << ": " << minFlips << endl;
		}
	}
	
}