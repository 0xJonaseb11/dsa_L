
#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(NULL) {}
};

// Function to find the mid-point of a linked list
Node* mid_point(Node* head) {
    // base case
    if (head == NULL || head->next == NULL)
        return head;
    // recursive case
    Node* fast = head;
    Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next;
        if (fast->next == NULL)
            break;
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* a, Node* b) {
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    Node* result = NULL;
    if (a->data <= b->data) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }
    return result;
}

// Function to perform merge sort on a linked list
Node* merge_sort(Node* head) {
    // base case
    if (head == NULL || head->next == NULL)
        return head;

    // recursive case
    // Step 1: divide the linked list into
    // two equal linked lists
    Node* mid = mid_point(head);
    Node* a = head;
    Node* b = mid->next;

    mid->next = NULL;

    // Step 2: recursively sort the smaller
    // linked lists
    a = merge_sort(a);
    b = merge_sort(b);

    // Step 3: merge the sorted linked lists
    Node* c = merge(a, b);

    return c;
}

// Utility function to print the linked list
void printList(Node* node) {
    while (node != NULL) {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main() {

    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    std::cout << "Original list: ";
    printList(head);

    head = merge_sort(head);

    std::cout << "Sorted list: ";
    printList(head);

    // Free memory
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}











Message general









