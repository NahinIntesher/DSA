#include<bits/stdc++.h> 
using namespace std; 
class Solution{
public:
    vector<int> candyStore(int candies[], int N, int K){
        vector<int> ans;       
        sort(candies, candies+N);
        int minMoney = 0, maxMoney = 0;
        int buy = 0, free = N - 1;
        while(buy <= free){
            minMoney += candies[buy];
            buy++;
            free -= K;
        }
        while(free <= buy){
            maxMoney += candies[buy];
            buy--;
            free += K;
        }    
        ans.push_back(minMoney);
        ans.push_back(maxMoney);
        return ans;
    }
};
int main(){
    int N, K;
    cin >> N >> K;
    int candies[N];
    for (int i = 0; i < N; i++){
        cin >> candies[i];
    }
    Solution ob;
    vector<int> cost = ob.candyStore(candies, N, K);
    cout << cost[0] << " " << cost[1] << endl;
}