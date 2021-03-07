#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

pair<int, pair<int, int>> activities[1000];

int getStart(pair<int, pair<int, int>> x){
	return x.first;
}

int getEnd(pair<int, pair<int, int>> x){
	return x.second.first;
}

int getIndex(pair<int, pair<int, int>> x){
	return x.second.second;
}

string solve(int size){
	string result = "";
	for (int i = 0; i < size; ++i)
	{
		result += "C";
	}
	int cEnd = getEnd(activities[0]);
	int jEnd = 0;
	for (int i = 1; i < size; ++i)
	{
		int currentStart = getStart(activities[i]);
		int currentEnd = getEnd(activities[i]);
		int currentIndex = getIndex(activities[i]);
		//cout << currentStart << " " << cEnd << " " << jEnd << endl;
		if(currentStart >= cEnd){
			result[currentIndex] = 'C';
			cEnd = currentEnd;
		}else if(currentStart >= jEnd){
			result[currentIndex] = 'J';
			jEnd = currentEnd;
		}else{
			return "IMPOSSIBLE";
		}
	}
	return result;
}

int main()
{
	int T;
	int N, S, E;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
        for (int j=0; j<N; j++){
            cin >> S >> E;
            activities[j] = make_pair(S,make_pair(E,j));
        }
        sort(activities, activities+N);
		cout << "Case #" << i << ": " << solve(N) << endl;
	}
	return 0;
}