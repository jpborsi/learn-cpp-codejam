#include <iostream>
#include <math.h>
using namespace std;

void getCoords(double A) {
	double theta = acos( 0.5 * (A - sqrt(2-pow(A,2))));
	double x1 = 0.5*sin(theta);
	double y1 = 0.5*cos(theta);
	cout << x1 << ' ' << y1 << ' ' << 0.0 << endl;
	cout << -y1 << ' ' << x1 << ' ' << 0.0 << endl;
	cout << 0.0 << ' ' << 0.0 << ' ' << 0.5 << endl;
}

int main()
{
	int T;
	double A;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> A;
		//if(A > 1.414213){break;}
		cout << "Case #" << i << ": " << endl;
		getCoords(A);
	}
	return 0;
}