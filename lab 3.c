#include "iostream"
using namespace std;

class node {
    int data;
    node* next;
public:
    node() : data(0), next(NULL) {}
    node(const int d) : data(d), next(NULL) {}
    friend class SLL;
};

class SLL {
    node* head;
public:
    SLL() : head(NULL) {}
    SLL(node* n) : head(n) {}

    void insertAtFront(const int val) {
        node* n = new node(val);
        if (head == NULL) head = n;
        else {
            n->next = head;
            head = n;
        }
    }

    void insertAtTail(const int val) {
        node* n = new node(val);
        if (head == NULL) head = n;
        else {
            node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = n;
        }
    }

    void InsertAfterValue(const int value, const int insertingValue) {
        node* n = new node(insertingValue);
        if (head == NULL) {
            cout << "Error: List is empty, cannot insert after value.\n";
            return;
        }
        node* currentPtr = head;
        while (currentPtr != NULL && currentPtr->data != value) {
            currentPtr = currentPtr->next;
        }
        if (currentPtr == NULL) {
            cout << "Error: Value " << value << " not found in the list.\n";
            return;
        }
        node* temp = currentPtr->next;
        currentPtr->next = n;
        n->next = temp;
    }

    void InsertBeforeValue(const int value, const int insertingValue) {
        node* n = new node(insertingValue);
        if (head == NULL) {
            cout << "Error: List is empty, cannot insert before value.\n";
            return;
        }
        if (head->data == value) {
            insertAtFront(insertingValue);
            return;
        }
        node* currentPtr = head;
        while (currentPtr->next != NULL && currentPtr->next->data != value) {
            currentPtr = currentPtr->next;
        }
        if (currentPtr->next == NULL) {
            cout << "Error: Value " << value << " not found in the list.\n";
            return;
        }
        n->next = currentPtr->next;
        currentPtr->next = n;
    }

    int numNodes() {
        int nodes = 0;
        node* currentPtr = head;
        while (currentPtr != NULL) {
            nodes++;
            currentPtr = currentPtr->next;
        }
        return nodes;
    }

    void deleteFromHead() {
        if (head != NULL) {
            node* currPtr = head;
            head = currPtr->next;
            delete currPtr;
            cout << "Deleted node from head.\n";
        } else {
            cout << "Error: List is empty.\n";
        }
    }

    void deleteFromTail() {
        if (head != NULL) {
            if (head->next == NULL) {
                delete head;
                head = NULL;
            } else {
                node* currPtr = head;
                while (currPtr->next->next != NULL) {
                    currPtr = currPtr->next;
                }
                delete currPtr->next;
                currPtr->next = NULL;
            }
            cout << "Deleted node from tail.\n";
        } else {
            cout << "Error: List is empty.\n";
        }
    }

    void deleteValue(const int value) {
        if (head == NULL) {
            cout << "Error: List is empty.\n";
            return;
        }
        if (head->data == value) {
            deleteFromHead();
            return;
        }
        node* n = head;
        while (n->next != NULL && n->next->data != value) {
            n = n->next;
        }
        if (n->next == NULL) {
            cout << "Error: Value " << value << " not found in the list.\n";
            return;
        }
        node* temp = n->next;
        n->next = n->next->next;
        delete temp;
        cout << "Deleted node with value " << value << ".\n";
    }

    void printList() {
        if (head == NULL) {
            cout << "The list is empty.\n";
            return;
        }
        node* currentPtr = head;
        cout << "Linked List: ";
        while (currentPtr != NULL) {
            cout << currentPtr->data << " ";
            currentPtr = currentPtr->next;
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
    cout << "After inserting at tail:" << endl;
    list.printList();

    cout << "Total nodes in list: " << list.numNodes() << endl;

    // Deleting elements
    list.deleteFromHead();
    cout << "After deleting from head:" << endl;
    list.printList();

    list.deleteFromTail();
    cout << "After deleting from tail:" << endl;
    list.printList();

    list.deleteValue(40);
    cout << "After deleting value 40:" << endl;
    list.printList();

    // Inserting after and before specific values
    list.InsertAfterValue(20, 11);
    cout << "Inserted value 11 after 20:" << endl;
    list.printList();

    list.InsertBeforeValue(50, 22);
    cout << "Inserted value 22 before 50:" << endl;
    list.printList();

    return 0;
}

