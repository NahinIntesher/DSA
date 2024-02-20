#include<iostream>
#include<vector>
using namespace std;
string longest(string s1, string s2){
    string ans = "";
    for (int i = 0, j = 0; i < s1.size() && j < s2.size(); i++, j++){
        if(s1[i] != s2[j])
            break;
        ans += s1[i];
    }
    return ans;
}
string LCP(vector<string> A, int low, int high){
    if(low == high)
        return A[low];
    int mid = (low + high) / 2;
    string left = LCP(A, low, mid);
    string right = LCP(A, mid + 1, high);
    return longest(left, right);
}
int main(){
    int N;
    cin >> N;
    vector<string> A(N);
    for(auto &a: A)
        cin >> a;
    cout << LCP(A, 0, A.size()-1); 
}