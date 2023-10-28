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

    
    
    linkedList -> insertAt(head, tail, 5, -1);
    linkedList -> insertAt(head, tail, 7 ,1);
 
    /* 2 Exceptional Cases: insert at 'head' and 'tail' using insertAt() function */
    linkedList -> insertAt(head, tail, 1 ,-10);
    int len = linkedList -> LinkedListLength(head);
    linkedList -> insertAt(head, tail, 13, 10);

    
    cout << endl << endl << "Size of the linked list: " << linkedList -> LinkedListLength(head) << endl;
    cout << "-> Linked List elements are: " << endl << endl;
    linkedList -> printLinkedList(head);

    cout << "Head: " << head -> data << endl;
    cout << "Tail: " << tail -> data << endl;
    
    linkedList ->deleteNode(head, 7);

    cout << endl << endl << "Size of the linked list: " << linkedList -> LinkedListLength(head) << endl;
    cout << "-> Linked List elements are: " << endl << endl;
    linkedList -> printLinkedList(head);
    


}
