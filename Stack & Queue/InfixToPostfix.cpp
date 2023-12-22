#include<bits/stdc++.h>
using namespace std;

string postFix = "";

void forPlus(stack<char> &st) {
    if(st.empty() || st.top() == '(') {
        st.push('+');
        return;
    }
    while (!st.empty() && st.top() != '(') {
        postFix += st.top();
        st.pop();
    }
    st.push('+');
}

void forMinus(stack<char> &st) {
    if (st.empty() || st.top() == '(') {
        st.push('-');
        return;
    }
    while (!st.empty() && st.top() != '(') {
        postFix += st.top();
        st.pop();
    }
    st.push('-');
}

void forMultiply(stack<char> &st) {
    if (st.empty() || st.top() == '+' || st.top() == '-' || st.top() == '(') {
        st.push('*');
        return;
    }
    while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '^')) {
        postFix += st.top();
        st.pop();
    }
    st.push('*');
}

void forDivide(stack<char> &st) {
    if (st.empty() || st.top() == '+' || st.top() == '-' || st.top() == '(') {
        st.push('/');
        return;
    }
    while (!st.empty() && (st.top() == '*' || st.top() == '/' || st.top() == '^')) {
        postFix += st.top();
        st.pop();
    }
    st.push('/');
}

void forPower(stack<char> &st) {
    if (st.empty() || st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/' || st.top() == '(') {
        st.push('^');
        return;
    }
    if(!st.empty() && st.top() == '^') {
        st.push('^');
    }
}


int main(){
    string s;
    cin >> s;
    stack<char> st;
    for (int i = 0; i < s.size(); i++){
        if(isalpha(s[i])) 
            postFix += s[i];
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
        else if(s[i] == '(') 
            st.push('(');
        else if(s[i] == ')'){
            while (!st.empty() && st.top() != '('){
                postFix += st.top();
                st.pop();
            }
            st.pop();
        }
    }

    while (!st.empty()) {
        if (st.top() != '(')
            postFix += st.top();
        st.pop();
    }

    cout << "\nPost Fix: " << postFix << endl;

}
