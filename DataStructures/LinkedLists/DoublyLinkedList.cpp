#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;
};

void printListElements(Node* node) {
    while (node != nullptr) {
        cout << node->data << " <-> ";
        node = node->next;
    }
    cout << "null" << endl;
}

void insertAtFront(Node** head, int newValue) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = *head;
    newNode->prev = nullptr;

    // Adjust the previous head node's prev pointer
    if (*head != nullptr) {
        (*head)->prev = newNode;
    }

    // Move head to point to the new node
    *head = newNode;
}

void insertAtEnd(Node** head, int newValue) {
    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = nullptr;

    // If the list is empty, make the new node the head
    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }

    // Traverse to the end of the list
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Adjust pointers to add the new node at the end
    last->next = newNode;
    newNode->prev = last;
}

void insertAfterSpecific(Node* previous, int newValue) {
    // Check if the previous node is null
    if (previous == nullptr) {
        cout << "Previous node cannot be null." << endl;
        return;
    }

    // Create a new node
    Node* newNode = new Node();
    newNode->data = newValue;
    newNode->next = previous->next;
    newNode->prev = previous;

    // Adjust pointers of the next node, if it exists
    if (previous->next != nullptr) {
        previous->next->prev = newNode;
    }

    // Adjust the previous node's next pointer
    previous->next = newNode;
}

void deleteFrontNode(Node** head) {
    // Check if the list is empty
    if (*head == nullptr) {
        cout << "List is empty. Can't delete head." << endl;
        return;
    }

    // Temporary node to reference the head
    Node* temp = *head;
    *head = (*head)->next;

    // If the new head exists, adjust its prev pointer
    if (*head != nullptr) {
        (*head)->prev = nullptr;
    }

    delete temp;
}

void deleteEndNode(Node** head) {
    // Check if the list is empty
    if (*head == nullptr) {
        cout << "List is empty. Can't delete last." << endl;
        return;
    }

    // If the list has only one node
    if ((*head)->next == nullptr) {
        delete *head;
        *head = nullptr;
        return;
    }

    // Traverse to the last node
    Node* last = *head;
    while (last->next != nullptr) {
        last = last->next;
    }

    // Adjust pointers to remove the last node
    Node* secondLast = last->prev;
    secondLast->next = nullptr;
    delete last;
}

void deleteSpecificNodeWithTargetValue(Node** head, int target) {
    // Check if the list is empty
    if (*head == nullptr) {
        cout << "List is empty. Can't delete node." << endl;
        return;
    }

    // Target node is the head node
    if ((*head)->data == target) {
        Node* temp = *head;
        *head = (*head)->next;

        // Adjust the new head's prev pointer if it exists
        if (*head != nullptr) {
            (*head)->prev = nullptr;
        }

        delete temp;
        return;
    }

    // Two pointers to find and delete the target node
    Node* curr = *head;
    while (curr != nullptr && curr->data != target) {
        curr = curr->next;
    }

    if (curr == nullptr) {
        cout << "The target value is not available." << endl;
        return;
    }

    // Adjust pointers to delete the node
    curr->prev->next = curr->next;
    if (curr->next != nullptr) {
        curr->next->prev = curr->prev;
    }

    delete curr;
}

Node* reverseLinkedList(Node* head) {
    Node* temp = nullptr;
    Node* current = head;

    // Traverse the list and reverse the links
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Update head to the new head after reversal
    if (temp != nullptr) {
        head = temp->prev;
    }

    return head;
}

int main() {
    Node* head = nullptr;

    // Insert nodes
    insertAtFront(&head, 3);
    insertAtFront(&head, 2);
    insertAtFront(&head, 0);
    int arr[] = {4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        insertAtEnd(&head, arr[i]);
    }
    insertAfterSpecific(head, 1);

    // Print list and perform operations
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

    int targetVal;
    cout << "Enter the target value: " << endl;
    cin >> targetVal;
    cout << "List before deletion of target " << targetVal << "->";
    printListElements(head);
    deleteSpecificNodeWithTargetValue(&head, targetVal);
    cout << "List after deletion of target " << targetVal << "->";
    printListElements(head);

    cout << "Before reversal: ";
    printListElements(head);
    head = reverseLinkedList(head);
    cout << "After reversal: ";
    printListElements(head);

    return 0;
}
