#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* prev;

    /* Constructor*/
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
        this -> prev = NULL;
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


    void insertAtHead(Node* &head, Node* &tail, int data) {
        // Create new node
        Node* nodeToInsert = new Node(data);
        
        if(head == NULL){
            head = nodeToInsert;
            tail = nodeToInsert;
        }
        else{
            nodeToInsert -> next = head;
            head -> prev = nodeToInsert;
            head = nodeToInsert;
        }
        
    }

    /* Insert at last */
    void insertAtTail(Node* &head, Node* &tail, int data) {
        // Create new node
        Node* nodeToInsert = new Node(data);

        if(tail == NULL){
            tail = nodeToInsert;
            head = nodeToInsert;
        }
        else{
            nodeToInsert -> prev = tail;
            tail -> next = nodeToInsert;
            tail = nodeToInsert;
        }
    }

    /* Insert at any Index */
    void insertAt(Node* &head, Node* &tail, int index, int data) {
        if(index == 1){
            insertAtHead(head, tail, data);
            return;
        }
        int count = 2;
        Node* traverse = head;
        while (count != index) { 
            count++; 
            traverse = traverse -> next;  
        }
        if(traverse -> next == NULL){
            insertAtTail(head, tail, data);
            return;
        }
        Node* nodeToInsert = new Node(data);
        nodeToInsert -> prev = traverse;
        nodeToInsert -> next = traverse -> next;
        traverse -> next -> prev = nodeToInsert;
        traverse -> next = nodeToInsert;
    }

    /* Print the Linked List */
    void printLinkedList(Node* &head){
        Node* traverse = head;
        /* Ascending Order */
        while (traverse -> next != NULL){
            cout << traverse -> data << "  ";
            traverse = traverse -> next;
        }
        cout << traverse -> data << "  ";
        cout << endl;
        /* Descending Order 
        while (traverse -> prev != NULL){
            cout << traverse -> data << "  ";
            traverse = traverse -> prev;
        }
        cout << traverse -> data << "  ";
        cout << endl;
        */
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

    /* Delete Node At any position */
    void deleteNode(Node* &head, Node* &tail, int index){
        if(index == 1){
            Node* current = head;
            head -> next -> prev = NULL;
            head = head -> next;
            current -> next = NULL;
            delete current;
        }
        else{
            Node* current = head;
            Node* previous = NULL;    
            int count = 1;
            while (count < index){
                previous = current;
                current = current -> next;
                count++;
            }

            if(index == LinkedListLength(head)){
                previous -> next = NULL;
                tail = previous;
            }
            else{
                previous -> next = current -> next;
                current -> next -> prev = current -> prev;
            }
            
            current -> prev = NULL;
            current -> next = NULL;
            delete current;
        }
    }

};



int main(){
    Node* linkedList = new Node(5);
    Node* head = linkedList;
    Node* tail = linkedList;
    
    linkedList -> insertAtHead(head, tail, 4);
    linkedList -> insertAtHead(head, tail, 3);
    linkedList -> insertAtHead(head, tail, 2);
    linkedList -> insertAtHead(head, tail, 1);

    linkedList -> insertAtTail(head, tail, 6);
    linkedList -> insertAtTail(head, tail, 7);
    linkedList -> insertAtTail(head, tail, 8);

    linkedList -> insertAt(head, tail, 3, 0);
    linkedList -> insertAt(head, tail, 1, 9);
    
    linkedList -> printLinkedList(head);
    cout << linkedList -> LinkedListLength(head) << endl;

    linkedList -> deleteNode(head, tail, 10);

    linkedList -> printLinkedList(head);
    cout << linkedList -> LinkedListLength(head) << endl;

}