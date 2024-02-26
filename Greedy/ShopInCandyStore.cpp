#include<bits/stdc++.h> 
using namespace std; 
class Solution{
public:
    vector<int> candyStore(int candies[], int N, int K){
        vector<int> ans;
        vector<int> cnd;
        for (int i = 0; i < N; i++)
            cnd.push_back(candies[i]);
        sort(cnd.begin(), cnd.end());

        int minMoney = 0, maxMoney = 0;
        for (int i = 0, j = cnd.size()-1; i <= j; i++){
            minMoney += cnd[i];
            j -= K;
        }
        for (int i = 0, j = cnd.size()-1; j >= i; j--){
            maxMoney += cnd[j];
            i += K;
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