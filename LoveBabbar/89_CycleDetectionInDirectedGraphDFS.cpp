#include <bits/stdc++.h>
using namespace std;

bool isCyclickDFS(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited,
            unordered_map<int, bool> &dfsCalled, int node){
    
    visited[node] = true;
    dfsCalled[node] == true;

    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            bool cycleDetected = isCyclickDFS(adjList, visited, dfsCalled, neighbour);
            if (cycleDetected) {
              return true;
            }
        }
        else if(dfsCalled[neighbour]){
            return true;
        }
    }
    dfsCalled[node] == false;
      return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m){
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsCalled;
    for (int i = 0; i < n; i++){
        if(!visited[i]){
            bool cycleFound = isCyclickDFS(adjList, visited, dfsCalled, i);
            if (cycleFound == true) {
                return "Yes";
            }
        }
    }
    return "No";
}


int main(){
    int vartex = 8, Edges = 9;
    vector<vector<int> > edges = {{1, 2}, {2, 3}, {2, 4}, {3, 7}, {3, 8}, {8, 7}, {4, 5}, {5, 6}, {6, 4}};

    string ans = cycleDetection(edges, vartex, Edges);

    cout << endl << "-> Is there any cycle? : " << ans;
    
}