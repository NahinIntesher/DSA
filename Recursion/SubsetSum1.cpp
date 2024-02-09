#include<bits/stdc++.h> 
using namespace std; 
void findSubSetSum(int ind, int sum, vector<int> &arr, vector<int>& ans){
    if(ind >= arr.size()){
        ans.push_back(sum);
        return;
    }
    // pick the element
    findSubSetSum(ind+1, sum+arr[ind], arr, ans);
    // not pick the element
    findSubSetSum(ind+1, sum, arr, ans);
}
vector<int> subsetSums(vector<int> arr, int N){
    vector<int> ans;
    findSubSetSum(0, 0, arr, ans);
    return ans;
}
int main(){
    int N = 3;
    vector<int> arr = {5, 2, 1};
    vector<int> ans = subsetSums(arr, N);
    sort(ans.begin(),ans.end());
    for(auto sum : ans){
        cout << sum << " ";
    } cout << endl;
}