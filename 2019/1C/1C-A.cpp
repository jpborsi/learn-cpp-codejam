#include <iostream>
#include <set>
#include <assert.h>

using namespace std;

struct Program{
    string str;
    Program() : str("") {}
    Program(string s) : str(s) {}
    char &operator[] (int i) { return str[i%str.length()]; }
};

const int R=1; 
const int S=2; 
const int P=4;

void solve(int A, Program* opp){
    string result = "";
    set<int> remaining;
    for(int i=0; i<A; i++){
        remaining.insert(i);
    }
    for(int i=0; i<256; i++){
        if(remaining.empty()){
            cout << result << endl;
            return;
        }
        int possible = 0;
        for(int index : remaining){
            switch(opp[index][i]){
                case 'R': possible |= R; break;
                case 'S': possible |= S; break;
                case 'P': possible |= P; break;
            }
        }
        set<int> new_remaining;
        switch(possible){
            case 0: assert(false);
            case R: result += 'P'; remaining.clear(); break;
            case S: result += 'R'; remaining.clear(); break;
            case P: result += 'S'; remaining.clear(); break;
            case R+S: 
                result += 'R';
                for(int index : remaining){
                    if(opp[index][i] == 'R'){ new_remaining.insert(index);}
                }
                remaining = new_remaining;
                break;
            case R+P: result += 'P';
                for(int index : remaining){
                    if(opp[index][i] == 'P'){ new_remaining.insert(index);}
                }
                remaining = new_remaining;
                break;
            case S+P:
                result += 'S';
                for(int index : remaining){
                    if(opp[index][i] == 'S'){ new_remaining.insert(index);}
                }
                remaining = new_remaining;
                break;
            case R+S+P:
                cout << "IMPOSSIBLE" << endl;
                return;
        }
    }
    assert(false);
}

int main(){
    int T, A;
    Program opponents[255];
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> A;
        cout << "Case #" << i << ": ";
        for(int j=0; j<A; j++){
            string s;
            cin >> s;
            opponents[j] = Program(s);
        }
        solve(A, opponents);
    }
}