#include<bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> makeAdjList(vector<pair<int, int> > &edges){
    unordered_map<int, vector<int>> adjList;
    for(auto i: edges){
        int u = i.first;
        int v = i.second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    return adjList;
}
/*
void printAdjList(vector<vector<int>> adj){
    for(int i = 1; i < adj.size() - 1; i++){
        cout << i << " -> ";
        for(auto j: adj[i]){
            cout << j << ", ";
        }
        cout << endl;
    }
}

// Recursive :
void DFS(vector<vector<int>> &component, unordered_map<int, vector<int>> &adj, 
vector<bool> &visited, int node){
    component.push_back(node);
    visited[node] = true;

    // Traversing all the neighbour node
    for(auto i: adj[frontNode]){
        if(!visited[i]){
            DFS(component, adjList, visited, i);
        }
    } 
}
*/

void DFS(vector<int> &ans, unordered_map<int, vector<int>> &adj, vector<bool> &visited, int node){
    stack<int> st;
    st.push(node);
    visited[node] = true;

    while (!st.empty()){
        int frontNode = st.top();
        ans.push_back(frontNode);
        st.pop();

        // Traversing all the neighbour node
        for(auto i: adj[frontNode]){
            if(!visited[i]){
                st.push(i);
                visited[i] = true;
            }
        }
    }
}


vector<int> dfsTraversal(int vartex, unordered_map<int, vector<int>> &adj){
    vector<int> ans;
    vector<bool> visited(vartex, false);

    // Traversing all the vartices
    for (int i = 1; i <= vartex; i++){
        if(!visited[i]){
            DFS(ans, adj, visited, i);
        }
    }
    return ans; 
}

int main(){
    int vartex = 5, Edges = 7;
    vector<pair<int, int> > edges = {{1, 2}, {1, 5}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}};

    unordered_map<int, vector<int>> adjList = makeAdjList(edges);
    // printAdjList(adjList);

    vector<int> ans = dfsTraversal(vartex, adjList);
    cout << endl;
    for(auto i: ans){
        cout << i << " ";
    }

}