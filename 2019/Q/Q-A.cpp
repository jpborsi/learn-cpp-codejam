#include <iostream>
#include <string>

using namespace std;

void printAandB(string N){
    string A = "";
    string B = "";
    for(char c: N){
        if(c == '4'){
            A += '2';
            B += '2';
        }else{
            A += c;
            B += '0';
        }
    }
    cout << A << " " << B << endl;
}

int main()
{
	int T;
	string N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		cout << "Case #" << i << ": ";
		printAandB(N);
	}
	return 0;
}