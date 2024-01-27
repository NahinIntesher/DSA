// 3:
#include<bits/stdc++.h>
using namespace std;

int reverseNum(int num, int revNum){
    if(num <= 0) 
        return revNum;

    revNum = revNum * 10 + num % 10;
    num = num / 10;

    revNum = reverseNum(num, revNum);
    return revNum;
}

int main(){
    int num;
    cin >> num;
    int revNum = reverseNum(num, 0);
    
    if(revNum == num)
        cout << "YES";
    else
        cout << "NO";
}

/* Or Using String.........
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int i, int j){
    if(i > j)
        return true;
    if(s[i] != s[j])
        return false;
    
    bool check = isPalindrome(s, ++i, --j);
    if(!check)
        return false;
    else
        return true;
}

int main(){
    int n;
    cin >> n;
    string s = to_string (n);
    if(isPalindrome(s, 0, s.size()-1))
        cout << "YES";
    else
        cout << "NO";
}
*/