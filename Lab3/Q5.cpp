#include "iostream"
using namespace std;

class Node {
    int data;
    Node* next, *prev;
    
public:
    Node() : next(NULL), prev(NULL), data(0) {}
    Node(const int d) : data(d), next(NULL), prev(NULL) {}
    
    friend class DLL;
};

class DLL {
    Node* head;
    Node* tail;
    
public:
    DLL() : head(NULL), tail(NULL) {}

    // Insert a node at the end of the list
    void insertAtEnd(const int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Delete a node by value
    void deleteVal(const int val) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* curr = head;
        
        // Traverse to find the node with the value
        while (curr != NULL && curr->data != val) {
            curr = curr->next;
        }
        
        if (curr == NULL) {
            cout << "Value not found in the list" << endl;
            return;
        }

        // If the node to be deleted is the head
        if (curr == head) {
            head = head->next;
            if (head) head->prev = NULL;
        } 
        // If the node to be deleted is the tail
        else if (curr == tail) {
            tail = tail->prev;
            tail->next = NULL;
        } 
        // If the node is somewhere in the middle
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }

        delete curr;
    }

    // Function to sort the list
    void sortList() {
        if (head == NULL) return;
        
        Node* curr, *index;
        
        // Selection sort logic
        for (curr = head; curr->next != NULL; curr = curr->next) {
            for (index = curr->next; index != NULL; index = index->next) {
                if (curr->data > index->data) {
                    int temp = curr->data;
                    curr->data = index->data;
                    index->data = temp;
                }
            }
        }
    }

    // Function to remove duplicates from the sorted list
    void removeDuplicates() {
        if (head == NULL) return;

        Node* curr = head;

        // Remove duplicates by comparing current node with next node
        while (curr != NULL && curr->next != NULL) {
            if (curr->data == curr->next->data) {
                Node* duplicate = curr->next;
                curr->next = duplicate->next;
                if (duplicate->next != NULL) {
                    duplicate->next->prev = curr;
                } else {
                    tail = curr; // Update tail if the duplicate was the last node
                }
                delete duplicate;
            } else {
                curr = curr->next;
            }
        }
    }

    // Function to print the list
    void printList() const {
        Node* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    DLL list;

    // Insert some elements
    list.insertAtEnd(6);
    list.insertAtEnd(3);
    list.insertAtEnd(9);
    list.insertAtEnd(12);
    list.insertAtEnd(12);
    list.insertAtEnd(13);

    cout << "Original list:" << endl;
    list.printList();

    // Sort the list
    list.sortList();
    cout << "Sorted list:" << endl;
    list.printList();

    // Remove duplicates
    list.removeDuplicates();
    cout << "List after removing duplicates:" << endl;
    list.printList();

    return 0;
}
