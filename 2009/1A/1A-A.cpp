//Round 1A 2009
//Problem A. Multi-base happiness
//https://code.google.com/codejam/contest/188266/dashboard

/* Input:
The first line of input gives the number of cases T. T test cases follow. Each case consists of a single line. Each line contains a space separated list of distinct integers, representing the bases. The list of bases is always in increasing order.

Output:
For each test case, output:
Case #X: K
where X is the test case number, starting from 1, and K is the decimal representation of the smallest integer (greater than 1) which is happy in all of the given bases.
*/

#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <sstream>

using namespace std;

vector<set<long> > happySets(11);
vector<set<long> > unhappySets(11);

int nextNum(long num, int base){
	string s;
	long nextNum = 0;
	long l = 1;
	long remainder = num;
	while(l <= num){
		l *= base;
		//cout << l << remainder << endl;
		int currentDigit = (remainder % l)/(l/base);
		nextNum += currentDigit*currentDigit;
		remainder = remainder - (remainder%l) / l;
	}
	return nextNum;
}

bool memo(long num, int base, set<long> currentChain){
	set<long> happySet = happySets[base];
	set<long> unhappySet = happySets[base];
	currentChain.insert(num);

	if(happySet.find(num) != happySet.end()){
		for(set<long>::iterator i = currentChain.begin(); i != currentChain.end(); ++i){
			happySet.insert(*i);
		}
		return true;
	}else if(unhappySet.find(num) != unhappySet.end()){
		for(set<long>::iterator i = currentChain.begin(); i != currentChain.end(); ++i){
			unhappySet.insert(*i);
		}
		return false;
	}else if(currentChain.find(num) != currentChain.end()){
		for(set<long>::iterator i = currentChain.begin(); i != currentChain.end(); ++i){
			unhappySet.insert(*i);
		}
		return false;
	}else{
		long next = nextNum(num, base);
		if(next == 1){
			for(set<long>::iterator i = currentChain.begin(); i != currentChain.end(); ++i){
				happySet.insert(*i);
			}
			return true;
		}else{
			return memo(next, base, currentChain);
		}
	}
}

bool memo(long num, int base){
	set<long> happySet = happySets[base];
	set<long> unhappySet = happySets[base];

	if(happySet.find(num) != happySet.end()){
		return true;
	}else if(unhappySet.find(num) != unhappySet.end()){
		return false;
	}else{
		long next = nextNum(num, base);
		if(next == 1){
			happySet.insert(num);
			return true;
		}else{
			set<long> currentChain;
			currentChain.insert(num);
			return memo(next, base, currentChain);
		}
	}

}

int main(){
	// cout << 3 << endl;
	// cout << nextNum(3,2) << endl;
	// cout << nextNum(2,2) << endl;
	// cout << 143 << endl;
	// cout << nextNum(143, 7) << endl;
	// cout << nextNum(49, 7) << endl;
	// cout << 91 << endl;
	// cout << nextNum(91,9) << endl;
	// cout << nextNum(3,9) << endl;
	long i = 2;
	while(i <= 1000){
		for(int j=2;j<=10;j++){
			memo(i,j);
		}
		i++;
	}

	int T;
	cin >> T;
	string line;
	getline(cin, line);
	for(int i = 1; i <= T; i++){
		set<int> bases;
		getline(cin, line);
		istringstream iss(line);
		int c;
		long j;
		while( iss >> c){
			bases.insert(c);
		}
		for(j = 2; j < 12000000; j++){
			bool yes = true;
			for(int b : bases){
				if(!memo(j,b)){
					yes = false;
				}
			}
			if(yes){
				break;
			}
		}
		cout << "Case #" << i << ": " << j << endl;
	}

	// }

	// cout << i << endl;


}