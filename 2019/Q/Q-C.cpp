#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

string decipher(string N, int L, string* ciphertext){
    return "CJQUIZ";
}

int main()
{
	int T;
	string N;
    int L;
	cin >> T;
    string* ciphertext = new string[101];
	for (int i = 1; i <= T; i++) {
		cin >> N;
        cin >> L;
        for (int i=0; i<L; i++){
            cin >> ciphertext[i];
        }
		cout << "Case #" << i << ": " << decipher(N, L, ciphertext) << endl;
	}
	return 0;
}