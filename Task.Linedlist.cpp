#include <iostream>

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) : data(data), prev(NULL), next(NULL) {}
};

class DoublyLinkedList {
public:
    Node* head; 

public:
    DoublyLinkedList() : head(NULL) {}

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) { 
            head = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) { 
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void insertAfter(Node* prevNode, int data) {
        if (prevNode == NULL) {
            std::cout << "Previous node cannot be NULL" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next != NULL) {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
    }

    void insertBefore(Node* nextNode, int data) {
        if (nextNode == NULL) {
            std::cout << "Next node cannot be NULL" << std::endl;
            return;
        }
        Node* newNode = new Node(data);
        newNode->prev = nextNode->prev;
        newNode->next = nextNode;
        if (nextNode->prev != NULL) {
            nextNode->prev->next = newNode;
        } else {
            head = newNode;
        }
        nextNode->prev = newNode;
    }

    void display() {
        if (head == NULL) {
            std::cout << "Doubly Linked List is empty" << std::endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void deleteNode(int key) {
        Node* temp = head;
        while (temp != NULL && temp->data != key) {
            temp = temp->next;
        }
        if (temp == NULL) { 
            std::cout << "Key not found in the list" << std::endl;
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        } else { 
            head = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }
};

int main() {
DoublyLinkedList list;

    int numElements;
    std::cout << "Enter the number of elements: ";
    std::cin >> numElements;

    std::cout << "Enter the elements: ";
    for (int i = 0; i < numElements; ++i) {
        int element;
        std::cin >> element;
        list.insertAtEnd(element);
    }

    std::cout << "Doubly Linked List: ";
    list.display();
    
    int choice, data, position;
    std::cout << "Enter the number to be deleted: ";
    std::cin >> data;
    list.deleteNode(data);
    list.display();
    
    std::cout << "Enter the operation you want to perform:\n";
    std::cout << "1. Insert at beginning\n";
    std::cout << "2. Insert at end\n";
    std::cout << "3. Insert after a given node\n";
    std::cout << "4. Insert before a given node\n";
    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << "Enter the number to be inserted at the beginning: ";
            std::cin >> data;
            list.insertAtBeginning(data);
            break;
        case 2:
            std::cout << "Enter the number to be inserted at the end: ";
            std::cin >> data;
            list.insertAtEnd(data);
            break;
        case 3: {
            std::cout << "Enter the number to be inserted: ";
            std::cin >> data;
            std::cout << "Enter the number after which you want to insert: ";
            std::cin >> position;
            Node* temp = list.head;
            while (temp != NULL && temp->data != position) {
                temp = temp->next;
            }
            list.insertAfter(temp, data);
            break;
        }
        case 4: {
            std::cout << "Enter the number to be inserted: ";
            std::cin >> data;
            std::cout << "Enter the number before which you want to insert: ";
            std::cin >> position;
            Node* temp = list.head;
            while (temp != NULL && temp->data != position) {
                temp = temp->next;
            }
            list.insertBefore(temp, data);
            break;
        }
        default:
            std::cout << "Invalid choice\n";
    }

    std::cout << "Doubly Linked List after insertion: ";
    list.display();
    
    return 0;
}
