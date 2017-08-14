//2009 Round 1B, Problem A
//Decision Tree
//https://code.google.com/codejam/contest/186264/dashboard

/*
Input: The first line of input contains a single integer, N, the number of test cases. N test cases follow.

Each test case description will start with a line that contains an integer L -- the number of lines that describe a decision tree. The next L lines will contain a decision tree in the format described above. The line after that will contain A -- the number of animals. The next A lines will each contain the description of one animal in the following format.

animal n feature1 feature2 ... featuren
*/

/*
Output: For each test case, output one line containing "Case #x:" followed by exactly A lines, one per animal, in the same order as they appear in the input. Each line should contain the probability that the animal is cute. Answers that are precise to within an absolute or relative error of 10-6 will be considered correct.
*/

class Node{
	string feature;
	double weight;
	Node *left, *right;
	public:
		double calculate(set<string>);
}

double Node::calculate(set<string> features){
	if(left == 0){
		return weight;
	}
	if(features.find(feature)!=features.end()){
		return weight*&left.calculate(features);
	}else{
		return weight*&right.calculate(features);
	}
}

Node getTree(std::vector<string> lines){
	
}

int main(){
	int N, L, A;
	cin << N;
	for(int i=1;i<=N;i++){
		cin << L << A;
		vector<string> tree;
		for(int j=0;j<N;j++){
			string line;
			getline(cin,line);
			tree.push_back(line);
		}
		Node root = getTree(tree);
		cout << "Case #" << i << ":" << endl;
		set<string> features;
		for(int j=0;j<A;j++){
			string name;
			cin >> name;
			int F;
			cin >> F;
			features.clear();
			for(k=0;k<F;k++){
				string feature;
				cin >> feature;
				features.insert(feature);
			}
			char result[50];
			sprintf(result,"%.6f",root.calculate(features));
			cout << result << endl;
		}
	}
}