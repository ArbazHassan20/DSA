#include <iostream>

using namespace std;

class Stack
{
    int topIndex;     // Points to the top element of the stack
    int capacity;     // Maximum capacity of the stack
    int *stackArray;  // Dynamic array to hold stack elements

public:
    Stack(int size)
    {
        topIndex = -1;
        capacity = size;
        stackArray = new int[capacity];
    }

    bool is_full()
    {
        return topIndex == capacity - 1;
    }
    bool is_empty()
    {
        return topIndex == -1;
    }

    void push(int data)
    {
        if (is_full())
        {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stackArray[++topIndex] = data;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack Underflow!" << endl;
            return -1;
        }
        return stackArray[topIndex--];
    }

    void display()
    {
        for (int i = topIndex; i >= 0; i--)
        {
            cout << stackArray[i] << " ";
        }
        cout << endl;
    }

    ~Stack()
    {
        delete[] stackArray;
    }
};

class Queue
{
    Stack *mainStack;    // Main stack to hold the elements
    Stack *tempStack;    // Temporary stack to aid in dequeue operations

public:
    Queue(int size)
    {
        mainStack = new Stack(size);
        tempStack = new Stack(size);
    }

    ~Queue()
    {
        delete mainStack;
        delete tempStack;
    }

    void enqueue(int value)
    {
        mainStack->push(value);
        cout << value << " added to the queue!" << endl;
    }

    void dequeue()
    {
        if (mainStack->is_empty())
        {
            cout << "Queue is empty, nothing to dequeue!" << endl;
            return;
        }

     
        while (!mainStack->is_empty())
        {
            tempStack->push(mainStack->pop());
        }

       
        int dequeuedValue = tempStack->pop();
        cout << dequeuedValue << " removed from the queue!" << endl;

        // Transfer the elements back to mainStack
        while (!tempStack->is_empty())
        {
            mainStack->push(tempStack->pop());
        }
    }

   
    void display()
    {
        if (mainStack->is_empty())
        {
            cout << "Queue is empty!" << endl;
            return;
        }

     
        while (!mainStack->is_empty())
        {
            tempStack->push(mainStack->pop());
        }

        cout << "Queue contains: ";
        tempStack->display();

       
        while (!tempStack->is_empty())
        {
            mainStack->push(tempStack->pop());
        }
    }
};

int main()
{
    Queue q(5);

  
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.display();  

    q.dequeue();
    q.dequeue();

    q.display();
}
