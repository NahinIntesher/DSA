#include <bits/stdc++.h>
using namespace std;
#define printVecVec(V) for(int i=0;i<V.size();i++){for(int j=0;j<V[i].size();j++)cout<<V[i][j]<< " ";cout<<endl;}

int main(){
    int n, m;
    cin >> n >> m;
    int adj[n+1][m+1];

    // Graph stored way 1
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    
    // Graph stored way 2
    vector<vector<int> > Adj(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);

    }
    printVecVec(Adj);


}