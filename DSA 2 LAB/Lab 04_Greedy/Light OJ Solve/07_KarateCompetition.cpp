#include <bits/stdc++.h>
using namespace std;

int findMaxScore(vector<int> &A, vector<int> &B, vector<vector<int>> &dp, int i, int j){
    if (i >= A.size() or j >= B.size())
        return 0;
    if (dp[i][j])
        return dp[i][j];
    if (A[i] > B[j])
        return dp[i][j] = 2 + findMaxScore(A, B, dp, i + 1, j + 1);

    else if (A[i] < B[j])
        return dp[i][j] = findMaxScore(A, B, dp, i, j + 1);
    else
        return dp[i][j] = max(1 + findMaxScore(A, B, dp, i + 1, j + 1), findMaxScore(A, B, dp, i, j + 1));
}
int main(){
    int t, cs = 1;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        vector<int> A(n), B(n);

        for (auto &i : A)
            cin >> i;
        for (auto &i : B)
            cin >> i;

        sort(A.begin(), A.end(), greater<int>());
        sort(B.begin(), B.end(), greater<int>());

        vector<vector<int>> dp(n, vector<int>(n, 0));

        cout << "Case " << cs++ << ": " << findMaxScore(A, B, dp, 0, 0) << endl;
    }
}