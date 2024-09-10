#include <iostream>
using namespace std;
class Node {
private:
    int data;
    int priority;
    Node* next;
public:
    Node(int d, int p){
        data = d;
        priority = p;
        next = nullptr;
    }
    // Getters
    // data, priority, nextNode
    int getData(){
        return data;
    }
    int getPriority(){
        return priority;
    }
    Node* getNext(){
        return next;
    }
    void setNext(Node* node){
        next = node;
    }
};
// Function to create a new node
Node* newNode(int d, int p){
    return new Node(d,p);
}
// peek
int peek(Node** head){
    return (*head)->getData();
}
// pop
void pop(Node** head){
    Node* temp = *head;
    (*head) = (*head)->getNext();
    delete temp;
}
// push - insert
void push(Node** head, int d, int p){
    Node* start = *head;
    Node* temp = newNode(d,p);
    if ((*head)->getPriority() < p){
        temp->setNext(*head);
        (*head) = temp;
    } else{
        while (start->getNext() != nullptr &&
        start->getNext()->getPriority() > p){
            start = start->getNext();
        }
        temp->setNext(start->getNext());
        start->setNext(temp);
    }
}
bool isEmpty(Node** head){
    return (*head) == nullptr;
}
int main() {
    // p d 1st
    Node* pq = newNode(4,1);
    push(&pq,5,2);
    push(&pq,2,3);
    push(&pq,7,0);
    push(&pq,8,0);
    push(&pq,9,0);
    push(&pq,7,5);
    while (!isEmpty(&pq)){
        cout << " " << peek(&pq);
        pop(&pq);
    }
    return 0;
}
