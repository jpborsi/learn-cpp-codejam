#include <iostream>
#include <unordered_set>

using namespace std;

const int MAX_SIZE = 100;
int M[MAX_SIZE][MAX_SIZE];

void solveMatrix(int size){
    int trace = 0;
    for (int i = 0; i < size; ++i)
    {
        trace += M[i][i];
    }

    cout << trace << " ";

    int rowsWithDuplicates = 0;
    for (int row = 0; row < size; ++row)
    {
        unordered_set<int> rowValues;
        for(int col = 0; col < size; ++col){
            rowValues.insert(M[row][col]);
        }
        if(rowValues.size() != size){
            rowsWithDuplicates++; 
        }
    }

    cout << rowsWithDuplicates << " ";

    int colsWithDuplicates = 0;
    for (int col = 0; col < size; ++col)
    {
        unordered_set<int> colValues;
        for(int row = 0; row < size; ++row){
            colValues.insert(M[row][col]);
        }
        if(colValues.size() != size){
            colsWithDuplicates++; 
        }
    }

    cout << colsWithDuplicates << endl;

}

int main()
{
	int T;
	int N;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N;
		for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < N; ++k)
            {
                int value;
                cin >> value;
                M[j][k] = value;
            }
        }
        cout << "Case #" << i << ": ";
        solveMatrix(N);
	}
	return 0;
}