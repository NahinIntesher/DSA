#include<bits/stdc++.h> 
using namespace std; 
#define printVecVec(A)                        \
    for (int i = 0; i < A.size(); i++){       \
        for (int j = 0; j < A[i].size(); j++) \
            cout << A[i][j] << " ";           \
        cout << endl;                         \
    }
void findSubSets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans){
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++) {
        if(i != ind && nums[i] == nums[i - 1]) continue;
        ds.push_back(nums[i]);
        findSubSets(i+1, nums, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums){
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    findSubSets(0, nums, ds, ans);
    return ans;
}
int main(){
    vector<int> arr = {1, 2, 2};
    vector<vector<int>> ans = subsetsWithDup(arr);
    sort(ans.begin(),ans.end());
    printVecVec(ans);
}