#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <functional>
#include <utility>
#include <algorithm>

using namespace std;

bool roundedUp(int people, int total){
    return round(100.*people/total)>(100*people/total);
}

int solve(int N, int L, int* C){
    int totalPercent = 0;
    int peopleRemaining = N;
    vector<pair<int, int>> queue;
    for (int i = 0; i < L; ++i)
    {
        if(roundedUp(C[i], N)){
            totalPercent += round(100.*C[i]/N);
            peopleRemaining -= C[i];
        }else{
            totalPercent += floor(100.*C[i]/N);
            peopleRemaining -= C[i];
            int peopleNeeded = 0;
            while(peopleNeeded <= peopleRemaining){
                if(roundedUp(peopleNeeded+C[i], N)){
                    queue.push_back(make_pair(peopleNeeded, round(100.*(peopleNeeded+C[i])/N) - round(100.*C[i]/N)));
                    break;
                }else{
                    peopleNeeded++;
                }
            }
        }
    }
    //cout << totalPercent << endl;
    //cout << peopleRemaining << endl;
    int maxNeeded = 0;
    pair<int, int> maxPair = make_pair(N, 0);
    while(maxNeeded <= peopleRemaining){
        if(roundedUp(maxNeeded, N)){
            maxPair = make_pair(maxNeeded, round(100.*maxNeeded/N));
            break;
        }else{
            maxNeeded++;
        }
    }

    sort(queue.begin(), queue.end(), greater<pair<int,int>>());
    while(peopleRemaining > 0){ 
        if(queue.empty() && peopleRemaining < maxNeeded){
            totalPercent += round(100.*peopleRemaining/N);
            peopleRemaining = 0;
        }else if(queue.empty()){
            totalPercent += get<1>(maxPair);
            peopleRemaining -= get<0>(maxPair);
        }else{
            pair<int, int> potentialPair = queue.back();
            if(get<0>(potentialPair) > maxNeeded && maxNeeded <= peopleRemaining){
                totalPercent += get<1>(maxPair);
                peopleRemaining -= get<0>(maxPair);
            }else if(get<0>(potentialPair) <= peopleRemaining){
                totalPercent += get<1>(potentialPair);
                peopleRemaining -= get<0>(potentialPair);
            }
            queue.pop_back();
        }
        //cout << peopleRemaining << endl;
    }
    return totalPercent;
}

int main(){
    int T;
    cin >> T;
    for(int i=1; i<=T; i++){
        int N, L;
        int* C = new int[100000];
        cin >> N >> L;
        for(int j=0; j<L; j++){
            cin >> C[j];
        }
        cout << "Case #" << i << ": " << solve(N, L, C) << endl;
    }
}