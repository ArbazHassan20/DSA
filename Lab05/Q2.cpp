#include <iostream>

using namespace std;

int factorialNonTail(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorialNonTail(n - 1);
    }
}
#the accumulator holds the temporary result 
int factorialTailHelper(int n, int accumulator) {
    if (n <= 1) {
        return accumulator;
    } else {
        return factorialTailHelper(n - 1, n * accumulator);
    }
}


int factorialTail(int n) {
    return factorialTailHelper(n, 1);
}

int main() {
    int number = 5;
    
    cout << "Factorial of " << number << " (non-tail recursive): " << factorialNonTail(number) << endl;
    cout << "Factorial of " << number << " (tail recursive): " << factorialTail(number) << endl;
    
    return 0;
}
