#include <bits/stdc++.h>
using namespace std;
void solve(int Case);
int main(){
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}

void solve(int Case){
	int N, ans = 0;
    cin >> N;      

    vector<int> A(N + 1);    // for given array
    vector<bool> visited(N + 1); // for tracking visited numbers 

    for(int i = 1; i <= N; i++){
    	cin >> A[i];
    }
    for(int i = 1; i <= N; i++){
		int k = i, cycle = 0; // "cycle" is for detecting the number of cycle 
        if(!visited[k]){ // if c[k] is unvisited it means we haven't covered the cycle 'k' belongs in yet.
            //For finding the number of elements in each cycle
            while(!visited[k]){
                cycle ++;
                visited[k] = true;
                k = A[k]; 
            }
    	    ans += cycle - 1; //summing answer according to formula.
        }
    }
    cout << "Case "<< Case << ": " << ans << endl;
}