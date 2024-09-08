#include "iostream"
using namespace std;

class Node {
    int data;
    Node* next;

public:
    Node() : data(0), next(NULL) {}
    Node(const int d) : data(d), next(NULL) {}

    friend class SLL; // Granting access to SLL class
};

class SLL {
    Node* head;

public:
    SLL() : head(NULL) {}
    SLL(Node* n) : head(n) {}

    // Insertion at the front of the list
    void insertAtFront(const int val) {
        Node* newNode = new Node(val);
        if (head == NULL)
            head = newNode;
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    // Insertion at the tail of the list
    void insertAtTail(const int val) {
        Node* newNode = new Node(val);
        if (head == NULL) 
            head = newNode;
        else {
            Node* current = head;
            while (current->next != NULL) 
                current = current->next;
            current->next = newNode;
        }
    }

    // Insert a node after a given value
    void InsertAfterValue(const int value, const int insertingValue) {
        Node* newNode = new Node(insertingValue);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->data != value) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = newNode;
            newNode->next = temp;
        }
    }

    // Insert a node before a given value
    void InsertBeforeValue(const int value, const int insertingValue) {
        Node* newNode = new Node(insertingValue);
        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next->data != value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Count the number of nodes
    int numNodes() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Delete the head node
    void deleteFromHead() {
        if (head != NULL) {
            Node* temp = head;
            head = temp->next;
            delete temp;
        } else {
            cout << "Linked list is empty" << endl;
        }
    }

    // Delete the tail node
    void deleteFromTail() {
        if (head != NULL) {
            Node* current = head;
            while (current->next->next != NULL) {
                current = current->next;
            }
            delete current->next;
            current->next = NULL;
        } else {
            cout << "Linked list is empty" << endl;
        }
    }

    // Delete a node by value
    void deleteValue(const int value) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        Node* current = head;
        while (current->next->data != value) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = current->next->next;
        delete temp;
    }

    // Print the list
    void printList() {
        Node* current = head;
        while (current != NULL) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SLL list;

    // Inserting elements at the front
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtFront(30);
    cout << "After inserting at front:" << endl;
    list.printList();

    // Inserting elements at the tail
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtTail(60);
    cout << "\nAfter inserting at tail:" << endl;
    list.printList();

    cout << "\nTotal nodes in the list: " << list.numNodes() << endl;

    // Deleting from head
    list.deleteFromHead();
    cout << "\nAfter deleting from head:" << endl;
    list.printList();

    // Deleting from tail
    list.deleteFromTail();
    cout << "\nAfter deleting from tail:" << endl;
    list.printList();

    // Deleting a node by value
    list.deleteValue(40);
    cout << "\nAfter deleting value 40:" << endl;
    list.printList();

    // Inserting after value 20
    list.InsertAfterValue(20, 11);
    cout << "\nInserted value 11 after 20:" << endl;
    list.printList();

    // Inserting before value 50
    list.InsertBeforeValue(50, 22);
    cout << "\nInserted value 22 before 50:" << endl;
    list.printList();

    return 0;
}
