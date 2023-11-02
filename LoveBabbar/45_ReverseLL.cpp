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

    /* Insert at first */
    void insertAtHead(Node* &head, int data) {
        // new node create
        Node* temp = new Node(data);
        temp -> next = head;
        head = temp;
    }

    /* Insert at last */
    void insertAtTail(Node* &tail, int data) {
        // new node create
        Node* temp = new Node(data);
        tail -> next = temp;
        tail = temp;
    }

    /* Insert at any Index */
    void insertAt(Node* &head, Node* &tail, int index, int data) {
        if(index == 1){
            insertAtHead(head, data);
            return;
        }
        int count = 2;
        Node* traverse = head;
        while (count != index) { 
            count++; 
            traverse = traverse -> next;  
        }
        if(traverse -> next == NULL){
            insertAtTail(tail, data);
            return;
        }
        Node* temp = new Node(data);
        temp -> next = traverse -> next;
        traverse -> next = temp;
    }


    void deleteNode(Node* &head, int index) {
        if(index == 1) {
            Node* current = head;
            head = head -> next;
            current -> next = NULL;
            delete current;
        }
        else {
            Node* current = head;
            Node* previous = NULL;    
            int count = 1;
            while (count < index) {
                previous = current;
                current = current -> next;
                count++;
            }
            previous -> next = current -> next;
            current -> next = NULL;
            delete current;
        }
    }

    /* Get the index of a particular data in a linked list */
    int getIndex(Node* &head, int d){
        Node* traverse = head;
        int index = 1;
        while (traverse -> data != d){
            traverse = traverse -> next;
            index++;
        }
        return index;
    }

    /* Print the linked list */
    void printLinkedList(Node* &head) {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp -> data << "  ";
            temp = temp -> next;
        }
        cout << endl;
    }

    /* Get the size of the linked list */
    int LinkedListLength(Node* &head) {
        Node* temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp -> next;
        }
        return count;
    }

};


void reverseLL(Node* &head);
void reverseLLRecursively(Node* &head, Node* prev, Node* curr);

int main() {
    Node* linkedList = new Node(0);
    Node* head = linkedList;
    Node* tail = linkedList;

    linkedList -> insertAtHead(head, -2);
    linkedList -> insertAtHead(head, -3);
    linkedList -> insertAtHead(head, -4);
    linkedList -> insertAtHead(head, -5);
    
    linkedList -> insertAtTail(tail, 2);
    linkedList -> insertAtTail(tail, 3);
    linkedList -> insertAtTail(tail, 4);
    linkedList -> insertAtTail(tail, 5);

        
    cout << endl << endl << "Size of the linked list: " << linkedList -> LinkedListLength(head) << endl;
    cout << "-> Linked List elements are: " << endl << endl;
    linkedList -> printLinkedList(head);

    //reverseLL(head);
    Node* curr = head;
    Node* prev = NULL;
    reverseLLRecursively(head, prev, curr);


    cout << endl << endl << "Size of the linked list: " << linkedList -> LinkedListLength(head) << endl;
    cout << "-> Linked List elements are: " << endl << endl;
    linkedList -> printLinkedList(head);

    
}

// REVERSING A LINKED LIST NORMALLY: 
void reverseLL(Node* &head){
    Node* forward;
    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;

}

// REVERSING A LINKED LIST RECURSIVELY: 
void reverseLLRecursively(Node* &head, Node* prev, Node* curr){
    // Base Case 
    if(curr == NULL){
        head = prev;
        return;
    }
    Node* forward = curr -> next;
    reverseLLRecursively(head, forward, curr);
    curr -> next = prev;

}