#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <utility>

using namespace std;

class Dancer{
private:
	int row, col, skillLevel;
	Dancer *left, *right, *up, *down;

public:
	Dancer() {};
	Dancer(int r, int c, int level): row(r), col(c), skillLevel(level) {};

	bool willBeEliminated() const {
		int sum = 0;
		sum += left ? left->skillLevel : skillLevel;
		sum += right ? right->skillLevel : skillLevel;
		sum += up ? up->skillLevel : skillLevel;
		sum += down ? down->skillLevel : skillLevel;
		return skillLevel*4<sum;
	}

	void eliminate() {
		if(left){
			left->right = right;
		}
		if(right){
			right->left = left;
		}
		if(up){
			up->down = down;
		}
		if(down){
			down->up = up;
		}
	}

	void setNeighbors(Dancer *l, Dancer *r, Dancer *u, Dancer *d){
		left = l;
		right = r;
		up = u;
		down = d;
	}

	long long int interestLevel(){
		return skillLevel;
	}

	vector<Dancer*> neighbors(){
		vector<Dancer*> v;
		if(left){v.push_back(left);}
		if(right){v.push_back(right);}
		if(up){v.push_back(up);}
		if(down){v.push_back(down);}
		return v;
	}

	friend ostream& operator<<(ostream& out, const Dancer& o);
};

ostream& operator<<(ostream& out, const Dancer& d){
	string up = d.up ? to_string(d.up->skillLevel) : "X";
	string left = d.left ? to_string(d.left->skillLevel) : "X";
	string right = d.right ? to_string(d.right->skillLevel) : "X";
	string down = d.down ? to_string(d.down->skillLevel) : "X";
	string elim = d.willBeEliminated() ? "OUT" : "IN";
	return out << d.row << "," << d.col << endl
			   << "    " << up << endl 
			   << left << "   " << d.skillLevel << "    " << right << endl 
			   << "    " << down << endl 
			   << elim << endl;
};

Dancer danceFloor[100000];

class Grid{
private:
	int R, C;
	int loc(int r, int c){
		return r*C + c;
	}
	int valid(int r, int c){
		return (r >= 0) && (r < R) && (c >= 0) && (c < C);
	}

public:
	Grid(int r, int c): R(r), C(c) {};

	void setDancer(int row, int col, int interest){
		danceFloor[loc(row, col)] = Dancer(row, col, interest);
		Dancer *l, *r, *u, *d;
		if(valid(row, col-1)){ l = danceFloor + loc(row, col-1); }
		else{l = nullptr;}
		if(valid(row, col+1)){ r = danceFloor + loc(row, col+1); }
		else{r = nullptr;}
		if(valid(row-1, col)){ u = danceFloor + loc(row-1, col); }
		else{u = nullptr;}
		if(valid(row+1, col)){ d = danceFloor + loc(row+1, col); }
		else{d = nullptr;}
		danceFloor[loc(row, col)].setNeighbors(l, r, u, d);
	}

	set<Dancer*> getDancers(){
		set<Dancer*> v;
		for(Dancer* x = danceFloor; x < danceFloor + R*C; ++x){
			v.insert(x);
		}
		return v;
	}


};

long long int solve(Grid grid){
	//cout << endl;
	set<Dancer*> next = grid.getDancers();
	set<Dancer*> current, eliminate;
	set<Dancer*> remaining = grid.getDancers();
	long long int round = 0;
	long long int totalInterest = 0;
	do {
		round++;
		swap(current, next);
		next.clear();
		eliminate.clear();

		for(Dancer *d : current){
			if(d->willBeEliminated()){
				eliminate.insert(d);
				for(Dancer *n : d->neighbors()){
					next.insert(n);
				}
			}
		}

		for(Dancer *d : eliminate){
			d->eliminate();
			totalInterest += d->interestLevel()*round;
			next.erase(d);
			remaining.erase(d);
		}
		//cout << totalInterest << endl;

	} while(!eliminate.empty());

	for(Dancer *d : remaining){
		totalInterest += d->interestLevel()*round;
	}
	return totalInterest;
}

int main()
{
	int T, R, C, S;
	cin >> T;
	for(int i=1; i<=T; ++i){
		cin >> R >> C;
		Grid grid = Grid(R, C);
		for(int j=0; j<R; ++j){
			for(int k=0; k<C; ++k){
				cin >> S;
				grid.setDancer(j,k,S);
			}
		}
		cout << "Case #" << i << ": " << solve(grid) << endl;
	}
	return 0;
}