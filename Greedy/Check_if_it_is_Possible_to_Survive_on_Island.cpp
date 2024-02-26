#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int minimumDays(int S, int N, int M){
        int totalFood = S * M;
        int sunday = S / 7;
        int buyingDays = S - sunday; 
        int ans = 0;

        if(totalFood % N == 0){
            ans = totalFood/N;
        }
        else{
            ans = totalFood/N + 1;
        }
        
        if(ans <= buyingDays)
            return ans;
        else
            return -1;
    }
};
int main(){
    int S, N, M;
    cin >> S >> N >> M;
    Solution ob;
    cout << ob.minimumDays(S, N, M) << endl;
}