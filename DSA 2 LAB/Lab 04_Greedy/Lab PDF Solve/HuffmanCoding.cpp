#include <bits/stdc++.h>
using namespace std;

class node {
  public:
	char data;
	int freq;
	node *left;
	node *right;
} typedef node;

struct compare {
	bool operator()(node* l, node* r){
		if (l -> freq > r -> freq) 
            return true;
		else
            return false;
	}
};

void printCodes(struct node* root, string str) {
	if (root == NULL) return;
	if (root->data != '$') {
        cout << root -> data << ": " << str << "\n";
	}

	printCodes(root -> left, str + "0");
	printCodes(root -> right, str + "1");
}

void HuffmanCodes(char data[], int freq[], int n) {
    node *left, *right, *top;

	priority_queue<node*, vector<node*>, compare> minHeap;
	for (int i = 0; i < n; ++i) {
        node *temp = new node();
        temp -> data = data[i];
        temp -> freq = freq[i];
        temp -> left = NULL;
        temp -> right = NULL;
		minHeap.push(temp);
    }

	for (int i=0; i<n-1; i++) {
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		top = new node();

		top -> data = '$';
        top -> freq = (left -> freq + right -> freq);

		top -> left = left;
		top -> right = right;

		minHeap.push(top);
	}
	printCodes(minHeap.top(), "");
}

int main() {
    int n;
    cin >> n;

	char arr[n];
	int freq[n];

	for(int i=0; i<n; i++) {
        cin >> arr[i];
        cin >> freq[i];
	}
	HuffmanCodes(arr, freq, n);

}