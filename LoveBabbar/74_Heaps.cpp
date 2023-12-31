#include<bits/stdc++.h>
using namespace std;

template<typename T>
class heap{
    public:
    T *arr;
    T size;

    heap(T Size){
        arr = new T[Size];
        this -> size = 0;
    }

    void insert(T value){
        size = size + 1;
        T index = size;
        arr[index] = value;

        while (index > 1){
            T parent = index /2;
            if(arr[index] > arr[parent]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }
    void Delete(){
        if(size == 0){
            cout << "-> Nothing to delete." << endl;
            return;
        }

        arr[1] = arr[size];
        size = size - 1;

        T index = 1;
        while (index < size){
            T leftChild = 2 * index;
            T rightChild = 2 * index + 1;
            
            if(leftChild < size && arr[index] < arr[leftChild]){
                swap(arr[index] , arr[leftChild]);
                index = leftChild;
            }
            else if(rightChild < size && arr[leftChild] < arr[rightChild]){
                swap(arr[leftChild] , arr[rightChild]);
                leftChild = rightChild;
            }
            else{
                return;
            }
        }
        
    }

    void printHeap(){
        for (T i = 1; i <= size; i++){
            cout << arr[i] << " ";
        } cout << endl;
    }

};

/* Max Heapify with 1 indexing array */
void heapify(int arr[], int size, int index){
    int largest = index;
    int left = 2 * index;
    int right = 2 * index + 1; 
    
    // Swaping with max child
    if(left <= size && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= size && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != index){
        swap(arr[index] , arr[largest]);
        heapify(arr, size, largest);
    }
}

/* Min Heapify with 0 indexing array
void heapify(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[smallest] > arr[left]){
        smallest = left;
    }
    if(right < n && arr[smallest] > arr[right]){
        smallest = right;
    }

    if(smallest != i){
        swap(arr[i] , arr[smallest]);
        heapify(arr, n, smallest);
    }    
}
*/

int main(){
    heap<int> hp(100);
    int arr[6] = {-1, 50, 55, 53, 52, 54};
    for (int i = 1; i <= 5; i++){
        hp.insert(arr[i]);
    }
    

    cout << endl << "-> Elements Before: ";
    hp.printHeap();
    cout << "-> Heap Size: " << hp.size  << endl;
    
    hp.Delete();
    // hp.Delete();
    

    cout << endl << "-> Elements After deleting 2 nodes: ";
    hp.printHeap();
    cout << "-> Heap Size: " << hp.size  << endl << endl;


    int A[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i >= 1; i--){
        heapify(A, n, i);
    }
    cout << "-> Elements After max heapifying: A[6] = {-1, 54, 53, 55, 52, 50}" << endl;
    for(int i = 1; i <= n; i++){
        cout << A[i] << " ";
    }

}