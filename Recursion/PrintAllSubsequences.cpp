#include<iostream>
#include<vector>
using namespace std;

void subsequences(int index, vector<int> A, vector<int> &temp){
    if(index >= A.size()){
        for(auto a: temp){
            cout << a << " ";
        } cout << endl;
        return;
    }

    // pickup conditions
    temp.push_back(A[index]);
    subsequences(index+1, A, temp);
    temp.pop_back();

    // not pickup conditions
    subsequences(index+1, A, temp);
}

int main(){
    vector<int> A = {3, 1, 2};
    vector<int> temp;
    cout << "\n>> All the subsequences of the array are: " << endl;
    subsequences(0, A, temp);
}