#include <bits/stdc++.h>
using namespace std;
string larger(string s1, string s2){
    string ans = "";
    for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++){
        if (s1[i] != s2[j])
            break;
        ans += s1[i];
    }
    return ans;
}
string LCP(vector<string> A, int low, int high){
    if (low == high)
        return A[low];
    int mid = (low + high) / 2;
    string left = LCP(A, low, mid);
    string right = LCP(A, mid + 1, high);
    return larger(left, right);
}
int main(){
    int N;
    cin >> N;
    vector<string> A(N);
    for (auto &a : A){
        cin >> a;
    }
    string ans = LCP(A, 0, A.size() - 1);
    if (ans.size() != 0)
        cout << ans;
    else
        cout << "No common prefix";
}

/*

-> What I understand: I have to take all the string in a vector and print a common string
    from all strings that is larger

-> My approach: I made a function that will take the vector of string and divide them until
    they become one string, then I return that string. But when returning two string then
    I called another function that will take two string and find the longst common string
    from them. Larger function will start tracing from start and if any of the charecter of
    those two string is no simmilar then it will return null string.

-> Key Logic: LCP function will do with
                (i) Divide and Conqurer Approach and
                (ii) the larger function will help to find the largest common prefix.

*/