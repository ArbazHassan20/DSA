#include <iostream>
using namespace std;

class Node {
    string data;
    Node* next;

public:
    Node() {
        data = " ";
        next = nullptr;
    }
    Node(string name) {
        data = name;
        next = nullptr;
    }

    friend class Queue;
};

class Queue {
    Node* front; // points to the front of the queue
    Node* rear;  // points to the rear of the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    bool is_empty() {
        return front == nullptr;
    }

    void buy_ticket(string name) {
        Node* newnode = new Node(name);

        // if the queue is empty
        if (is_empty()) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }
        cout << name << " is in the line." << endl;
    }

    void move_to_next() {
        if (is_empty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        cout << temp->data << " is done with the process now!" << endl;  // Output current front before removing
        front = front->next;

        delete temp;
    }

    void display() {
        if (is_empty()) {
            cout << "The queue is empty!" << endl;
            return;
        }
        Node* current = front;
        cout << "|| ";
        while (current->next != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << current->data << " ||" << endl;
    }
};

int main() {
    Queue q;

    // adding 10 people to the queue
    q.buy_ticket("Arbaz");
    q.buy_ticket("Virda");
    q.buy_ticket("Ali");
    q.buy_ticket("Sara");
    q.buy_ticket("Omar");
    q.buy_ticket("Zainab");
    q.buy_ticket("Bilal");
    q.buy_ticket("Fatima");
    q.buy_ticket("Usman");
    q.buy_ticket("Hassan");
    cout << endl;

    q.display();

    cout << endl;

    // removing 5 people from the queue
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    cout << endl;

    q.display();

    cout << endl;

    // adding 5 more people to the queue
    q.buy_ticket("Amarha");
    q.buy_ticket("Leeya");
    q.buy_ticket("Rida");
    q.buy_ticket("Ehtisham");
    q.buy_ticket("Hassan");
    cout << endl;

    q.display();
}
