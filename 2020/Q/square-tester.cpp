#include <iostream>

using namespace std;

int main(){
	int rows[24][4] = {{1,2,3,4},{1,2,4,3},{1,3,2,4},{1,3,4,2},{1,4,2,3},{1,4,3,2},
					   {2,1,3,4},{2,1,4,3},{2,3,1,4},{2,3,4,1},{2,4,1,3},{2,4,3,1},
					   {3,1,2,4},{3,1,4,2},{3,2,1,4},{3,2,4,1},{3,4,1,2},{3,4,2,1},
					   {4,1,2,3},{4,1,3,2},{4,2,1,3},{4,2,3,1},{4,3,1,2},{4,3,2,1}};

	for(int row1 = 0; row1 < 24; ++row1){
		for(int row2 = 0; row2 < 24; ++row2){
			if(row1 == row2){continue;}
			if(rows[row1][0] == rows[row2][0] || rows[row1][1] == rows[row2][1] || rows[row1][2] == rows[row2][2] || rows[row1][3] == rows[row2][3]){
				continue;
			}
			for(int row3 = 0; row3 < 24; ++row3){
				if(row1 == row3 || row2 == row3){
					continue;
				}
				if(rows[row1][0] == rows[row3][0] || rows[row2][0] == rows[row3][0]){
					continue;
				}
				if(rows[row1][1] == rows[row3][1] || rows[row2][1] == rows[row3][1]){
					continue;
				}
				if(rows[row1][2] == rows[row3][2] || rows[row2][2] == rows[row3][2]){
					continue;
				}
				if(rows[row1][3] == rows[row3][3] || rows[row2][2] == rows[row3][3]){
					continue;
				}
				for(int row4 = 0; row4 < 24; ++row4){
					if(row1 == row4 || row2 == row4 || row3 == row4){
						continue;
					}
					if(rows[row1][0] == rows[row4][0] || rows[row2][0] == rows[row4][0] || rows[row3][0] == rows[row4][0]){
					continue;
					}
					if(rows[row1][1] == rows[row4][1] || rows[row2][1] == rows[row4][1] || rows[row3][1] == rows[row4][1]){
						continue;
					}
					if(rows[row1][2] == rows[row4][2] || rows[row2][2] == rows[row4][2] || rows[row3][2] == rows[row4][2]){
						continue;
					}
					if(rows[row1][3] == rows[row4][3] || rows[row2][3] == rows[row4][3] || rows[row3][3] == rows[row4][3]){
						continue;
					}
					int trace = rows[row1][0] + rows[row2][1] + rows[row3][2] + rows[row4][3];
					cout << rows[row1][0] << " " << rows[row1][1] << " " << rows[row1][2] << " " << rows[row1][3] << endl;
					cout << rows[row2][0] << " " << rows[row2][1] << " " << rows[row2][2] << " " << rows[row2][3] << endl;
					cout << rows[row3][0] << " " << rows[row3][1] << " " << rows[row3][2] << " " << rows[row3][3] << endl;
					cout << rows[row4][0] << " " << rows[row4][1] << " " << rows[row4][2] << " " << rows[row4][3] << endl;
					cout << "TRACE: " << trace << endl;
				}
			}
		}
	}
}