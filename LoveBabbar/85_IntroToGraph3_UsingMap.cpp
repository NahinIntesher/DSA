#include <bits/stdc++.h>
using namespace std;

class graph{
    public:
    int Nodes;
    int Edges;
    unordered_map<int, list<int> > adj;

    void addEdges(int u, int v, int direction){
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph
        
        // create an edge from u to v 
        adj[u].push_back(v);

        if(direction == 0){
            adj[v].push_back(u);
        }
    }

    void printAdjList(){
        for(auto i: adj){
            cout << i.first << " -> ";
            for(auto j: i.second){
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main(){
    int N, M;
    cout << "\nEnter the number of Nodes: ";
    cin >> N;
    cout << "Enter the number of edges: ";
    cin >> M;

    graph g;

    for (int i = 1; i <= N + 1; i++){
        int u, v;
        cin >> u >> v;
        
        // creating undirected graph
        g.addEdges(u , v, 0);
    }
    cout << endl;
    // Printing Graph 
    g.printAdjList();
}