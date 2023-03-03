#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

void insertAtTail(Node* &head, int val) {
    Node* n = new Node(val);
    if (head == NULL) {
        head = n;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = n;
}

bool hasCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return false;
    }
    Node* slow = head;
    Node* fast = head->next;
    while (slow != fast) {
        if (fast == NULL || fast->next == NULL) {
            return false;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main() {
    Node* head = NULL;
    int arr[] = {3, 2, 0, -4};
    int n = sizeof(arr)/sizeof(arr[0]);
    int pos = 1;
    for (int i = 0; i < n; i++) {
        insertAtTail(head, arr[i]);
    }
    Node* temp = head;
    while (pos--) {
        temp = temp->next;
    }
    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    tail->next = temp;
    cout << boolalpha << hasCycle(head) << endl;

    return 0;
}
