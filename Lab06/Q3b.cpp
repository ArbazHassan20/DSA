#include <iostream>

using namespace std;

class Queue {
    int front;      
    int rear;       
    int count;      
    int capacity;   
    string* queue;  

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
        capacity = 10;
        queue = new string[capacity];
    }

    ~Queue() {
        delete[] queue; 
    }

    
    bool is_full() {
        return count == capacity;
    }

  
    bool is_empty() {
        return count == 0;
    }

    
    void buy_ticket(string name) {
        if (is_full()) {
            cout << "Queue is full!" << endl;
            return;
        }
      
        rear = (rear + 1) % capacity;
        queue[rear] = name;
        count++;
        cout << name << " Enqueued!" << endl;
    }

   
    void move_to_next() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << queue[front] << " is done with the process now!" << endl;
        // Circular increment for the front pointer
        front = (front + 1) % capacity;
        count--;
    }

   
    void display_queue() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = 0; i < count; i++) {
            cout << queue[(front + i) % capacity] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q;

    // Initial queue display (empty)
    q.display_queue();

    // Adding 10 people to the queue
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

    q.display_queue(); // Display the queue after adding 10 people

    cout << endl;

    // Removing 5 people from the queue
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    q.move_to_next();
    cout << endl;

    q.display_queue(); // Display the queue after removing 5 people

    cout << endl;

    // Adding 5 more people to the queue
    q.buy_ticket("Rida");
    q.buy_ticket("Amir");
    q.buy_ticket("Ehsan");
    q.buy_ticket("Kiran");
    q.buy_ticket("Murtaza");
    cout << endl;

    q.display_queue(); // Final queue display after adding new people
}
