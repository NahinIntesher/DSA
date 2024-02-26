#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string reverseWords(string S){ 
        string ans = "";
        string temp = "";
        for(int i = S.size()-1; i >= 0; i--){
            if(S[i] == '.'){
                reverse(temp.begin(), temp.end());
                ans = ans + temp;
                ans = ans + ".";
                temp = "";
            }
            else{
                temp = temp + S[i];
            }
        }
        reverse(temp.begin(), temp.end());
        ans = ans + temp;
        return ans;
    } 
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}