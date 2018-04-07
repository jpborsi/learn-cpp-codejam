#include <iostream>
#include <string>
using namespace std;

void processGarden(bool garden[][20], int A){
	int xlim, ylim;
	if(A==20){
		xlim = 4;
		ylim = 5;
	}else{
		xlim = 10;
		ylim = 20;
	}
	int minFull = 9;
	int bestX = 0;
	int bestY = 0;
	for(int x = 1; x < xlim-1; x++){
		for(int y = 1; y < ylim-1; y++){
			int currentFull = 0;
			currentFull += garden[x][y];
			currentFull += garden[x+1][y];
			currentFull += garden[x-1][y];
			currentFull += garden[x][y+1];
			currentFull += garden[x+1][y+1];
			currentFull += garden[x-1][y+1];
			currentFull += garden[x][y-1];
			currentFull += garden[x+1][y-1];
			currentFull += garden[x-1][y-1];
			if(currentFull < minFull){
				minFull = currentFull;
				bestX = x;
				bestY = y;
			}
		}
	}
	int translatedX = 100+bestX;
	int translatedY = 100+bestY;
	cout << translatedX << ' ' << translatedY << endl;
}

int main()
{
	int T, A, I, J;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A;
		bool garden[10][20] = {{false}};
		processGarden(garden, A);
		while(true){
			cin >> I;
			cin >> J;
			if( I==-1 && J==-1 ){
				return 1;
			}
			if( I==0 && J==0 ){
				break;
			}
			garden[I-100][J-100] = true;
			processGarden(garden, A);
		}
	}
	return 0;
}