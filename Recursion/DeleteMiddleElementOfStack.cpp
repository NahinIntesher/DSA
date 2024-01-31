#include<iostream>
#include<stack>
#include <vector>
using namespace std;

void deleteMiddle(stack<int> &stack, int halfSize){
    if(stack.size() == halfSize){
        stack.pop();
        return;
    }

    int temp = stack.top();
    stack.pop();
    deleteMiddle(stack, halfSize);
    stack.push(temp);
}

int main(){
    stack<int> stack;
    vector<int> A = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto a: A){
        stack.push(a);
    }
    
    // cout << "\n>> Before deleting middle element: " << endl;
    // while(!stack.empty()){
    //     cout << stack.top() << endl;
    //     stack.pop();
    // }

    deleteMiddle(stack, (stack.size()+1)/2);
    
    cout << "\n\n>> After deleting middle element: " << endl;
    while(!stack.empty()){
        cout << stack.top() << endl;
        stack.pop();
    }

}