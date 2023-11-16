#include<bits/stdc++.h>
using namespace std;

vector<int> A = {0, 1, 3, 5, 17, -1, -1, 16, -1, -1, 7, -1, -1, 
11, 6, 2, -1, -1, 3, -1, -1, 9, 17, -1, -1, 13, -1, -1};
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

Node* buildTree(Node* root){
    int data = A[i++];
    root = new Node(data);
    
    if(data == -1){
        return NULL;
    }

    root -> left = buildTree(root -> left);
    root -> right = buildTree(root -> right);

    return root;
}

int treeTraverse(Node* root, int leaf){
    if(root == NULL) {
        return leaf;
    }
    // An extra condition
    else if(root -> left == NULL && root -> right == NULL){
        leaf++;
        return leaf;
    }
    //cout << root -> data << " ";
    leaf = treeTraverse(root -> left, leaf);
    leaf = treeTraverse(root -> right, leaf);
    
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    // cout << endl << endl << "Post Order : ";
    int count = treeTraverse(root, 0);
    cout << "\n-> Number of Leaf Nodes: " << count;
}