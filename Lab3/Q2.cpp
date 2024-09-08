#include "iostream"
using namespace std;

class Node {
    int value;
    Node* nextNode;

public:
    Node() : value(0), nextNode(NULL) {}
    Node(const int val) : value(val), nextNode(NULL) {}

    friend class SinglyLinkedList;
};

class SinglyLinkedList {
    Node* headNode;

public:
    SinglyLinkedList() : headNode(NULL) {}
    SinglyLinkedList(Node* n) : headNode(n) {}

    void appendAtEnd(const int newValue) {
        Node* newNode = new Node(newValue);
        if (headNode == NULL)
            headNode = newNode;
        else {
            Node* current = headNode;
            while (current->nextNode != NULL)
                current = current->nextNode;
            current->nextNode = newNode;
        }
    }

    Node* reverseList() {
        Node* current = headNode;
        Node* previous = NULL;
        Node* next = NULL;

        while (current != NULL) {
            next = current->nextNode;
            current->nextNode = previous;
            previous = current;
            current = next;
        }

        return previous; // returning the new head after reversing
    }

    void display() {
        Node* current = headNode;
        while (current != NULL) {
            cout << current->value << " ";
            current = current->nextNode;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList linkedList;

    linkedList.appendAtEnd(10);
    linkedList.appendAtEnd(20);
    linkedList.appendAtEnd(30);
    linkedList.appendAtEnd(40);

    cout << "Original List: ";
    linkedList.display();

    linkedList.headNode = linkedList.reverseList(); // updated the head with the reversed list

    cout << "Reversed List: ";
    linkedList.display();

    return 0;
}
