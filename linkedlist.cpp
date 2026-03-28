#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


void insert(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(Node*& head){
    Node* temp =head->next;
    while(temp->next !=NULL){
        
    }
}

