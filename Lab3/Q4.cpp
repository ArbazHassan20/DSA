#include "iostream"
using namespace std;

class Node {
    int value;         // stores data
    Node* nextNode;    // pointer to the next node
    Node* prevNode;    // pointer to the previous node

public:
    Node() : value(0), nextNode(NULL), prevNode(NULL) {}           // Default constructor
    Node(const int data) : value(data), nextNode(NULL), prevNode(NULL) {}  // Parameterized constructor

    friend class DoublyLinkedList;  // Giving access to private members for the DoublyLinkedList class
};

class DoublyLinkedList {
    Node* headNode;   // pointer to the head node
    Node* tailNode;   // pointer to the tail node

public:
    DoublyLinkedList() : headNode(NULL), tailNode(NULL) {}  // Constructor to initialize empty list

    // Insert a node at the end of the list
    void insertAtEnd(const int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (headNode == NULL) {
            headNode = tailNode = newNode;  // If the list is empty, new node becomes both head and tail
        } else {
            tailNode->nextNode = newNode;   // Link current tail to the new node
            newNode->prevNode = tailNode;   // Set new node's previous pointer to the old tail
            tailNode = newNode;             // Update tail to the new node
        }
    }

    // Insert a node at the front of the list
    void insertAtFront(const int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (headNode == NULL) {
            headNode = tailNode = newNode;  // If the list is empty, new node becomes both head and tail
        } else {
            headNode->prevNode = newNode;   // Link current head's previous pointer to the new node
            newNode->nextNode = headNode;   // Set new node's next pointer to the old head
            headNode = newNode;             // Update head to the new node
        }
    }

    // Insert a node after a specific value
    void insertAfterValue(const int afterValue, const int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (headNode == NULL) {
            cout << "List not found." << endl;
            return;
        }
        Node* currentNode = headNode;
        while (currentNode->value != afterValue) {  // Traverse to find the node with afterValue
            currentNode = currentNode->nextNode;
            if (currentNode == NULL) {
                cout << "Value not found in the list." << endl;
                return;
            }
        }
        newNode->prevNode = currentNode;
        newNode->nextNode = currentNode->nextNode;
        if (currentNode->nextNode != NULL) {
            currentNode->nextNode->prevNode = newNode;  // Adjust the previous pointer of the next node
        }
        currentNode->nextNode = newNode;
    }

    // Insert a node before a specific value
    void insertBeforeValue(const int beforeValue, const int data) {
        Node* newNode = new Node(data);  // Create a new node
        if (headNode == NULL) {
            cout << "List not found." << endl;
            return;
        }
        Node* currentNode = headNode;
        while (currentNode->nextNode->value != beforeValue) {  // Traverse to find the node with beforeValue
            currentNode = currentNode->nextNode;
            if (currentNode->nextNode == NULL) {
                cout << "Value not found in the list." << endl;
                return;
            }
        }
        newNode->prevNode = currentNode;
        newNode->nextNode = currentNode->nextNode;
        currentNode->nextNode->prevNode = newNode;
        currentNode->nextNode = newNode;
    }

    // Delete the head node
    void deleteHead() {
        if (headNode == NULL) {
            cout << "List not found." << endl;
            return;
        }
        Node* tempNode = headNode;
        headNode = headNode->nextNode;
        if (headNode != NULL) {
            headNode->prevNode = NULL;
        } else {
            tailNode = NULL;  // If the list is now empty, reset the tail
        }
        delete tempNode;
    }

    // Delete the tail node
    void deleteTail() {
        if (tailNode == NULL) {
            cout << "List not found." << endl;
            return;
        }
        Node* tempNode = tailNode;
        tailNode = tailNode->prevNode;
        if (tailNode != NULL) {
            tailNode->nextNode = NULL;
        } else {
            headNode = NULL;  // If the list is now empty, reset the head
        }
        delete tempNode;
    }

    // Delete a specific value
    void deleteValue(const int val) {
        if (headNode == NULL) {
            cout << "List is empty." << endl;
            return;
        }
        Node* currentNode = headNode;
        while (currentNode->nextNode != NULL && currentNode->nextNode->value != val) {
            currentNode = currentNode->nextNode;
        }
        if (currentNode->nextNode == NULL) {
            cout << "Value not found in the list." << endl;
            return;
        }
        Node* tempNode = currentNode->nextNode;
        currentNode->nextNode = tempNode->nextNode;
        if (tempNode->nextNode != NULL) {
            tempNode->nextNode->prevNode = currentNode;
        }
        delete tempNode;
    }

    // Print the list's values
    void printList() {
        Node* currentNode = headNode;
        while (currentNode != NULL) {
            cout << currentNode->value << " ";  // Print each node's value
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    // Insert nodes at the end of the list
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.printList();

    // Insert node at the front
    list.insertAtFront(6);
    list.printList();

    // Insert node after a specific value
    list.insertAfterValue(2, 3);
    list.printList();

    // Insert node before a specific value
    list.insertBeforeValue(3, 9);
    list.printList();

    // Delete a node by value
    list.deleteValue(9);
    list.printList();

    // Delete the head node
    list.deleteHead();
    list.printList();

    // Delete the tail node
    list.deleteTail();
    list.printList();

    return 0;
}
