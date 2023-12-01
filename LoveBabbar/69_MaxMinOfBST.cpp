#include<bits/stdc++.h>
using namespace std;
#define printVec(v) for (int i = 0; i < v.size(); i++) cout << v[i] -> data << " "; cout<<endl


// vector<int> V = {0, 1, 3, 5, 17, 16, 7, 11, 6, 2, 3, 9, 17, 13, -1};
// vector<int> V = {0, 1, 3, 7, 11, 5, 17, -1};
vector<int> V = {0, 10, 8, 21, 7, 27, 5, 4, 3, -1};
int i = 1;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST(Node* &root, int value){
    if(root == NULL){
        root = new Node(value);
        return root;
    }
    
    if(value > root -> data){
        root -> right = insertIntoBST(root -> right, value);
    }
    else{
        root -> left = insertIntoBST(root -> left, value);
    }
    return root;
}

void takeInput(Node* &root){
    int data = V[i++];
    // cin >> data;
    while (data != -1){
        insertIntoBST(root, data);
        // cin >> data;
        data = V[i++];
    }
    
}

int maxOfBST(Node* &root){
    Node* temp = root;
    while (temp -> right != NULL){
        temp = temp -> right;
    }
    return temp -> data;
}

int minOfBST(Node* &root){
    Node* temp = root;
    while (temp -> left != NULL){
        temp = temp -> left;
    }
    return temp -> data;
}

int main(){
    Node* root = NULL;
    
    // cout << "Enter data to create BST: ";
    takeInput(root);

    int maxi = maxOfBST(root);
    int mini = minOfBST(root);

    cout << "Minimum of a BST: " << maxi << endl;
    cout << "Maximum of a BST: " << mini << endl;
}