//2017 Round 1-B, Problem A

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

char* getMaxSpeed(int D, int N, int* positions, int* velocities){
	double max_speed = -1.0;
	double speedToMeetAtD;
	for(int i = 0; i < N; i++){
		speedToMeetAtD = 1.0*velocities[i]*D/(D-positions[i]);
		if(max_speed < 0){
			max_speed = speedToMeetAtD;
		}else if(speedToMeetAtD < max_speed){
			max_speed = speedToMeetAtD;
		}
	}
	char *result = (char*)malloc(12*sizeof(char));
	sprintf(result,"%.6f",max_speed);
	return result;
}

int main(){
	int T, D, N;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> D >> N;
		int positions[N];
		int velocities[N];
		for(int j = 0; j < N; j++){
			cin >> positions[j] >> velocities[j];
		}
		cout << "Case #" << i << ": " << getMaxSpeed(D,N,positions,velocities) << endl;
	}
}