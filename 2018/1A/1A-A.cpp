//2018 Round 1A, Problem A
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPossible(int R, int C, int H, int V, char waffle[][100]){
	int numCustomers = (H+1)*(V+1);
	int numChips = 0;
	for(int r = 0; r<R; r++){
		for(int c = 0; c<C; c++){
			numChips += (waffle[r][c] == '@');
		}
	}
	if(numChips % numCustomers != 0){
		return false;
	}

	//cout << "Validating numbers..." << endl;

	int numChipsPerHorizontalSlice = numChips/(H+1);
	int numChipsInCurrentSlice = 0;
	vector<int> hslices;
	hslices.push_back(0);
	for(int r = 0; r< R; r++){
		if(numChipsInCurrentSlice == numChipsPerHorizontalSlice){
			hslices.push_back(r);
			numChipsInCurrentSlice = 0;
		}else if(numChipsInCurrentSlice > numChipsPerHorizontalSlice){
			return false;
		}
		for(int c = 0; c<C; c++){
			numChipsInCurrentSlice += (waffle[r][c] == '@');
		}
	}
	hslices.push_back(R);

	//cout << "Validating horizontal slices..." << endl;

	int numChipsPerVerticalSlice = numChips/(V+1);
	numChipsInCurrentSlice = 0;
	vector<int> vslices;
	vslices.push_back(0);
	for(int c = 0; c<C; c++){
		if(numChipsInCurrentSlice == numChipsPerVerticalSlice){
			vslices.push_back(c);
			numChipsInCurrentSlice = 0;
		}else if(numChipsInCurrentSlice > numChipsPerVerticalSlice){
			return false;
		}
		for(int r = 0; r<R; r++){
			numChipsInCurrentSlice += (waffle[r][c] == '@');
		}
	}
	vslices.push_back(C);

	//cout << "Validating vertical slices..." << endl;
	//verify correct cuts
	int numChipsPerCustomer = numChips/((H+1)*(V+1));
	for(int h = 1; h<=H+1; h++){
		for(int v = 1; v<=V+1; v++){
			//cout << "Checking slice: (" << hslices[h] << "," << vslices[v] << ")" << endl;
			numChipsInCurrentSlice = 0;
			for(int r = hslices[h-1]; r<hslices[h]; r++){
				for(int c = vslices[v-1]; c<vslices[v]; c++){
					numChipsInCurrentSlice += (waffle[r][c] == '@');
				}
			}
			if(numChipsInCurrentSlice != numChipsPerCustomer){
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int T, R, C, H, V;
	char waffle[100][100];
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> R >> C >> H >> V;
		string row;
		for(int r = 0; r < R; r++ ){
			cin >> row;
			for(int c = 0; c < C; c++){
				waffle[r][c] = row[c];
			}
		}
		cout << "Case #" << i << ": ";
		bool possible = isPossible(R,C,H,V,waffle);
		if(possible){cout << "POSSIBLE" << endl;}
		else{cout << "IMPOSSIBLE" << endl;}
	}
	return 0;
}