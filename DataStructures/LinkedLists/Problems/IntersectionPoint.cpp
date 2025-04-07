#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

int getLength(Node* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

Node* getIntersection(Node* headA, Node* headB) {
    int lenA = getLength(headA);
    int lenB = getLength(headB);

    while (lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while (lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    while (headA && headB) {
        if (headA == headB)
            return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return nullptr;
}

int main() {
    // Common nodes
    Node* common = new Node(8);
    common->next = new Node(10);

    // First list: 3->7->8->10
    Node* headA = new Node(3);
    headA->next = new Node(7);
    headA->next->next = common;

    // Second list: 99->1->8->10
    Node* headB = new Node(99);
    headB->next = new Node(1);
    headB->next->next = common;

    Node* intersection = getIntersection(headA, headB);
    if (intersection)
        cout << "Intersection at node with value: " << intersection->data << endl;
    else
        cout << "No intersection." << endl;

    return 0;
}
