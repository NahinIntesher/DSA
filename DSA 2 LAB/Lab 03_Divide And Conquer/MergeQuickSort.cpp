#include<bits/stdc++.h> 
using namespace std; 
class Solution {
public:
    // void Merge(vector<int>& nums, int start, int end){
    //     int mid = start + (end - start)/2;
    //     int len1 = mid - start + 1;
    //     int len2 = end - mid;
    //     vector<int> v1;
    //     vector<int> v2;

    //     int mainArrayIndex = start;
    //     for(int i = 0; i < len1; i++)
    //         v1.push_back(nums[mainArrayIndex++]);
    //     mainArrayIndex = mid+1;
    //     for(int i = 0; i < len1; i++)
    //         v2.push_back(nums[mainArrayIndex++]); 

    //     int index1 = 0;
    //     int index2 = 0;
    //     mainArrayIndex = start;
    //     while(index1 < len1 && index2 < len2){
    //         if(v1[index1] < v2[index2]) nums[mainArrayIndex++] = v1[index1++];
    //         else nums[mainArrayIndex++] = v2[index2++];
    //     }
    //     while(index1 < len1)
    //         nums[mainArrayIndex++] = v1[index1++];
    //     while(index2 < len2)
    //         nums[mainArrayIndex++] = v2[index2++];
    // }
    // void MergeSort(vector<int>& nums, int start, int end){
    //     if(start >= end){
    //         return;
    //     }
    //     int mid = start + (end - start)/2;
    //     MergeSort(nums, start, mid); 
    //     MergeSort(nums, mid + 1, end); 
    //     Merge(nums, start, end);      
    // }
    int partition(vector<int>& nums, int start, int end){
        int pivot = nums[start];
        int count = 0;
        for (int i = start+1; i <= end; i++){
            if(nums[i] <= pivot) count++;
        }
        if(count == 0) return start;
        int pivotIndex = start + count;
        swap(nums[pivotIndex], nums[start]);
        int i = start;
        int j = end;
        while(i<pivotIndex && j>pivotIndex){
            while(nums[i] < pivot){
                i++;
            }
            while(nums[j] > pivot){
                j--;
            }
            if(i<pivotIndex && j>pivotIndex){
                swap(nums[i++], nums[j--]); 
            }
        }
        return pivotIndex;
    }
    void QuickSort(vector<int>& nums, int start, int end){
        if(start>=end)
            return;
        int index = partition(nums, start, end);
        QuickSort(nums, start, index-1);
        QuickSort(nums, index+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        // MergeSort(nums, 0, nums.size()-1);
        QuickSort(nums, 0, nums.size()-1);
        return nums;
    }
};
int main(){
    vector<int> arr = {5,1,1,2,0,0};
    Solution ob;
    vector<int> ans = ob.sortArray(arr);
    for(auto i : ans){
        cout << i << " ";
    } cout << endl;
}