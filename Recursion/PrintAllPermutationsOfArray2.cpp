#include<bits/stdc++.h> 
using namespace std; 
void printVecVec(vector<vector<int>> A){  
    for (int i = 0; i < A.size(); i++){
        for (int j = 0; j < A[i].size(); j++){
            cout << A[i][j] << " ";
        } cout << endl;
    }
}
void findPermutation(int ind, vector<int> &nums, vector<vector<int>> &ans){
    if(ind == nums.size()){
        ans.push_back(nums);
        return;
    }
    for (int i = ind; i < nums.size(); i++){
        swap(nums[i], nums[ind]);
        findPermutation(ind+1, nums, ans);
        swap(nums[ind], nums[i]);
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    findPermutation(0, nums, ans);
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = permute(arr);
    sort(ans.begin(),ans.end());
    printVecVec(ans);
}