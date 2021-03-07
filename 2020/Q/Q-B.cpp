#include <iostream>
#include <string>

using namespace std;

string solve(string S){
    string result = "";
    int currentDepth = 0;
    for(char c:S){
        int nextDepth = c - '0';
        for(int i=0; i<nextDepth-currentDepth; ++i){
            result += "(";
        }
        for(int i=0; i<currentDepth-nextDepth; ++i){
            result += ")";
        }
        result += c;
        currentDepth = nextDepth;
    }
    for(int i=currentDepth; i>0; --i){
        result += ")";
    }
    return result;
}

int main()
{
	int T;
    string S;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> S;
		cout << "Case #" << i << ": " << solve(S) << endl;
	}
	return 0;
}