#include <bits/stdc++.h>
using namespace std;

bool isCyclickDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int node, int parent){
    visited[node] = true;

    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclickDFS(adjList, visited, neighbour, node);
            if (cycleDetected) {
              return true;
            }
        }
        else if(neighbour != parent){
            return true;
        }
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            bool ans = isCyclickDFS(adjList, visited, i, -1);
            if (ans == true) {
                return "Yes";
            }
        }
    }
    return "No";
}


int main(){
    int vartex = 9, Edges = 8;
    vector<vector<int> > edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {5, 7}, {6, 8}, {7, 8}, {8, 9}};

    string ans = cycleDetection(edges, vartex, Edges);

    cout << endl << "-> Is there any cycle? : " << ans;
    
}