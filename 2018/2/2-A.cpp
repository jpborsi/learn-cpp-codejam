#include <iostream>

using namespace std;

void solve(int C, int* B){
    if(B[0] == 0 || B[C-1] == 0){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    int maxDistance = 0;
    int source = -1;
    int* destination = new int[C];
    for(int dest=0; dest<C; dest++){
        for(int j=0; j<B[dest]; j++){
            source++;
            destination[source] = dest;
            if(abs(dest-source) > maxDistance){
                maxDistance = abs(dest-source);
            }
        }
    }

    cout << (maxDistance+1) << endl;

    for(int row=0; row<=maxDistance; row++){
        for(int col=0; col<C; col++){
            if(destination[col] == col){
                cout << ".";
            }else if(col-row >= 0 && destination[col-row] > col){
                cout << "\\";
            }else if(col+row < C && destination[col+row] < col){
                cout << "/";
            }else{
                cout << ".";
            }
        }
        cout << endl;
    }
}

int main(){
    int T, C;
    int* B = new int[100];
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> C;
        for(int j=0;j<C;j++){
            cin >> B[j];
        }
        cout << "Case #" << i << ": ";
        solve(C, B);
    }
}