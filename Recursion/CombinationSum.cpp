#include <bits/stdc++.h>
using namespace std;
#define printVecVec(A)                        \
    for (int i = 0; i < A.size(); i++){       \
        for (int j = 0; j < A[i].size(); j++) \
            cout << A[i][j] << " ";           \
        cout << endl;                         \
    }
class Solution {
public:
    void combinations(int index, int sum, int target, vector<int> &candidates, vector<int> temp, vector<vector<int>> &ans){
        if(index == candidates.size()){
            if(sum == target){
                ans.push_back(temp);
            }
            return;
        }
        if (sum == target) {
            ans.push_back(temp);
            return;
        }
        if (sum > target) {
            return;
        }

        temp.push_back(candidates[index]);
        sum += candidates[index];
        combinations(index, sum, target, candidates, temp, ans);

        temp.pop_back();
        sum -= candidates[index];
        combinations(index+1, sum, target, candidates, temp, ans);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        combinations(0, 0, target, candidates, temp, ans);
        return ans;
    }
};

int main(){
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum(candidates, target);
    cout << "\n>> Answer is: " << endl;
    printVecVec(ans);
}