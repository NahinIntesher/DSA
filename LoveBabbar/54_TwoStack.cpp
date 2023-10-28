#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int element) {
        if(top1 <= top2 - 2) {
            arr[++top1] = element;
        }
        else {
            cout << "Stack OverFlow..." << endl;
        }
    }
    void push2(int element) {
        if(top2 >= top1 + 2) {
            arr[--top2] = element;
        }
        else {
            cout << "Stack 2 OverFlow..." << endl;
        }
    }

    void pop1() {
        if(top1 >= 0) {
            top1--;
        }
        else {
            cout << "Stack UderFlow..." << endl;
        }
    }
    void pop2() {
        if(top2 <= size - 1) {
            top2++;
        }
        else {
            cout << "Stack 2 UderFlow..." << endl;
        }
    }

    int peek1() {
        if(top1 >= 0) {
            return arr[top1];
        }
        else {
            cout << "Stack is empty..." << endl;
            return -1;
        }
    }
    int peek2() {
        if(top2 >= 1) {
            return arr[top2];
        }
        else {
            cout << "Stack is empty..." << endl;
            return -1;
        }
    }

    bool isEmpty1() {
        if(top1 == -1) {
            return true;
        }
        return false;
    }
    bool isEmpty2() {
        if(top2 == size) {
            return true;
        }
        return false;
    }
    
    bool isFull1() {
        if(top1 == top2 - 1) {
            return true;
        }
        return false;
    }
    bool isFull2() {
        if(top2 == top1 + 1) {
            return true;
        }
        return false;
    }
};

int main(){
    Stack st(4);
    st.push1(22);
    st.push1(23);

    st.push2(43);
    st.push2(44);

    cout << st.peek1() << endl;
    cout << st.peek2() << endl;

    st.pop2();
    st.pop2();

    st.push1(56);
    st.push1(89);

    if(st.isFull1()){
        cout << "Stack 1 is full\n";
    }
    if(st.isEmpty2()){
        cout << "Stack 2 is empty\n";
    }

}