#include<bits/stdc++.h>
using namespace std; 
struct Job { 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
class Solution {
    public:
    static bool comp(Job a, Job b){
        return a.profit > b.profit; 
    }
    vector<int> JobScheduling(Job arr[], int n) { 
        sort(arr, arr+n, comp);
        int maxDeadline = INT_MIN;
        for (int i = 0; i < n; i++){
            maxDeadline = max(maxDeadline, arr[i].dead);
        }
        vector<int> schedule(maxDeadline+1, -1); 
        int profit = 0;
        int countJob = 0;
        for (int i = 0; i < n; i++){
            int currJobId = arr[i].id;
            int currDead = arr[i].dead;
            int currProfit = arr[i].profit;

            for (int k = currDead; k > 0; k--){
                if(schedule[k] == -1){
                    countJob++;
                    profit += currProfit;
                    schedule[k] = currJobId;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(countJob);
        ans.push_back(profit);
        return ans;
    } 
};
int main() {
    int n;
    cin >> n;
    Job arr[n];
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        arr[i].id = x;
        arr[i].dead = y;
        arr[i].profit = z;
    }
    Solution ob;
    vector<int> ans = ob.JobScheduling(arr, n);
    cout << ans[0] << " " << ans[1] << endl;
}