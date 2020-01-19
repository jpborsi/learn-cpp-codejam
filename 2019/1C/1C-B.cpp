#include <iostream>
#include <map>
#include <set>

using namespace std;

void solve(){
    map<char, set<int>> results;
    for(int i=0; i<595; i+=5){
        char x;
        cout << i+1 << endl;
        cin >> x;
        if(x=='N'){exit(0);}
        results[x].insert(i+1);
    }
    char missingFirst = 'X';
    if(results['A'].size() == 23){
        missingFirst = 'A';
    }else if(results['B'].size() == 23){
        missingFirst = 'B';
    }else if(results['C'].size() == 23){
        missingFirst = 'C';
    }else if(results['D'].size() == 23){
        missingFirst = 'D';
    }else if(results['E'].size() == 23){
        missingFirst = 'E';
    }

    map<char, set<int>> results2;
    for(int i : results[missingFirst]){
        char x;
        cout << i+1 << endl;
        cin >> x;
        if(x=='N'){exit(0);}
        results2[x].insert(i+1);
    }
    char missingSecond = 'X';
    if(results2['A'].size() == 5){
        missingSecond = 'A';
    }else if(results2['B'].size() == 5){
        missingSecond = 'B';
    }else if(results2['C'].size() == 5){
        missingSecond = 'C';
    }else if(results2['D'].size() == 5){
        missingSecond = 'D';
    }else if(results2['E'].size() == 5){
        missingSecond = 'E';
    }

    map<char, set<int>> results3;
    for(int i : results2[missingSecond]){
        char x;
        cout << i+1 << endl;
        cin >> x;
        if(x=='N'){exit(0);}
        results3[x].insert(i+1);
    }

    char missingThird = 'X';
    if(results3['A'].size() == 1){
        missingThird = 'A';
    }else if(results3['B'].size() == 1){
        missingThird = 'B';
    }else if(results3['C'].size() == 1){
        missingThird = 'C';
    }else if(results3['D'].size() == 1){
        missingThird = 'D';
    }else if(results3['E'].size() == 1){
        missingThird = 'E';
    }

    char missingFifth, missingFourth;
    for(int i : results3[missingThird]){
        cout << i+1 << endl;
        cin >> missingFifth;
        if(missingFifth=='N'){exit(0);}
        cout << i+2 << endl;
        cin >> missingFourth;
        if(missingFourth=='N'){exit(0);}
    }
    cout << missingFirst << missingSecond << missingThird << missingFourth << missingFifth << endl;
    char r;
    cin >> r;
    if(r=='N'){exit(0);}

}

int main(){
    int T,F;
    cin >> T >> F;
    for(int i=0; i<T; i++){
        solve();
    }
}