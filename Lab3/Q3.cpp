#include "iostream"
using namespace std;

class ListNode {
    int value;          // stores data
    ListNode* nextNode; // pointer to the next node

public:
    ListNode() : value(0), nextNode(NULL) {}                    // Default constructor
    ListNode(const int data) : value(data), nextNode(NULL) {}    // Parameterized constructor

    friend class LinkedList;  // Granting LinkedList class access to private members
};

class LinkedList {
    ListNode* headNode; // Pointer to the head node of the list

public:
    LinkedList() : headNode(NULL) {}             // Default constructor
    LinkedList(ListNode* n) : headNode(n) {}     // Constructor with ListNode initialization

    // Insert a node at the end of the list
    void appendToTail(const int data) {
        ListNode* newNode = new ListNode(data); // Creating a new node
        if (headNode == NULL) {
            headNode = newNode;  // If the list is empty, the new node becomes the head
        } else {
            ListNode* currentNode = headNode;
            while (currentNode->nextNode != NULL) {
                currentNode = currentNode->nextNode;  // Traverse to the last node
            }
            currentNode->nextNode = newNode;  // Append the new node at the end
        }
    }

    // Segregate even and odd values: place even values first, then odd values
    LinkedList segregateEvenOdd() {
        LinkedList segregatedList;          // New list for the segregated result
        ListNode* currentNode = headNode;

        // First pass: add even values to the new list
        while (currentNode != NULL) {
            if (currentNode->value % 2 == 0) {
                segregatedList.appendToTail(currentNode->value);
            }
            currentNode = currentNode->nextNode;
        }

        currentNode = headNode;

        // Second pass: add odd values to the new list
        while (currentNode != NULL) {
            if (currentNode->value % 2 != 0) {
                segregatedList.appendToTail(currentNode->value);
            }
            currentNode = currentNode->nextNode;
        }

        return segregatedList;  // Return the new segregated list
    }

    // Print the list's values
    void displayList() {
        ListNode* currentNode = headNode;
        while (currentNode != NULL) {
            cout << currentNode->value << " ";  // Print each node's value
            currentNode = currentNode->nextNode;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    // Append nodes to the list
    myList.appendToTail(11);
    myList.appendToTail(22);
    myList.appendToTail(33);
    myList.appendToTail(44);
    myList.appendToTail(55);
    myList.appendToTail(66);

    // Display the original list
    cout << "Original List:" << endl;
    myList.displayList();

    // Segregate the list into even and odd numbers and assign the result to myList
    myList = myList.segregateEvenOdd();

    // Display the segregated list
    cout << "Segregated List (Even numbers first, followed by odd numbers):" << endl;
    myList.displayList();

    return 0;
}
