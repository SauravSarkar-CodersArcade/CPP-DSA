#include <iostream>
#include <cstdint>
using namespace std;

class XORLinkedList {
private:
    struct Node {
        int data;
        Node* npx; // XOR of next and previous

        Node(int val) : data(val), npx(nullptr) {}
    };

    Node* head;

    // XOR helper
    Node* XOR(Node* a, Node* b) {
        return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
    }

public:
    XORLinkedList() : head(nullptr) {}

    // Insert at the beginning
    void insertFront(int val) {
        Node* newNode = new Node(val);
        newNode->npx = XOR(nullptr, head);

        if (head != nullptr) {
            Node* next = XOR(nullptr, head->npx);
            head->npx = XOR(newNode, next);
        }

        head = newNode;
    }

    // Traverse and print the list
    void printList() {
        Node* curr = head;
        Node* prev = nullptr;
        Node* next;

        cout << "XOR Linked List: ";
        while (curr != nullptr) {
            cout << curr->data << " ";
            next = XOR(prev, curr->npx);
            prev = curr;
            curr = next;
        }
        cout << endl;
    }
};

int main() {
    XORLinkedList list;

    list.insertFront(10);
    list.insertFront(20);
    list.insertFront(30);
    list.insertFront(40);

    list.printList(); // Output: 30 20 10

    return 0;
}
