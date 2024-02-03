#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void printVec(vector<int> A){
    cout << "{";           
    for (int i = 0; i < A.size(); i++){
        if(i == A.size()-1) cout << A[i];
        else cout << A[i] << ",";
    }
    cout << "}" << endl;
}
void subsequences(int index, vector<int> A, vector<int> &temp, int k){
    if(index >= A.size()){
        int sum = accumulate(temp.begin(), temp.end(), 0); // Using a stl function
        if(sum == k){
            printVec(temp);
        }
        return;
    }
    // pickup conditions
    temp.push_back(A[index]);
    subsequences(index+1, A, temp, k);
    temp.pop_back();

    // not pickup conditions
    subsequences(index+1, A, temp, k);
}

int main(){
    vector<int> A = {3, 1, 2};
    vector<int> temp;
    int k = 2;
    cout << "\n>> Those subsequences whoose sum is equal to 'K' are: : " << endl;
    subsequences(0, A, temp, k);
}
