//2019 Round 2, Problem 2

#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <map>
#include <set>

using namespace std;

int get_day(){
    int day;
    cin >> day;
    if(day==-1){exit(1);}
    return day;
}

void solve(){
    int day = get_day();
    assert(day == 1);
    for(int i=0; i<4; ++i){
        int token;
        if(i==0){token=100;}
        else{token=i;}
        for(int vase=1; vase<=15; ++vase){
            cout << vase << " " << token << endl;
            day = get_day();
        }
    }
    assert(day==61);
    map<int, int> vase_sizes;
    map<int, set<int>> vase_contents;
    for(int vase=1; vase<=20; ++vase){
        cout << vase << " " << 0 << endl;
        cin >> vase_sizes[vase];
        for(int i=0; i<vase_sizes[vase]; ++i){
            int token;
            cin >> token;
            vase_contents[vase].insert(token);
        }
        day = get_day();
    }
    int choice1, choice2;
    int min_tokens=100;
    int min2_tokens=101;
    for(int vase=1; vase<=20; ++vase){
        if(vase_sizes[vase] != vase_contents[vase].size()){
            continue;
        }
        if(vase_sizes[vase] <= min_tokens){
            choice2 = choice1;
            min2_tokens = min_tokens;
            choice1 = vase;
            min_tokens = vase_sizes[vase];
        }else if (vase_sizes[vase] <= min2_tokens){
            choice2 = vase;
            min2_tokens = vase_sizes[vase];
        }
    }
    assert(day==81);
    for(int d=81; d<95; ++d){
        int vase_to_sabotage;
        int min_tokens=100;
        for(int vase=1; vase<=20; vase++){
            if(vase==choice1 || vase==choice2){ continue; }
            if(vase_sizes[vase]<=min_tokens){
                vase_to_sabotage = vase;
                min_tokens = vase_sizes[vase];
            }
        }
        int token;
        for(token=1; token<day; token++){
            if(vase_contents[vase_to_sabotage].find(token) == vase_contents[vase_to_sabotage].end()){
                break;
            }
        }
        vase_sizes[vase_to_sabotage]++;
        vase_contents[vase_to_sabotage].insert(token);
        cout << vase_to_sabotage << " " << token << endl;
        day = get_day();
    }
    assert(day==95);
    int n_choice1, n_choice2;
    set<int> tokens1, tokens2;
    cout << choice1 << " " << 0 << endl;
    cin >> n_choice1;
    for(int i=0; i<n_choice1; ++i){
        int t;
        cin >> t;
        tokens1.insert(t);
    }
    day = get_day();
    cout << choice2 << " " << 0 << endl;
    cin >> n_choice2;
    for(int i=0; i<n_choice2; ++i){
        int t;
        cin >> t;
        tokens2.insert(t);
    }
    bool token100_1 = tokens1.find(100) != tokens1.end();
    bool token100_2 = tokens2.find(100) != tokens2.end();
    day = get_day();
    assert(day==97);
    int vase_selection, vase_to_sabotage;
    set<int> tokens_to_sabotage;
    if(n_choice1 + !token100_1 < n_choice2 + !token100_2){
        vase_selection = choice1;
        vase_to_sabotage = choice2;
        tokens_to_sabotage = tokens2;
        if(!token100_1){
            cout << vase_selection << " " << 100 << endl;
            day = get_day();
        }
    }else{
        vase_selection = choice2;
        vase_to_sabotage = choice1;
        tokens_to_sabotage = tokens2;
        if(!token100_2){
            cout << vase_selection << " " << 100 << endl;
            day = get_day();
        }
    }
    for(;day<100;){
        int token;
        for(token=1; token<100; ++token){
            if(tokens_to_sabotage.find(token) == tokens_to_sabotage.end()){
                break;
            }
        }
        cout << vase_to_sabotage << " " << token << endl;
        day = get_day();
    }
    assert(day == 100);
    cout << vase_to_sabotage << " " << 100 << endl;

}

int main(){
    int T;
    cin >> T;
    for(int q=1; q<=T; ++q){
        solve();
    }
}
