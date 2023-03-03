#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head, int pos) {
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            // Cycle detected, now find the starting position
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            if (pos == -1) {
                return false; // Cycle not expected
            } else if (slow == head) {
                return true; // Cycle starts at head
            } else {
                return false; // Cycle starts at some other position
            }
        }
    }
    return pos == -1; // No cycle expected
}

int main() {
    // Create a linked list with no cycle
    ListNode *head = new ListNode(1);

    // Test if the linked list has a cycle starting at position -1
    bool has_cycle = hasCycle(head, -1);
    if (has_cycle) {
        cout << "The linked list has a cycle starting at position -1." << endl;
    } else {
        cout << "The linked list does not have a cycle starting at position -1." << endl;
    }

    // Clean up memory
    delete head;

    return 0;
}
