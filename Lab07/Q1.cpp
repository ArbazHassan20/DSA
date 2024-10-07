#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* head, Node* end) {
    if (!head || head == end) return head;

    Node* pivot = end;
    Node* p = head->next;
    Node* current = head;

    for ( p != end; p = p->next) {
        if (p->data < pivot->data) {
            current = (current == nullptr) ? head : current->next;
            swap(current, p);
        }
    }
    swap(current, pivot);
    return current;
}

void quickSort(Node* head, Node* end) {
    if (head != end) {
        Node* pivot = partition(head, end);

        // Recursively sort the left part
        if (head != pivot) {
            Node* temp = head;
            while (temp->next != pivot) {
                temp = temp->next;
            }
            quickSort(head, temp);
        }

        // Recursively sort the right part
        quickSort(pivot->next, end);
    }
}

Node* getTail(Node* head) {
    while (head && head->next) {
        head = head->next;
    }
    return head;
}

void quickSort(Node** head) {
    Node* tail = getTail(*head);
    quickSort(*head, tail);
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(7);
    head->next->next = new Node(8);
    head->next->next->next = new Node(9);
    head->next->next->next->next = new Node(1);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    quickSort(&head);

    cout << "Sorted list: ";
    printList(head);

    // memory free
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
