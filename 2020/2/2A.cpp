#include <iostream>
#include <cmath>

using namespace std;

void solve(long long int L, long long int R){
	long long int excess = abs(L-R);
	long long int init_customers = floor(sqrt(8*excess+1)/2 - 0.5);
	long long int init_stack = (init_customers * init_customers + init_customers)/2;

	if(L>=R){L=L-init_stack;}
	else{R=R-init_stack;}
	//cout << R << endl;

	long long int L_customers, L_remaining, R_customers, R_remaining;

	if(L>=R){
		L_customers = floor(sqrt(L + 1.*init_customers*init_customers/4) - 1.*init_customers/2);
		L_remaining = L - (L_customers*(L_customers+init_customers));
		R_customers = floor(sqrt(R + 1.*(init_customers+1)*(init_customers+1)/4) - 1.*(init_customers+1)/2);
		R_remaining = R - (R_customers*R_customers + (init_customers+1)*R_customers);
	}else{
		R_customers = floor(sqrt(R + 1.*init_customers*init_customers/4) - 1.*init_customers/2);
		R_remaining = R - (R_customers*(R_customers+init_customers));
		L_customers = floor(sqrt(L + 1.*(init_customers+1)*(init_customers+1)/4) - 1.*(init_customers+1)/2);
		L_remaining = L - (L_customers*L_customers + (init_customers+1)*L_customers);
	}
	long long int total_customers = init_customers + L_customers + R_customers;
	//cout << init_customers << " " << L_customers << " " << R_customers << endl;
	cout << total_customers << " " << L_remaining << " " << R_remaining << endl;
}

int main(){
	int T;
	long long int L,R;
	cin >> T;
	for(int i=1;i<=T;++i){
		cin >> L >> R;
		cout << "Case #" << i << ": ";
		solve(L, R);
	}
}