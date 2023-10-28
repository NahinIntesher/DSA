#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    /* Constructor*/
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    /* Destructor*/
    ~Node() {
        int value = this -> data;
        // Memory free
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
        cout << "Memory is free for node with data : " << value <<endl;
    }

};

/* Insert node after the element given */
void insertNode(Node* &tail, int element, int data) {
        
    // Empty list
    if(tail == NULL){
        Node* newNode = new Node(data);
        tail = newNode;
        newNode -> next = newNode;
    }

    // Non empty
    else{
        Node * current = tail;
        while (current -> data != element){
            current = current -> next;
        }
            
        // Element found -> current is representing that element

        Node *temp = new Node(data);
        temp -> next = current -> next;
        current -> next = temp;
    }
}

/* Delete node of the given input element */
void deleteNode(Node* &tail, int data) {
        
    // Empty list
    if(tail == NULL){
        cout << "List is empty.." << endl;
    }

    // Single Element present
    else if(tail -> next == tail){
        tail -> next = NULL;
        tail == NULL;
        delete tail;
    }

    // Non empty
    else{
        Node* previous = tail;
        Node* head = tail;
        while (previous -> next -> next -> data != data){
            previous = previous -> next;
        }
        // Element found -> Node after previous is representing that element
    
        Node* current = previous -> next;
        previous -> next = current -> next;
        current -> next = NULL;
        delete current;
        
    }
}

/* Print the linked list */
void printLinkedList(Node* tail) {
    Node* temp = tail;
    do {
        cout << tail -> data << "  ";
        tail = tail -> next;
    } while (tail != temp);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    insertNode(tail, 3, 6);
    insertNode(tail, 3, 9);
    insertNode(tail, 3, 5);
    insertNode(tail, 3, 4);

    cout << endl << "-> Linked List elements are: " << endl;
    printLinkedList(tail);

    //deleteNode(tail, 6);
    deleteNode(tail, 3);

    cout << endl << "-> Linked List elements are: " << endl;
    printLinkedList(tail);
    
    cout << endl << "Head: " << tail -> next -> data << endl;
    cout << "Tail: " << tail -> data << endl;
    
}
