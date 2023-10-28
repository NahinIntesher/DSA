#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cout << "\n>> Enter stack size: ";
    cin >> N;
    char Stack[N];
    int TOP = -1;
    string S;
    cout << "\nEnter a string that you want to reverse: ";
    cin >> S;
    int len = S.size();
    cout << "-> String data before: " << S << endl;
    for (int i = 0; i < len; i++){
        Stack[++TOP] = S[i];
    }
    S = "";
    for (int i = 0; i < len; i++){
        char ch = Stack[TOP--];
        S += ch;
    }
    cout << "-> String data after: " << S << endl;
}

