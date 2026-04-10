#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = prev = nullptr;
    }
};

Node* head = nullptr;

// Insert at Head
void insertAtHead(int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void printList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printListReverse() {
    Node* itr = head;
    while (itr && itr->next != nullptr) {
        itr = itr->next;
    }
    while (itr != nullptr) {
        cout << itr->val << " ";
        itr = itr->prev;
    }
    cout << endl;
}

int main() {
    insertAtHead(2);
    insertAtHead(5);
    insertAtTail(8);
    insertAtTail(4);

    printList();         // 5 2 8 4
    printListReverse();  // 4 8 2 5
}