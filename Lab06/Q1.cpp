#include <iostream>
#include <stack>

using namespace std;

void separateEvenOdd(stack<int>& original, stack<int>& evenStack, stack<int>& oddStack) {
    while (!original.empty()) {
        int value = original.top();
        original.pop();
        if (value % 2 == 0) {
            evenStack.push(value); 
        } else {
            oddStack.push(value);   
        }
    }
}

int main() {
    stack<int> originalStack, evenStack, oddStack;

   
    originalStack.push(1);
    originalStack.push(2);
    originalStack.push(3);
    originalStack.push(4);
    originalStack.push(5);
    originalStack.push(6);

    
    separateEvenOdd(originalStack, evenStack, oddStack);

   
    cout << "Even values in stack: ";
    while (!evenStack.empty()) {
        cout << evenStack.top() << " ";
        evenStack.pop();
    }
    cout << endl;

  
    cout << "Odd values in stack: ";
    while (!oddStack.empty()) {
        cout << oddStack.top() << " ";
        oddStack.pop();
    }
    cout << endl;

    return 0;
}
