#include<bits/stdc++.h>
using namespace std;
#define printVec(v) for (int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl

// vector<int> A = {0, 1, 3, 5, 17, -1, -1, 16, -1, -1, 7, -1, -1, 
// 11, 6, 2, -1, -1, 3, -1, -1, 9, 17, -1, -1, 13, -1, -1};
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

vector<int> iterativePre(Node* root){
    vector<int> v;
    if(root == NULL) return v;

    stack<Node*> st;
    st.push(root);

    while (!st.empty()){
        root = st.top();
        st.pop();
        
        v.push_back(root -> data);
        
        if(root -> right)
            st.push(root -> right);
        
        if(root -> left)
            st.push(root -> left);
    }
    return v;
}

vector<int> iterativeIn(Node* root){
    stack<Node*> st;
    vector<int> v;
    Node* node = root;
    while (true){

        if(node != NULL){
            st.push(node);
            node = node -> left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            v.push_back(node -> data);
            node = node -> right;
        }
    }
    return v;
}

vector<int> iterativePost(Node* root){
    vector<int> v;
    if(root == NULL) return v;

    stack<Node*> st, st2;
    st.push(root);

    while (!st.empty()){
        root = st.top();
        st.pop();
        st2.push(root);
        
        if(st2.top() -> left != NULL){
            st.push(root -> left);
        }
        if(root -> right != NULL){
            st.push(root -> right);
        }
    }

    while (!st2.empty()){
        v.push_back(st2.top() -> data);
        st2.pop();
    }
    return v;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout << endl << "-> Pre Order : ";
    vector<int> ans = iterativePre(root);
    printVec(ans);

    cout << endl << "-> In Order : ";
    vector<int> ans2 = iterativeIn(root); 
    printVec(ans2);

    cout << endl << "-> Post Order : ";
    vector<int> ans3 = iterativePost(root);
    printVec(ans3);

}