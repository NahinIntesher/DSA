#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> makeAdjList(int vartex, vector<vector<int> > &edges){
    unordered_map<int, vector<int>> adjList(vartex);
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}

void BFS(vector<int> &ans, unordered_map<int, vector<int>> &adjList, unordered_map<int, bool> &visited, int node){
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

vector<int> bfsTraversal(int vartex, unordered_map<int, vector<int>> &adj){
    vector<int> ans;
    unordered_map<int, bool> visited;

    // Traversing all the vartices
    for (int i = 1; i < adj.size(); i++){
        if(!visited[i]){
            
            BFS(ans, adj, visited, i);
        }
    }
    return ans; 
}



int main(){
    int vartex = 9, Edges = 8;
    vector<vector<int> > edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {5, 7}, {6, 8}, {7, 8}, {8, 9}};

    unordered_map<int, vector<int>> adjList = makeAdjList(vartex, edges);

    // Printing adjList 
    for(int i = 1; i < adjList.size(); i++){
        cout << i << " -> ";
        for(auto j: adjList[i]){
            cout << j << ", ";
        }
        cout << endl;
    }
    

    vector<int> BreathFirstSearch = bfsTraversal(vartex, adjList);

    for(auto i: BreathFirstSearch){
        cout << i << " ";
    }
    
}