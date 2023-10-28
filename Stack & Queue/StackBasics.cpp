#include<bits/stdc++.h>
using namespace std;
#define SIZE 100
int Stack[SIZE];
int TOP = -1;

void push(int v);
void pop();
int menuList();

int main(){
    int N;
    cout << "\n>> Enter stack size: ";
    cin >> N;
    int choice = menuList();
    while (choice){
        if(choice == 1) {
            if(TOP == N - 1) {
                cout << "\n-> Stack is full..." << endl;
            }
            else {
                int v;
                cout << ">> Enter value to push: ";
                cin >> v;
                push(v);
            }
        }
        else if(choice == 2) {
            if(TOP == -1){
                cout << "\n-> Stack is empty..." << endl;
            }
            else{
                pop();
            }
        }
        else if(choice == 3) {
            cout << "\n-> Stack size: " << (TOP + 1) << endl;
        }
        else if(choice == 4) {
            if(TOP == -1) cout << "\n-> Stack is empty..." << endl;
            else cout << "\n-> Top element: " << Stack[TOP] << endl;
        }
        else if(choice == 0) {
            break;
        }
        else{
            cout << "\n-> Invalid Input !" << endl;
        }
        choice = menuList();
    }
}

int menuList(){
    cout << "\n1. Push" << endl;
    cout << "2. Pop" << endl;
    cout << "3. Stack size" << endl;
    cout << "4. Top element" << endl;
    cout << "0. Exit" << endl;
    int x;
    cout << "\n>> Enter your choice: ";
    cin >> x;
    return x;
}

void push(int v){
    Stack[++TOP] = v;
}

void pop(){
    cout << "\n-> Poped value: " << Stack[TOP--] << endl;
}