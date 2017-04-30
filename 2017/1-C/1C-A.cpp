//2017 Round 1-C, Problem A

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <utility>
#include <boost/math/constants/constants.hpp>

const double pi = boost::math::constants::pi<double>();

using namespace std;

void getMaxSA(int N, int K, vector<int> radius, vector<int> height){

	vector<pair<int,double> > radius_sorted;
	for(int i =0;i<N;i++){
		radius_sorted.push_back(make_pair(radius[i],2*pi*radius[i]*height[i]));
	}
	sort(radius_sorted.begin(),radius_sorted.end());
	reverse(radius_sorted.begin(),radius_sorted.end());

	double result = 0;
	for(int i=0;i<N-K+1;i++){
		double bottom_area, vertical_area;
		bottom_area = pi*get<0>(radius_sorted[i])*get<0>(radius_sorted[i])+get<1>(radius_sorted[i]);
		vector<double> possible_areas;
		for(int j =i+1; j<N; j++){
			possible_areas.push_back(get<1>(radius_sorted[j]));
		}
		sort(possible_areas.begin(),possible_areas.end());
		reverse(possible_areas.begin(),possible_areas.end());
		vertical_area = 0;
		if(possible_areas.size() < K-1){
			break;
		}
		for(int i=0; i<K-1; i++){
			vertical_area += possible_areas[i];
		}

		if(bottom_area+vertical_area > result){
			result = bottom_area + vertical_area;
		}

	}
	// double max_bottom = 0;
	// int max_index = -1;
	// int corresponding_height = -1;
	// vector<double> side_height;
	// for(int i =0; i< N;i++){
	// 	double this_bottom = pi*radius[i]*radius[i] + 2*pi*radius[i]*height[i];
	// 	if(this_bottom > max_bottom){
	// 		max_bottom = this_bottom;
	// 		max_index = i;
	// 		corresponding_height = height[i];
	// 	}else if(this_bottom == max_bottom && height[i]<corresponding_height){
	// 		max_index = i;
	// 		corresponding_height = height[i];
	// 	}
	// 	side_height.push_back(2*pi*height[i]*radius[i]);
	// }
	// //cout << max_bottom << " " << corresponding_height << endl;
	// double totalSA = 0.0;
	// totalSA += max_bottom;
	// side_height.erase(side_height.begin()+max_index);
	// sort(side_height.begin(),side_height.end());
	// reverse(side_height.begin(),side_height.end());
	// for(int i = 0;i<K-1;i++){
	// 	totalSA += side_height[i];
	// }

	char out[50];
	sprintf(out,"%.6f",result);
	cout << out;
}

int main(){
	int T;
	int K,N;
	int r,h;
	vector<int> radius,height;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> N >> K;
		radius.clear();
		height.clear();
		for(int j=0;j<N;j++){
			cin >> r >> h;
			radius.push_back(r);
			height.push_back(h);
		}
		cout << "Case #" << i << ": ";
		getMaxSA(N,K,radius,height);
		cout << endl;
	}
}