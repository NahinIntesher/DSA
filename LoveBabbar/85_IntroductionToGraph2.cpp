#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<vector<int>>V){
    for (int i = 0; i < V.size(); i++){
        cout << i << ": ";
        for (int j = 0; j < V[i].size(); j++){
            cout << V[i][j] << " "; cout << endl;
        }
    }
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i <= N + 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    printGraph(adj);
}