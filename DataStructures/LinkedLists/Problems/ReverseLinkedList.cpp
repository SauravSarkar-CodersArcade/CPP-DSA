#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

void printList(Node* head){
    while (head != nullptr){
        cout << head->data << "->";
        head = head->next;
    }
    cout << "null" << endl;
}

void insertAtTail(Node** head, int value){
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    if (*head == nullptr){
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

void reverseList(Node** head){
    Node* prev = nullptr;
    Node* current = *head;
    Node* nextNode = nullptr;

    while (current != nullptr){
        nextNode = current->next;   // store next
        current->next = prev;       // reverse
        prev = current;             // move prev
        current = nextNode;         // move curr
    }
    *head = prev; // new head
}

int main(){
    Node* head = nullptr;
    int arr[] = {1,2,3,4,5};
    for (int val : arr){
        insertAtTail(&head, val);
    }

    cout << "Original List: ";
    printList(head);

    reverseList(&head);

    cout << "Reversed List: ";
    printList(head);
    return 0;
}
