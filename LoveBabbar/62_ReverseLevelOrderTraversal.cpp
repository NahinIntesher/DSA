#include<bits/stdc++.h>
using namespace std;

vector<int> v = {0, 1, 3, 7, -1, -1, 11, -1, -1, 5, 17, -1, -1, -1};
int i = 1;

class node {
    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {
    //cout << "Enter the data: " << endl;
    int data = v[i++];
    root = new node(data);    

    if(data == -1) {
        return NULL;
    }
    //cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);
    //cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);
    return root;

}

void reverselevelOrderTraversal(node* root) {
    queue<node*> q;
    stack<node*> s;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();
        if(temp == NULL) { 
            if(!q.empty()) { 
                // Stack still has some child ndoes
                q.push(NULL);
                s.push(NULL);
            }  
        }
        else{
            // cout << temp -> data << " ";
            s.push(temp);
            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
    while(!s.empty()){
        cout << "\t";
        if(s.top() == NULL){
            cout << endl << "\t";
            s.pop();
        }
        cout << s.top() -> data << " ";
        s.pop();
    }

}


int main() {

    node* root = NULL;

    root = buildTree(root);

    cout << "\n>> Printing the data of the tree: \n\n";
    reverselevelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1


    return 0;
}