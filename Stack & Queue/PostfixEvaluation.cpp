#include<bits/stdc++.h>
using namespace std;

void forPlus(stack<int> &st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();

    int ans = b + a;
    st.push(ans);
}

void forMinus(stack<int> &st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();

    int ans = b - a;
    st.push(ans);
}

void forMultiply(stack<int> &st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();

    int ans = b * a;
    st.push(ans);
}

void forDivide(stack<int> &st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();

    int ans = b / a;
    st.push(ans);
}

void forPower(stack<int> &st) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();

    int ans = (b << a);
    st.push(ans);
}


int main(){
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); i++){
        if('0' <= s[i] && s[i] <= '9') 
            st.push(s[i] - 48);
        else if(s[i] == '+') 
            forPlus(st);
        else if(s[i] == '-') 
            forMinus(st);
        else if(s[i] == '*') 
            forMultiply(st);
        else if(s[i] == '/') 
            forDivide(st);
        else if(s[i] == '^') 
            forPower(st);
    }

    cout << "\nEvaluation: " << st.top() << endl;

}
