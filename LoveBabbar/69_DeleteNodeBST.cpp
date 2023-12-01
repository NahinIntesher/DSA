#include<bits/stdc++.h>
using namespace std;
#define printVec(v) for (int i = 0; i < v.size(); i++) cout << v[i] -> data << " "; cout<<endl

vector<int> V = {0, 50, 20, 70, 10, 30, 90, 110, -1};
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
    while (data != -1){
        insertIntoBST(root, data);
        data = V[i++];
    }
}

/* For sucsessor while deleting a Node having 2 child */
int minVal(Node* &root){
    Node* temp = root;
    while (temp -> left != NULL){
        temp = temp -> left;
    }
    return temp -> data;
}

Node* deleteNodeBST(Node* root, int x){
    if(root == NULL){
        return root;
    }
    
    if(root -> data == x){

        /* For Zero Child  Node */
        if(root -> left == NULL && root -> right == NULL){
            delete root;
            return NULL;
        }

        /* For One child Node*/ 
        else if(root -> left == NULL && root -> right != NULL){ // Only left child
            Node* leftChild = root -> left;
            delete root;
            return leftChild;
        }
        else if(root -> left != NULL && root -> right == NULL){ // Only right child
            Node* rightChild = root -> right;
            delete root;
            return rightChild;
        }


        /* For Two child Node */
        else if(root -> left != NULL && root -> right != NULL){
            int mini = minVal(root -> right);
            root -> data = mini;

            // Recursive delete call for Node with having mini data in the right 
            root -> right = deleteNodeBST(root -> right, mini);
            return root;
        }
    }
    else if(x > root -> data){
        root -> right = deleteNodeBST(root -> right, x);
        return root;
    }
    else{
        root -> left = deleteNodeBST(root -> left, x);
        return root;
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
    takeInput(root);
    
    vector<vector<Node*>> Tree = levelWiseTraversal(root);
    cout << "\n\n>> Printing the data of the tree: \n";
    printTree(Tree);

    root = deleteNodeBST(root, 90);
    Tree = levelWiseTraversal(root);
    cout << "\n\n>> Printing the data of the tree: \n";
    printTree(Tree);
}