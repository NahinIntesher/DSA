#include<bits/stdc++.h>
using namespace std;

vector<int> A = {0, 1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
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

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void inOrder(Node* root){
    if(root == NULL){
        return;
    }
    inOrder(root -> left);
    cout << root -> data << " ";
    inOrder(root -> right);
}

void postOrder(Node* root){
    if(root == NULL){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int main(){
    Node* root = NULL;
    root = buildTree(root);
    cout << endl << "Pre Order : ";
    preOrder(root);

    cout << endl << endl << "In Order : ";
    inOrder(root);

    cout << endl << endl << "Post Order : ";
    postOrder(root);

}