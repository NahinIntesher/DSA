#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#define printVecVec(A)                        \
    for (int i = 0; i < A.size(); i++){       \
        for (int j = 0; j < A[i].size(); j++) \
            cout << A[i][j] << " ";           \
        cout << endl;                         \
    }
using namespace std;

class Solution {
public:
    void combinations(int index, int target, vector<int> &candidates, vector<vector<int>> &ans, vector<int> &temp){
        if(target == 0){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            if(candidates[i] > target) break; 
            if(i > index && candidates[i] == candidates[i-1])
                continue;
                
            temp.push_back(candidates[i]);
            combinations(i+1, target - candidates[i], candidates, ans, temp); 
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        combinations(0, target, candidates, ans, temp);
        return ans;
    }
};

int main(){
    vector<int> A = {1, 1, 1, 2, 2};
    // vector<int> A = {10, 1, 2, 7, 6, 1, 5};
    vector<int> temp;
    cout << "\n>> All the combinaitons for the target are: " << endl;
    Solution obj;
    vector<vector<int>> ans = obj.combinationSum2(A, 4);
    printVecVec(ans);

}