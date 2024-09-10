#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void printListElements(Node* head){
    if (head == nullptr){
        cout << "List is empty." << endl;
        return;
    }
    Node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "head" << endl;
}
void insertAtFront(Node** head, int newValue){
    Node* newNode = new Node();
    newNode->data = newValue;
    if (*head == nullptr){
        newNode->next = newNode; // Points to itself
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != *head){
        last = last->next;
    }
    newNode->next = *head;
    last->next = newNode;
    *head = newNode;
}
void insertAtEnd(Node** head, int newValue){
    Node* newNode = new Node();
    newNode->data = newValue;
    if (*head == nullptr){
        newNode->next = newNode; // Points to itself
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != *head){
        last = last->next;
    }
    last->next = newNode;
    newNode->next = *head;
}
void insertAfterSpecific(Node* previous, int newValue){
    if (previous == nullptr){
        cout << "Previous node cannot be null." << endl;
        return;
    }
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = previous->next;
    previous->next = newNode;
}
void deleteFrontNode(Node** head){
    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the head." << endl;
        return;
    }
    Node* temp = *head;
    // Single element
    if ((*head)->next == *head){
        delete *head;
        *head = nullptr;
        return;
    }
    Node* last = *head;
    while (last->next != *head){
        last = last->next;
    }
    *head = (*head)->next;
    last->next = *head;
    delete temp;
}
void deleteEndNode(Node** head){
    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the head." << endl;
        return;
    }
    // Single element
    if ((*head)->next == *head){
        delete *head;
        *head = nullptr;
        return;
    }
    Node* secondLast = *head;
    Node* last = (*head)->next;
    while (last->next != *head){
        secondLast = last;
        last = last->next;
    }
    secondLast->next = *head;
    delete last;
}
int main() {
    Node* head = nullptr;
    insertAtFront(&head,3);
    insertAtFront(&head,2);
    insertAtFront(&head, 0);
    int arr[] = {4,5,6};
    int size = sizeof (arr) / sizeof (arr[0]);
    for (int i = 0; i < size; ++i) {
        insertAtEnd(&head, arr[i]);
    }
//  insertAfterSpecific(nullptr, 1);
    insertAfterSpecific(head,1);
    printListElements(head);
    cout << "List before deleting head: ";
    printListElements(head);
    deleteFrontNode(&head);
    cout << "List after deleting head: ";
    printListElements(head);
    cout << "List before deleting tail: ";
    printListElements(head);
    deleteEndNode(&head);
    cout << "List after deleting tail: ";
    printListElements(head);
    return 0;
}
