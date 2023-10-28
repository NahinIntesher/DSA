#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter size of the array/vector (n): ";
    cin>>n;
    vector<int> v(n);
    for(auto &a: v){
        cin>>a;
    }
    sort(v.begin(),v.end());
    int key;
    cout<<"Enter the number you want to find: ";
    cin>>key;
    int flag = 0;
    int start = 0;
    int end = n;
    while(start<=end){
        int mid = (start+end)/2;
        if(key == v[mid]){
            cout<<"Key: "<< key << endl;
            cout<<"Index: "<< mid;
            flag = 1;
            break;
        }
        else if(key > v[mid]){
            start = mid+1;
        }
        else if(key < v[mid]){
            end = mid-1;
        }
    }
    if(flag==0) cout<<"Not Found!";
}