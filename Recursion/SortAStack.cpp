#include<iostream>
#include<stack>
#include <vector>
using namespace std;

void sortedInsert(stack<int> &stack, int num){
    if(stack.empty() || (!stack.empty() && num > stack.top()) ){
        stack.push(num);
        return;
    }
    int temp = stack.top();
    stack.pop();

    sortedInsert(stack, num);
    stack.push(temp);
}

void sortStack(stack<int> &stack){
    if(stack.empty()){
        return;
    }
    int num = stack.top();
    stack.pop();

    sortStack(stack);
    sortedInsert(stack, num);
}

int main(){
    stack<int> stack;
    vector<int> A = {5, 2, 10, 1, 19, 3, 6, 27};
    for(auto a: A){
        stack.push(a);
    }

    sortStack(stack);
    
    cout << "\n>> After sorting stack elements are: " << endl;
    while(!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }

}