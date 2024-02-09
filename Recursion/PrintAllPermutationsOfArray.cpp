#include<bits/stdc++.h> 
using namespace std; 
#define printVecVec(A)                        \
    for (int i = 0; i < A.size(); i++){       \
        for (int j = 0; j < A[i].size(); j++) \
            cout << A[i][j] << " ";           \
        cout << endl;                         \
    }
void findPermutation(vector<bool> &indices, vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans){
    if(ds.size() == nums.size()){
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++){
        if(!indices[i]){
            ds.push_back(nums[i]);
            indices[i] = true;
            findPermutation(indices, ds, nums, ans);
            indices[i] = false;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> indices(nums.size(), 0);
    findPermutation(indices, ds, nums, ans);
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = permute(arr);
    sort(ans.begin(),ans.end());
    printVecVec(ans);
}