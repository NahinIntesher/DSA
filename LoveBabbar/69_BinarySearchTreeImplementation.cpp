#include<bits/stdc++.h>
using namespace std;
#define printVec(v) for (int i = 0; i < v.size(); i++) cout << v[i] -> data << " "; cout<<endl


vector<int> V = {0, 1, 3, 5, 17, 16, 7, 11, 6, 2, 3, 9, 17, 13, -1};
// vector<int> V = {0, 1, 3, 7, 11, 5, 17, -1};
// vector<int> V = {0, 10, 8, 21, 7, 27, 5, 4, 3, -1};
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

vector<vector<Node*>> levelWiseTraversal(Node* root){
    vector<vector<Node*>> Tree;
    if(root == NULL) return Tree;
    
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        vector<Node*> level;
        while (!q.empty()){
            level.push_back(q.front());
            q.pop();
        }

        for (int i = 0; i < level.size(); i++){
            Node* tempNode = level[i];
            if(tempNode -> left){
                q.push(tempNode -> left);
            }
            if(tempNode -> right){
                q.push(tempNode -> right);
            }
        }
        Tree.push_back(level);
        level.clear();        

    }
    return Tree;
}

void printTree(vector<vector<Node*>> Tree){
    for (int i = 0; i < Tree.size(); i++) { 
        for (int j = 0; j < Tree[i].size(); j++) {
            cout << Tree[i][j] -> data << " "; 
        }
        cout << endl; 
    } 
}

int main(){
    Node* root = NULL;
    
    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "\n\n>> Printing the data of the tree: \n";
    vector<vector<Node*>> Tree = levelWiseTraversal(root);

    printTree(Tree);
}