//2011 Round 2, Problem A

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Walkway{
	int B,E,w;
public:
	Walkway(int Bi, int Ei, int wi){
		B = Bi;
		E = Ei;
		w = wi;
	}
	Walkway(){ B=0; E=0; w=0; }
	double getWalkwayTime(int speed){
		return 1.0*(E-B)/(speed + w);
	}
	double getLength(){
		return 1.0*(E-B);
	}
	double getBaseSpeed(){ return w; }
	double getRunningLength(int runningSpeed, double time){
		return (runningSpeed+w)*time;
	}
};
bool compareWalkway(Walkway i, Walkway j){ return i.getBaseSpeed() < j.getBaseSpeed();}

double getTime(int corridorLength, int walkingSpeed, int runningSpeed, int maxRunningTime, int numWalkways, Walkway *walkways){
	vector<Walkway> ways;
	int totalWalkwayLength = 0;
	for(int i=0; i<numWalkways; ++i){
		totalWalkwayLength += walkways[i].getLength();
		ways.push_back(walkways[i]);
	}
	ways.push_back(Walkway(0, corridorLength - totalWalkwayLength, 0));
	sort(ways.begin(), ways.end(), compareWalkway);
	double remainingRunningTime = maxRunningTime;
	double totalTime = 0;
	for(int i=0; i<=numWalkways; i++){
		double wtime = ways[i].getWalkwayTime(walkingSpeed);
		double rtime = ways[i].getWalkwayTime(runningSpeed);
		if(rtime < remainingRunningTime){
			totalTime += rtime;
			remainingRunningTime -= rtime;
		}else if(remainingRunningTime > 0){
			double rLength = ways[i].getRunningLength(runningSpeed, remainingRunningTime);
			remainingRunningTime = 0;
			totalTime += rLength/(runningSpeed+ways[i].getBaseSpeed());
			totalTime += (ways[i].getLength()-rLength)/(walkingSpeed+ways[i].getBaseSpeed());
		}else{
			totalTime += wtime;
		}
	}
	return totalTime;
}

int main(){
	int T, X, S, R, t, N, b, e, w;
	Walkway ways[1000];
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> X >> S >> R >> t >> N;
		for(int j=0; j<N; j++){
			cin >> b >> e >> w;
			ways[j] = Walkway(b,e,w);
		}
		cout << "Case #" << i << ": ";
		printf("%.6f",getTime(X, S, R, t, N, ways));
		cout << endl;
	}
}