#include <iostream>

using namespace std;

#define capacity 10 // Maximum capacity of the queue

// Ticket Queue class
class Ticket_Queue {
    int front; 
    int rear;  
    string *queue; 

public:
    
    Ticket_Queue() {
        front = 0;
        rear = -1;
        queue = new string[capacity];
    }

   
    bool is_full() {
        return rear == capacity - 1;
    }

    
    bool is_empty() {
        return front > rear || front == -1;
    }

    // Function to add a new passenger to the queue
    void buy_ticket(string name) {
        if (is_full()) {
            cout << "Queue is full at the moment!" << endl;
            return;
        }
        queue[++rear] = name;
        cout << name << " has been added to the queue!" << endl;
    }

   
    void move_to_next() {
        if (is_empty()) {
            cout << "The queue is now empty!" << endl;
            return;
        }
        cout << queue[front] << " has completed the process!" << endl;
        front++;
    }

  
    string peek() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return " ";
        }
        return queue[front];
    }

    
    void display() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Passengers in the queue: ";
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << ' ';
        }
        cout << endl;
    }
};

// Main function
int main() {
    Ticket_Queue q;

    // Adding 10 passengers to the queue
    q.buy_ticket("Ahmed");
    q.buy_ticket("Ayesha");
    q.buy_ticket("Sara");
    q.buy_ticket("Usman");
    q.buy_ticket("Ali");
    q.buy_ticket("Zara");
    q.buy_ticket("Omar");
    q.buy_ticket("Fatima");
    q.buy_ticket("Bilal");
    q.buy_ticket("Hiba");
    cout << endl;

    q.display(); // Display the current queue

    cout << endl;

    // Simulating the processing of 5 passengers
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    cout << endl;

    q.display(); // Display the remaining passengers in the queue

    cout << endl;

    // Trying to add 5 more passengers to the queue
    // These passengers won't be enqueued because the rear pointer has reached the capacity
    q.buy_ticket("Zain");
    q.buy_ticket("Mariam");
    q.buy_ticket("Hassan");
    q.buy_ticket("Kiran");
    q.buy_ticket("Tariq");
    cout << endl;

    q.display(); // Final display of the queue
}
