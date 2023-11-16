#include<bits/stdc++.h>
using namespace std;
#define printVec(v) for (int i = 0; i < v.size(); i++) cout << v[i] -> data << " "; cout<<endl

vector<int> V = {0, 1, 3, 5, 7, 11, 17, -1, -1, -1, -1, -1, -1, -1};
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

Node* buildFromLevelOrderTraversal(Node* root){
    queue<Node*> q;

    //cout << "\n-> Enter data: ";
    int value = V[i++];
    root = new Node(value);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // cout << "Enter data for left node: ";
        int leftData = V[i++];
        if(leftData != -1){
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        // cout << "Enter data for right node: ";
        int rightData = V[i++];
        if(rightData != -1){
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }

    }
    return root;
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
        // printVec(TEMP);
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
    Node* root = buildFromLevelOrderTraversal(root);
    
    cout << "\n\n>> Printing the data of the tree: \n";
    vector<vector<Node*>> Tree = levelWiseTraversal(root);

    printTree(Tree);
}