#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
};
void printListElements(Node* node){
    while (node != nullptr){
        cout << node->data << "->";
        node = node->next;
    }
    cout << "null";
}
void insertAtFront(Node** head,  int newValue){
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    // Set the new node to point to the head
    newNode->next = *head;
    // Make the head point to the new node
    *head = newNode;
}
void insertAtTail(Node** head, int newValue){
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    // This will become the tail, and tail points to null
    newNode->next = nullptr;
    // Empty List
    if (*head == nullptr){
        *head = newNode;
        return;
    }
    // Multiple Nodes
    Node* last = *head;
    while (last->next != nullptr){
        last = last->next;
    }
    // Add the new node to the end of last node (tail)
    last->next = newNode;
}
void insertAfterSpecific(Node* previous, int newValue){
    if (previous == nullptr){
        cout << "Previous node cannot be null." << endl;
        return;
    }
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = previous->next;
    previous->next = newNode;
}
// Delete Operations :
void deleteFrontNode(Node** head){
    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the head." << endl;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    delete temp;
}
void deleteEndNode(Node** head){
    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the tail." << endl;
        return;
    }
    // Single node
    if ((*head)->next == nullptr){
        delete *head;
        *head = nullptr;
        return;
    }
    // Multiple nodes -> Traverse till the end and find the last node
    Node* last = *head;
    Node* secondLast = nullptr;
    while (last->next != nullptr){
        secondLast = last;
        last = last->next;
    }
    delete last;
    secondLast->next = nullptr;
}
void deleteSpecificNodeWithTarget(Node** head, int target){
    // Check if the list is empty
    if (*head == nullptr){
        cout << "List is empty. Can't delete the target node." << endl;
        return;
    }
    // Head is the target node
    if ((*head)->data == target){
        Node* temp = *head;
        (*head) = (*head)->next;
        delete temp;
        return;
    }
    // Two pointer approach
    Node* curr = *head;
    Node* prev = nullptr;
    // Till we don't find the target or reach the end of the list we traverse
    while (curr != nullptr && curr->data != target){
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr){
        cout << "The target value is not found in the list." << endl;
        return;
    }
    prev->next = curr->next;
    delete curr;
}
int main() {
    // Manual Entry 1->2->3->null
//    Node* head = new Node();
//    head->data = 1;
//    Node* second = new Node();
//    second->data = 2;
//    Node* third = new Node();
//    third->data = 3;
//    head->next = second;
//    second->next = third;
//    third->next = nullptr;
    Node* head = nullptr;
    insertAtFront(&head, 3);
    insertAtFront(&head,2);
    insertAtFront(&head,0);
    int arr[] = {4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<size; i++){
        insertAtTail(&head, arr[i]);
    }
    insertAfterSpecific(head, 1);
    cout << "List before deleting the head: " << endl;
    printListElements(head);
    cout << endl;
    deleteFrontNode(&head);
    cout << "List after deleting the head: " << endl;
    printListElements(head);
    cout << endl;
    cout << "List before deleting the tail: " << endl;
    printListElements(head);
    cout << endl;
    deleteEndNode(&head);
    cout << "List after deleting the tail: " << endl;
    printListElements(head);
    cout << endl;
    int targetValue;
    cout << "Enter a target node to be deleted:" << endl;
    cin >> targetValue;
    cout << "List before deleting the target: " << targetValue << endl;
    printListElements(head);
    cout << endl;
    deleteSpecificNodeWithTarget(&head, targetValue);
    cout << "List after deleting the target: " << targetValue << endl;
    printListElements(head);
    return 0;
}
