//2019 Round 2, Problem 3

#include <iostream>
#include <utility>
#include <vector>

using namespace std;

typedef pair<int, int> molecule;

bool sorted(int C, int J, vector<molecule> mols){
    for(int i=0; i<mols.size()-1; i++){
        long long int A = mols[i].first*C + mols[i].second*J;
        long long int B = mols[i+1].first*C + mols[i+1].second*J;
        if(B<=A){return false;}
    }
    return true;
}

void solve(int N, vector<molecule> mols){
    for(int C=1; C<=1000; C++){
        for(int J=1; J<=1000; J++){
            if(sorted(C,J,mols)){
                cout << C << " " << J;
                return;
            }
        }
    }
    cout << "IMPOSSIBLE";
    return;
}

int main(){
    int T, N, C, J;
    cin >> T;
    for(int q=1; q<=T; ++q){
        vector<molecule> mols;
        cin >> N;
        for(int i=0; i<N; ++i){
            cin >> C >> J;
            mols.push_back(make_pair(C, J));
        }
        cout << "Case #" << q << ": ";
        solve(N, mols);
        cout << endl;
    }
}