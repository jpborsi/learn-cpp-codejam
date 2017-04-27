//2017 Round 1B, Problem C

#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>
#include <cstdlib>
#include <cassert>
#include <map>

using namespace std;

char* getTime(int N, vector<int> horse_range, vector<int> horse_speed, int* distances, pair<int,int> route){
	queue<tuple<int,double,int,int> > myChoices;
	int myfirsthorse = 0;
	int myfirsthorse_range = horse_range[0];
	int myfirsthorse_speed = horse_speed[0];
	int distanceToNextTown = distances[1];
	double time = 1.0*distanceToNextTown/myfirsthorse_speed;
	int range_left = myfirsthorse_range - distanceToNextTown;
	myChoices.push(make_tuple(1,time,myfirsthorse,range_left));
	double minTime = -1.0;
	map<tuple<int,int,int>,double> previouslySeen;
	while(!myChoices.empty()){
		tuple<int,double,int,int> entry = myChoices.front();
		myChoices.pop();
		tuple<int,int,int> tt = make_tuple(get<0>(entry),get<2>(entry),get<3>(entry));
		if(previouslySeen.find(tt) != previouslySeen.end() && previouslySeen[tt] < get<1>(entry)){
			continue;
		}
		previouslySeen[tt] = get<1>(entry);
		int currentCity = get<0>(entry);
		//cout << currentCity << endl;
		if(currentCity == N-1){
			double time = get<1>(entry);
			if(minTime < 0 || time < minTime){
				minTime = time;
			}
			continue;
		}
		if(get<3>(entry)<0){
			continue;
		}
		if(minTime > 0 && get<1>(entry) > minTime){
			continue;
		}
		int distanceToNextTown = distances[currentCity*N+currentCity+1];
		double time = get<1>(entry);
		int old_horse = get<2>(entry);
		int old_speed = horse_speed[old_horse];
		double old_time = 1.0*distanceToNextTown/old_speed;
		int new_horse = currentCity;
		int new_speed = horse_speed[new_horse];
		double new_time = 1.0*distanceToNextTown/new_speed;
		int old_range = get<3>(entry);
		int new_range = horse_range[new_horse];

		if(old_range > distanceToNextTown){
			myChoices.push(make_tuple(currentCity+1,time+old_time,old_horse,old_range-distanceToNextTown));
		}
		myChoices.push(make_tuple(currentCity+1,time+new_time,new_horse,new_range-distanceToNextTown));
	}
	assert(minTime > 0);
	char *result = (char*)malloc(24*sizeof(char));
	sprintf(result,"%.6f",minTime);
	return result;
}


int main(){
	int T;
	int N, Q;
	vector<int> horse_range, horse_speed;
	vector<pair<int,int>> routes;

	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> Q;
		horse_speed.clear();
		horse_range.clear();
		for(int j = 0; j < N; j++){
			int E,S;
			cin >> E >> S;
			horse_range.push_back(E);
			horse_speed.push_back(S);
		}
		int distances[N*N];
		for(int j = 0; j < N; j++){
			for(int k = 0; k < N; k++){
				cin >> distances[j*N+k];
			}
		}
		routes.clear();
		for(int j = 0; j < Q; j++){
			int A,B;
			cin >> A >> B;
			routes.push_back(make_pair(A,B));
		}
		cout << "Case #" << i << ": ";
		for(int j = 0; j < Q; j++){
			cout << getTime(N,horse_range,horse_speed,distances,routes[j]);
		}
		cout << endl;
	}
}