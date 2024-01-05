#include<bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int,int>> &edges) {
    // Make AdjList
    unordered_map<int, list<int>> adjList;
    for(int i = 0; i < edges.size(); i++){
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;
        adjList[u].push_back(v);
    }
    
    // Find all indegrees
    vector<int> inDegree(n, 0);
    for(auto i: adjList){
        for(auto j: i.second){
            inDegree[j]++;
        }
    }
    
    // Push  all the nodes with 0 indegree into the queue
    queue<int> q;
    for (int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    // Do BFS
    int NoOfNode = 0;
    while (!q.empty()){
        int frontNode = q.front();
        q.pop();

        NoOfNode++;
        for(auto neighbour: adjList[frontNode]){
            if(inDegree[neighbour] != 0){
                inDegree[neighbour]--;
                if(inDegree[neighbour] == 0) 
                    q.push(neighbour);
            }
        }

    }

    if(NoOfNode == n){ // No cycle present
      return false;
    } 
    else { // cycle present
      return true;
    }
}

int main(){
    int v = 5, e = 5;
    // int v = 6, e = 7;
    // vector<pair<int, int>> edges = {{1,2},{1,3},{2,4},{3,4},{4,5},{4,6},{5,6}};
    vector<pair<int, int>> edges = {{1,2},{2,5},{5,4},{4,3},{3,1}};

    int ans = detectCycleInDirectedGraph(v, edges);
    cout << endl;
    
    if(ans == 1){
        cout << "-> Cycle is Present.";
    }
    else{
        cout << "-> Cycle is not Present.";
    }

}