#include<iostream>
#include<vector>
using namespace std;

/* This function checks if the two elements are positioned side by side*/
bool check(int a, int b, vector<int> A){
    int indexA, indexB;
    for (int i = 0; i < A.size(); i++){
        if(A[i] == a) indexA = i; 
        else if(A[i] == b) indexB = i; 
    }
    if(indexA != indexB-1) return false;
    else return true;
}

/* Print the array if all the elements are positioned side by side*/
void printVec(vector<int> A, vector<int> temp){
    bool shouldPrint = true;
    if(temp.size() >= 1){
       for (int i = 0; i < temp.size() - 1; i++){
            if(!check(temp[i], temp[i+1], A)) shouldPrint = false;
        }
    }
    if(!shouldPrint) return;

    cout << "{";           
    for (int i = 0; i < temp.size(); i++){
        if(i == temp.size()-1) cout << temp[i];
        else cout << temp[i] << ",";
    }
    cout << "}" << endl;
}

/* Finding all the subsets */
void subsets(int index, vector<int> A, vector<int> &temp){
    if(index >= A.size()){
        printVec(A, temp);
        return;
    }
    temp.push_back(A[index]);
    subsets(index+1, A, temp);
    temp.pop_back();
    subsets(index+1, A, temp);
}

int main(){
    vector<int> A = {1, 2, 3, 4, 5};
    vector<int> temp = {};
    cout << "\n>> All the subsets of the array are: " << endl;
    subsets(0, A, temp);
}