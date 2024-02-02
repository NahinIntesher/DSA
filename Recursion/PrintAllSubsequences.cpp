#include<iostream>
#include<vector>
using namespace std;

void printVec(vector<int> A){
    cout << "{";           
    for (int i = 0; i < A.size(); i++){
        if(i == A.size()-1) cout << A[i];
        else cout << A[i] << ",";
    }
    cout << "}" << endl;
}

void subsequences(int index, vector<int> A, vector<int> &temp){
    if(index >= A.size()){
        printVec(temp);
        return;
    }
    temp.push_back(A[index]);
    subsequences(index+1, A, temp);
    temp.pop_back();
    subsequences(index+1, A, temp);
}

int main(){
    vector<int> A = {3, 1, 2};
    vector<int> temp = {};
    cout << "\n>> All the subsequences of the array are: " << endl;
    subsequences(0, A, temp);
}