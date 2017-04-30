//2017 Round 1C, Problem B

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int getMinExchanges(int AC, int AJ, vector<pair<int, int>> cameron, std::vector<pair<int,int>> jamie){
	sort(cameron.begin(),cameron.end());
	sort(jamie.begin(), jamie.end());
	int required_switches = 0;
	int ctime = 0, jtime = 0;
	vector<int> timeForCorJwithNoAdditionalSwitches;
	vector<int> timeForCWithAdditionalSwitch;
	vector<int> timeForJWithAdditionalSwitch;
	vector<int> timeForCWith2Switches;
	vector<int> timeForJWith2Switches;
	int cindex = 0, jindex = 0;
	int current = 0, first = 0, last = 0;
	if(AJ == 0 && AC == 0){
		return 2;
	}else if(AJ == 0){
		current = 1;
		first = 1;
		last = 1;
	}else if(AC == 0){
		current = 0;
		last = 1;
		first = 1;
	}else if(get<1>(jamie[AJ])>get<1>(cameron[AC])){
		current = 1;
		last = 1;
		if(get<1>(jamie[0])>get<1>(cameron[0])){
			first = 0;
		}else{
			first = 1;
		}
	}else{
		current = 0;
		last = 0;
		if(get<1>(jamie[0])>get<1>(cameron[0])){
			first = 0;
		}else{
			first = 1;
		}
	}
	// if(first!=last){
	// 	required_switches++;
	// }
	int m = 0;
	int firstOffset=0;
	int lastOffset=0;
	while(m<1440){
		int nextC, nextJ;
		if(cindex<AC){
			nextC = get<0>(cameron[cindex]);
		}else{
			nextC = 1440;
		}

		if(jindex<AJ){
			nextJ = get<0>(jamie[jindex]);
		}else{
			nextJ = 1440;
		}
		//cout << m << " " << nextC << " " << nextJ << endl;
		if(m==nextC && current == 1){
			jtime += get<1>(cameron[cindex])-get<0>(cameron[cindex]);
			m = get<1>(cameron[cindex]);
			cindex++;
		}else if(m==nextC && current ==0){
			required_switches++;
			jtime += get<1>(cameron[cindex])-get<0>(cameron[cindex]);
			m = get<1>(cameron[cindex]);
			cindex++;
			current = 1;
		}else if(m==nextC && current ==-1){
			jtime += get<1>(cameron[cindex])-get<0>(cameron[cindex]);
			m = get<1>(cameron[cindex]);
			cindex++;
			current = 1;
		}else if(m==nextJ && current == 0){
			ctime += get<1>(jamie[jindex])-get<0>(jamie[jindex]);
			m = get<1>(jamie[jindex]);
			jindex++;
		}else if(m==nextJ && current==1){
			required_switches++;
			ctime += get<1>(jamie[jindex])-get<0>(jamie[jindex]);
			m = get<1>(jamie[jindex]);
			jindex++;
			current=0;
		}else if(m==nextJ && current==-1){
			ctime += get<1>(jamie[jindex])-get<0>(jamie[jindex]);
			m = get<1>(jamie[jindex]);
			jindex++;
			current=0;
		}else if(nextC < nextJ && cindex == 0 && jindex == 0){
			firstOffset = nextC-m;
			m = nextC;
		}else if(nextC < nextJ && current == 1){
			timeForCWith2Switches.push_back(nextC-m);
			m = nextC ;
		}else if(nextC < nextJ && current == 0){
			timeForCorJwithNoAdditionalSwitches.push_back(nextC-m);
			m = nextC;
		}else if(nextJ < nextC && cindex == 0 && jindex == 0){
			firstOffset = nextJ-m;
			m=nextJ;
		}else if(nextJ < nextC && current == 1){
			timeForCorJwithNoAdditionalSwitches.push_back(nextJ-m);
			m = nextJ;
		}else if(nextJ < nextC && current == 0){
			timeForJWith2Switches.push_back(nextJ-m);
			m = nextJ;
		}else if(nextJ == nextC && current == -1){
			return 1;
		}else if(nextJ == nextC){
			lastOffset = nextJ -m;
			m=1441;
		}
	}

	if(first==last && last == 1){
		timeForCWith2Switches.push_back(firstOffset+lastOffset);
	}else if(first==last && last == 0){
		timeForJWith2Switches.push_back(firstOffset+lastOffset);
	}else{
		timeForCorJwithNoAdditionalSwitches.push_back(firstOffset+lastOffset);
		required_switches++;
	}

	int defaultCtime = 0, defaultJtime=0;
	for(int i : timeForJWithAdditionalSwitch){
		//cout << "j+1 " << i << endl;
		defaultCtime+=i;
	}
	for(int i : timeForJWith2Switches){
		//cout << "j+2 " << i << endl;
		defaultCtime+=i;
	}
	for(int j : timeForCWithAdditionalSwitch){
		//cout << "c+1 " << j << endl;
		defaultJtime+=j;
	}
	for(int j : timeForCWith2Switches){
		//cout << "c+2 " << j << endl;
		defaultJtime+=j;
	}
	if(ctime+defaultCtime>720){
		sort(timeForJWithAdditionalSwitch.begin(), timeForJWithAdditionalSwitch.end());
		reverse(timeForJWithAdditionalSwitch.begin(), timeForJWithAdditionalSwitch.end());
		for(int i : timeForJWithAdditionalSwitch){
			defaultCtime -= i;
			required_switches++;
			if(ctime+defaultCtime<=720){
				return required_switches;
			}
		}
		sort(timeForJWith2Switches.begin(), timeForJWith2Switches.end());
		reverse(timeForJWith2Switches.begin(), timeForJWith2Switches.end());
		for(int i : timeForJWith2Switches){
			defaultCtime -= i;
			required_switches+= 2;
			if(ctime+defaultCtime<=720){
				return required_switches;
			}
		}

	}else if(jtime+defaultJtime>720){
		sort(timeForCWithAdditionalSwitch.begin(), timeForCWithAdditionalSwitch.end());
		reverse(timeForCWithAdditionalSwitch.begin(), timeForCWithAdditionalSwitch.end());
		for(int i : timeForCWithAdditionalSwitch){
			defaultJtime -= i;
			required_switches++;
			if(jtime+defaultJtime<=720){
				return required_switches;
			}
		}
		sort(timeForCWith2Switches.begin(), timeForCWith2Switches.end());
		reverse(timeForCWith2Switches.begin(), timeForCWith2Switches.end());
		for(int i : timeForCWith2Switches){
			defaultJtime -= i;
			required_switches+= 2;
			if(jtime+defaultJtime<=720){
				return required_switches;
			}
		}
	}else{
		return required_switches;
	}
}

int main(){
	int T;
	int AC, AJ;
	int start, end;
	vector<pair<int, int> > cameron, jamie;
	cin >> T;
	for(int i = 1; i <= T; i++){
		cin >> AC >> AJ;
		cameron.clear();
		jamie.clear();
		for(int c=0; c<AC;c++){
			cin >> start >> end;
			cameron.push_back(make_pair(start,end));
		}
		for(int j=0;j<AJ;j++){
			cin >> start >> end;
			jamie.push_back(make_pair(start,end));
		}
		cout << "Case #" << i << ": " << getMinExchanges(AC,AJ,cameron,jamie) << endl;
	}
}