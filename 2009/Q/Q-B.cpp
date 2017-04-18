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
typedef boost::multi_array<int,2> array_type_int;
typedef array_type_int::index mint;
typedef boost::multi_array<char,2> array_type_char;
typedef array_type_char::index mchar;

void swap(array_type_char& basins, char from, char to, mchar H, mchar W){
	for(mchar h = 0; h < H; h++){
		for(mchar w = 0; w < W; w++){
			if(basins[h][w] == from){
				basins[h][w] = to;
			}
		}
	}
}

void printSolution(const int HEIGHT, const int WIDTH, array_type_int altitudes){
	array_type_char basins(boost::extents[HEIGHT][WIDTH]);
	for(mchar h = 0; h < HEIGHT; h++){
		for(mchar w = 0; w < WIDTH; w++){
			basins[h][w] = '?';
		}
	}

	char currentChar = 'a';

	int N, E, S, W, A;

	for(mint h = 0; h < HEIGHT; h++){
		for(mint w = 0; w < WIDTH; w++){
			mint currentH = h;
			mint currentW = w;

			while(basins[currentH][currentW] == '?'){
				basins[currentH][currentW] = currentChar;
				A = altitudes[currentH][currentW];
				if(currentH == 0){ N = 10001; }
				else{ N = altitudes[currentH-1][currentW];}
				if(currentW == 0){ W = 10001; }
				else{ W = altitudes[currentH][currentW-1];}
				if(currentH == HEIGHT-1){ S = 10001; }
				else{ S = altitudes[currentH+1][currentW];}
				if(currentW == WIDTH-1){ E = 10001; }
				else{ E = altitudes[currentH][currentW+1];}

				if(N < A && N <= W && N <= E && N <= S){
					currentH = currentH-1;
				}else if( W < A && W <= E && W <= S){
					currentW = currentW-1;
				}else if( E < A && E <= S){
					currentW = currentW+1;
				}else if( S < A){
					currentH = currentH+1;
				}
			}

			if(basins[currentH][currentW] < currentChar){
				swap(basins, currentChar, basins[currentH][currentW], HEIGHT, WIDTH);
			}else{
				currentChar++;
			}

		}
	}

	for(mchar height = 0; height < HEIGHT; height++){
		for(mchar weight = 0; weight < WIDTH-1; weight++){
			cout << basins[height][weight] << " ";
		}
		cout << basins[height][WIDTH-1] << endl;
	}
}

int main(){
	int T, H, W;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> H >> W;
		array_type_int altitudes(boost::extents[H][W]);
		for(mint height = 0; height < H; height++){
			for(mint weight = 0; weight < W; weight++){
				cin >> altitudes[height][weight];
			}
		}
		cout << "Case #" << i << ":" << endl;
		printSolution(H,W,altitudes);
	}

}

