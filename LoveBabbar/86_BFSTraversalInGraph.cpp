#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> makeAdjList(vector<pair<int, int> > &edges){
    vector<vector<int>> adjList(edges.size());
    for (auto &i: edges){
        int u = i.first;
        int v = i.second;
        cout << u << " " << v << endl;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

void BFS(vector<int> &ans, vector<vector<int>> &adjList, vector<bool> &visited, int node){
    queue<int> q;  
    q.push(node);
    visited[node] = true;

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        // Traversing all the neighbours of current node
        for(auto i: adjList[frontNode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> bfsTraversal(int vartex, vector<vector<int>> &adj){
    vector<int> ans;
    vector<bool> visited(vartex, false);

    // Traversing all the vartices
    for (int i = 1; i <= vartex; i++){
        if(!visited[i]){
            BFS(ans, adj, visited, i);
        }
    }
    return ans; 
}


int main(){
    int vartex = 5, Edges = 7;
    vector<pair<int, int> > edges = {{1, 2}, {1, 5}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}};

    vector<vector<int>> adjList = makeAdjList(edges);

    vector<int> BreathFirstSearch = bfsTraversal(vartex, adjList);

    for(auto i: BreathFirstSearch){
        cout << i << " ";
    }
    
}