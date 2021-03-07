//2019 Round 2, Problem 1

#include <iostream>
#include <set>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Molecule;
typedef pair<int, int> Ratio;
constexpr Ratio FIXED = make_pair(0,1);

Ratio make_ratio(int c, int j){
    int gcd = __gcd(c, j);
    return make_pair(c/gcd, j/gcd);
}

Ratio ratio(Molecule a, Molecule b){
    if(a.first == b.first || a.second == b.second){ return FIXED; }
    if(a.first > b.first && a.second > b.second){ return FIXED; }
    if(a.first < b.first && a.second < b.second){ return FIXED; }
    int c_diff = abs(a.first - b.first);
    int j_diff = abs(a.second - b.second);
    return make_ratio(c_diff, j_diff);
}

int solve(vector<Molecule> molecules){
    set<Ratio> r;
    r.insert(FIXED);
    for (int i = 0; i < molecules.size(); i++){
        for (int j = i+1; j < molecules.size(); j++){
            r.insert(ratio(molecules[i],molecules[j]));
        }
    }
    return r.size();
}

int main(){
    int T, N, C, J;
    cin >> T;
    for (int q = 1; q <= T; q++){
        cin >> N;
        vector<Molecule> m;
        for (int i = 0; i < N; i++){
            cin >> C >> J;
            m.push_back(make_pair(C,J));
        }
        cout << "Case #" << q << ": " << solve(m) << endl;
        
    }
    
}