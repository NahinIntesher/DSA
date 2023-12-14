#include<bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adjList, vector<bool> &visited, stack<int> &st){
    visited[node] = true;
    for(auto neighbour: adjList[node]){
        if(!visited[neighbour]){
            dfs(neighbour, adjList, visited, st);
        }
    }
    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    vector<int> ans;
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }

    vector<bool> visited(v, false);
    stack<int> st;

    for (int i = 1; i < v; i++){
        if(!visited[i]){
            dfs(i, adjList, visited, st);
        }
    }

    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}
int main(){
    int v = 6, e = 7;
    vector<vector<int>> edges = {{1,2},{1,3},{2,4},{3,4},{4,5},{4,6},{5,6}};

    vector<int> ans = topologicalSort(edges, v, e);
    for(auto i: ans){
        cout << i << " ";
    }

}