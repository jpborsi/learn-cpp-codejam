#include <iostream>
#include <vector>
#include <array>
#include <tuple>
#include <algorithm>

using namespace std;

vector<vector<int>> prepare(){
    vector<tuple<int, int, int>> v;
    for(int i=0; i<=32; i++){
        for(int j=0; j<=32; j++){
            if((i==0 && j==0) || i+j > 32 ){ continue; }
            //cout << i << " " << j << endl;
            v.push_back(make_tuple(i+j,i,j));
        }
    }
    sort(v.begin(), v.end());
    //cout << v.size() << endl;
    vector<vector<int>> result, next_table;
    for(int r = 0; r<=500; r++){
        vector<int> v, w;
        result.push_back(v);
        next_table.push_back(w);
        for(int b=0; b<=500; b++){
            result[r].push_back(0);
            next_table[r].push_back(0);
        }
    }
    for(tuple<int, int, int> a: v){
        //cout << get<1>(a) << " " << get<2>(a) << endl;
        for(int r = 0; r<=500; r++){
            for(int b=0; b<=500; b++){
                if(r+get<1>(a) >= 500 || b+get<2>(a) >= 500){
                    continue;
                }
                next_table[r+get<1>(a)][b+get<2>(a)] = max(result[r+get<1>(a)][b+get<2>(a)], 1+result[r][b]);
            }
        }
        for(int r=0; r<=500; r++){
            for(int b=0; b<=500; b++){
                next_table[r][b] = max(next_table[r][b], result[r][b]);
                if(r>0){
                    next_table[r][b] = max(next_table[r][b], result[r-1][b]);
                }
                if(b>0){
                    next_table[r][b] = max(next_table[r][b], result[r][b-1]);
                }
                if(r>0 && b>0){
                    next_table[r][b] = max(next_table[r][b], result[r-1][b-1]);
                }
            }
        }
        result = next_table;
    }
    return result;
}

int solve(int R, int B, vector<vector<int>> table){
    return table[R][B];
}

int main(){
    int T, R, B;
    cin >> T;
    vector<vector<int>> table = prepare();
    for(int i=1; i<=T; i++){
        cin >> R >> B ;
        cout << "Case #" << i << ": " << solve(R, B, table) << endl;
    }
}