#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned char Vertex;

enum VertexType {ROW, COLUMN};

Vertex make_vertex(VertexType vt, int v){
    switch (vt)
    {
    case ROW:
        return v;
        break;
    case COLUMN:
        return 255 - v;
        break;
    }
}

struct Graph {
    unordered_map<Vertex, unordered_set<Vertex>> adjacency_list;
    unordered_set<Vertex> rows, cols;
    bool empty(){
        return adjacency_list.empty();
    }
    void addDancer(int x, int y){
        Vertex row = make_vertex(ROW, x);
        Vertex col = make_vertex(COLUMN, y);
        adjacency_list[row].insert(col);
        rows.insert(row);
        cols.insert(col);
    };
    int getMaxIndSetSize(){
        int size = 0;
        unordered_set<Vertex> temp_rows = rows;
        for(Vertex r: temp_rows){
            for(Vertex c: adjacency_list[r]){
                if(cols.find(c) != cols.end()){
                    size++;
                    rows.erase(r);
                    cols.erase(c);
                    adjacency_list[r].erase(c);
                    adjacency_list[c].insert(r);
                    break;
                }
            }
        }
        bool graphChanged = true;
        while(graphChanged && !rows.empty() && !cols.empty()){
            graphChanged = false;
            deque<vector<Vertex>> queue;
            for(Vertex v : rows){
                vector<Vertex> c;
                c.push_back(v);
                queue.push_back(c);
            }
            while(!queue.empty()){
                vector<Vertex> chain = queue.front();
                queue.pop_front();
                Vertex lastNode = chain.back();
                Vertex initialNode = chain.front();
                if(cols.find(lastNode) != cols.end()){
                    graphChanged=true;
                    size++;
                    rows.erase(initialNode);
                    cols.erase(lastNode);
                    for(auto it=chain.begin(); (it+1)!=chain.end(); it++){
                        Vertex current = *it;
                        Vertex next = *(it+1);
                        adjacency_list[current].erase(next);
                        adjacency_list[next].insert(current);
                    }
                    //print();
                    break;
                }else{
                    for(Vertex v : adjacency_list[lastNode]){
                        if(find(chain.begin(), chain.end(), v) != chain.end()){ continue; }
                        vector<Vertex> new_chain = chain;
                        new_chain.push_back(v);
                        queue.push_back(new_chain);
                    }
                }
            }
        }
        return size;
    };

};

int solve(int N){
    unordered_map<int, Graph> costumes;
    for(int i=-N; i<=N; i++){
        costumes[i] = Graph();
    }
    for(int r=0; r<N; r++){
        for(int c=0; c<N; c++){
            int A; cin >> A;
            costumes[A].addDancer(r, c);
        }
    }
    int specialDancers = 0;
    for(int i=-N; i<=N; i++){
        if(costumes[i].empty()){continue;}
        //costumes[i].print();
        specialDancers += costumes[i].getMaxIndSetSize();
    }
    return N*N - specialDancers;
}

int main(){
    int T, N;
    cin >> T;
    for(int i=1; i<=T; i++){
        cin >> N;
        cout << "Case #" << i << ": " << solve(N) << endl;
    }
}