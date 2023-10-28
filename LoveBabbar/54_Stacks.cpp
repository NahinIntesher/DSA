#include<bits/stdc++.h>
using namespace std;

class Stack {
    public:
    int *arr;
    int top;
    int size;

    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if(top <= size - 2) {
            arr[++top] = element;
        }
        else {
            cout << "Stack OverFlow..." << endl;
        }
    }

    void pop() {
        if(top >= 0) {
            top--;
        }
        else {
            cout << "Stack UderFlow..." << endl;
        }
        
    }

    int peek() {
        if(top >= 0) {
            return arr[top];
        }
        else {
            cout << "Stack is empty..." << endl;
            return -1;
        }
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        return false;
    }
    
    bool isFull() {
        if(top == size - 1) {
            return true;
        }
        return false;
    }
};

int main(){
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.peek() << endl;

    st.pop();
    st.pop();
    
    cout << st.peek() << endl;

}