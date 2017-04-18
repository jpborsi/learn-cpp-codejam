//2009 Qualification Round, Problem B
//Watersheds
//code.google.com/codejam/contest/90101

/*
Input: 
The first line of the input file will contain the number of maps, T. T maps will follow, each starting with two integers on a line -- H and W -- the height and width of the map, in cells. The next H lines will each contain a row of the map, from north to south, each containing W integers, from west to east, specifying the altitudes of the cells.
*/

/*
Output:
For each test case, output 1+H lines. The first line must be of the form "Case #X:" where X is the test case number, starting from 1. The next H lines must list the basin labels for each of the cells, in the same order as they appear in the input.
*/

#include <iostream>
#include <boost/multi_array.hpp>

using namespace std;
typedef boost::multi_array<int,2> array_type;
typedef array_type::index mindex;

void printSolution(int H, int W, array_type altitudes){
	for(mindex height = 0; height < H; height++){
		for(int weight = 0; weight < W-1; weight++){
			cout << altitudes[height][weight] << " ";
		}
		cout << altitudes[height][W-1] << endl;
	}
}

int main(){
	int T, H, W;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> H >> W;
		array_type altitudes(boost::extents[H][W]);
		for(mindex height = 0; height < H; height++){
			for(mindex weight = 0; weight < W; weight++){
				cin >> altitudes[height][weight];
			}
		}
		cout << "Case #" << T << ":" << endl;
		printSolution(H,W,altitudes);
	}

}

