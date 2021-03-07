#include <iostream>
#include <utility>

using namespace std;

const int MAX_SIZE = 51;
int fwd[MAX_SIZE];
int bwd[MAX_SIZE];

void complement(){
    for (int i = 0; i < MAX_SIZE; ++i)
    {
        fwd[i] = 1 - fwd[i];
        bwd[i] = 1 - bwd[i];
    }
}

void validate(int firstSame, int firstDifferent){
    int F;
    bool S,D;
    //verification
    if(firstSame != 0){
        cout << firstSame << endl;
        cin >> F;
        S = (F == fwd[firstSame]);
    }else{
        cout << 1 << endl;
        cin >> F;
        S = true;
    }

    if(firstDifferent != 0){
        cout << firstDifferent << endl;
        cin >> F;
        D = (F == fwd[firstDifferent]);
    }else{
        cout << 1 << endl;
        cin >> F;
        D = true;
    }

    if(S && D){
        //do nothing
    }else if(S && !D){
        swap(fwd, bwd);
    }else if(!S && D){
        complement();
        swap(fwd, bwd);
    }else if(!S && !D){
        complement();
    }
}

void output(int size){
    for (int i = 1; i <= size/2; ++i)
    {
        cout << fwd[i];
    }
    for(int i = size/2; i >= 1; --i)
    {
        cout << bwd[i];
    }
    cout << endl;
    char c;
    cin >> c;
    if(c!='Y'){
         exit(1);
    }
    return;
}

void solve(int size){
    int F, B;
    int firstSame = 0;
    int firstDifferent = 0;
    //1st 10 queries
    for(int i = 1; i<=5; ++i){
        cout << i << endl;
        cin >> F;
        fwd[i] = F;
        cout << size+1-i << endl;
        cin >> B;
        bwd[i] = B;
        if(firstSame == 0 && F==B){
            firstSame = i;
        }
        if(firstDifferent == 0 && F!=B){
            firstDifferent = i;
        }
    }
    if(size==10){
        output(size);
        return;
    }
    //2nd 10 queries
    validate(firstSame, firstDifferent);
    for(int i = 6; i<=9; ++i){
        cout << i << endl;
        cin >> F;
        fwd[i] = F;
        cout << size+1-i << endl;
        cin >> B;
        bwd[i] = B;
        if(firstSame == 0 && F==B){
            firstSame = i;
        }
        if(firstDifferent == 0 && F!=B){
            firstDifferent = i;
        }
    }

    //3rd 10 queries
    //verification
    validate(firstSame, firstDifferent);

    for(int i = 10; i<=13; ++i){
        cout << i << endl;
        cin >> F;
        fwd[i] = F;
        cout << size+1-i << endl;
        cin >> B;
        bwd[i] = B;
        if(firstSame == 0 && F==B){
            firstSame = i;
        }
        if(firstDifferent == 0 && F!=B){
            firstDifferent = i;
        }
        if(size==20){
            output(size);
            return;
        }
    }

    //4th through 12th 10 queries
    for(int start = 14; start <= 46; start += 4){
        //verification
        validate(firstSame, firstDifferent);

        for(int i = start; i<=start+3; ++i){
            cout << i << endl;
            cin >> F;
            fwd[i] = F;
            cout << size+1-i << endl;
            cin >> B;
            bwd[i] = B;
            if(firstSame == 0 && F==B){
                firstSame = i;
            }
            if(firstDifferent == 0 && F!=B){
                firstDifferent = i;
            }
        }      
    }

    //final queries
    //verification
    validate(firstSame, firstDifferent);
    cout << 50 << endl;
    cin >> F;
    fwd[50] = F;
    cout << 51 << endl;
    cin >> B;
    bwd[50] = B;
    output(size);
}

int main()
{
	int T, B;
	cin >> T >> B;
	for (int i = 1; i <= T; i++) {
		solve(B);
	}
	return 0;
}