#include<bits/stdc++.h>
using namespace std;
#define printVec(v) for (int i = 0; i < v.size(); i++) cout << v[i] -> data << " "; cout<<endl


vector<int> V = {0, 1, 3, 5, 17, -1, -1, 16, -1, -1, 7, -1, -1, 
11, 6, 2, -1, -1, 3, -1, -1, 9, 17, -1, -1, 13, -1, -1};
// vector<int> V = {0, 1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
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

    //cout << "\n-> Enter data: ";
    int value = V[i++];
    root = new Node(value);

    if(value == -1){
        return NULL;
    }

    //cout << "-> Enter data for inserting left of " << value << endl;
    root -> left = buildTree(root -> left);
    //cout << "-> Enter data for inserting right of " << value << endl;
    root -> right = buildTree(root -> right);

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
    Node* root;
    root = buildTree(root);
     
    cout << "\n\n>> Printing the data of the tree: \n";
    vector<vector<Node*>> Tree = levelWiseTraversal(root);

    printTree(Tree);
}