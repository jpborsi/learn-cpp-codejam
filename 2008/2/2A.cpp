//2008 Round 2, Problem A

#include <iostream>

#define tc(t) for(int i=1;i<=t;++i)
#define f(n) for(int j=0;j<n;++j)


using namespace std;

class Node{
	bool changeable, isAnd, isLeaf;
public:
	bool value;
	int count;
	Node(int G, int C){
		changeable = C;
		isAnd = G;
		isLeaf = false;
		value = false;
		count = 0;
	}
	Node(int I){
		changeable = false;
		isAnd = false;
		isLeaf = true;
		value = I;
		count = 0;
	}
	Node(){ count = 0; }
	void minimize(Node L, Node R){
		if(L.value && R.value){
			value = true;
			count = 0;
		}else if(!isAnd && !changeable && (L.value || R.value)){
			value = true;
			count = 0;
		}else{
			value = false;
			if(!changeable && !isAnd){ 
				count = L.count + R.count;
			}else if(isAnd && !L.value && !R.value){
				count = min(L.count, R.count);
			}else if(isAnd){
				count = max(L.count, R.count);
			}else if(!L.value && !R.value){
				count = min(L.count+R.count, 1+min(L.count, R.count));
			}else{
				count = 1 + max(L.count, R.count);
			}
		}
	}
	void maximize(Node L, Node R){
		if(!L.value && !R.value){
			value = false;
			count = 0;
		}else if(isAnd && !changeable && !(L.value && R.value)){
			value = false;
			count = 0;
		}else{
			value = true;
			if(!changeable && isAnd){ count = L.count + R.count; }
			else if(!isAnd && L.value && R.value){ count = min(L.count, R.count);}
			else if(!isAnd){ count = max(L.count, R.count);}
			else if(L.value && R.value){ count = min(L.count + R.count, 1 + min(L.count, R.count));}
			else{ count = 1 + max(L.count, R.count);}
		}
	}
};

int minGates(int M, int V, Node *nodes){
	//cout << "====" << endl;
	//cout << V << endl;
	for(int i = M/2 - 1; i >=0; i--){
		if(V){ nodes[i].maximize(nodes[2*(i+1) - 1], nodes[2*(i+1)]); }
		else{ nodes[i].minimize(nodes[2*(i+1) - 1], nodes[2*(i+1)]); }
		//cout << i+1 << ": " << nodes[i].value << ", " << nodes[i].count << endl;
	}

	Node head = nodes[0];
	if(head.value == V){
		return head.count;
	}else{
		return -1;
	}
}

int main(){
	int T, M, V;
	Node nodes[10000];
	cin >> T;
	tc(T){
		cin >> M >> V;
		f((M-1)/2){
			int G,C;
			cin >> G >> C;
			nodes[j] = Node(G,C);
		}
		f((M+1)/2){
			int I;
			cin >> I;
			nodes[(M-1)/2 + j] = Node(I);
		}
		cout << "Case #" << i << ": ";
		int min = minGates(M,V,nodes);
		if(min == -1){ cout << "IMPOSSIBLE" << endl;}
		else{ cout << min << endl;}
	}
}