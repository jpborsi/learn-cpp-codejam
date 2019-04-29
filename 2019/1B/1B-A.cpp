#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int solve(vector<pair<int, bool>> people, int Q){
    sort(people.begin(), people.end());
    int count_up = 0;
    int count_down = people.size() - count_if(people.begin(), people.end(), [](pair<int, bool> i){return i.second;});

    int current_street = 0;
    int max_street = 0;
    int max_people = count_down;
    int next_up = 0;
    int next_down = 0;
    for(pair<int, bool> person : people){
        if(person.first == current_street && person.second){
            next_up++;
        }else if(person.first == current_street+1 && !person.second){
            next_down++;
        }else if(person.first == current_street && !person.second){
            count_down--;
        }else{
            if(count_down - next_down + count_up + next_up > max_people){
                max_people = count_down - next_down + count_up + next_up;
                max_street = current_street + 1;
            }
            count_down -= next_down;
            count_up += next_up;
            next_up = person.second;
            count_down -= !person.second;
            next_down = 0;
            current_street = person.first;
        }
    }
    if((max_street < Q) && (count_down - next_down + count_up + next_up > max_people)){
        max_street = current_street+1;
    }
    return max_street;
}

int main(){
    int T, P, Q, x, y;
    char dir;
    vector<pair<int, bool>> ns, ew;
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> P >> Q;
        for(int j=0; j<P; j++){
            cin >> x >> y >> dir;
            if(dir=='N'||dir=='S'){
                ns.push_back(make_pair(y,dir=='N'));
            }else{
                ew.push_back(make_pair(x,dir=='E'));
            }
        }
        cout << "Case #" << i << ": "
            << solve(ew, Q) << " " << solve(ns, Q) << endl;
        ns.clear();
        ew.clear();
    }
}