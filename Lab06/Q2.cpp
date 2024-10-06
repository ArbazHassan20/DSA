#include <iostream>
#include <cctype>  // For isalnum()

using namespace std;

class Stack {
  int topIndex;
  int maxSize;
  char *elements;

 public:
  // Default constructor to initialize stack with a size of 10
  Stack() {
    topIndex = -1;
    maxSize = 10;
    elements = new char[maxSize];
  }

  // Constructor to initialize stack with a custom size
  Stack(int n) {
    topIndex = -1;
    maxSize = n;
    elements = new char[maxSize];
  }

  // Check if the stack is full
  bool is_full() { return topIndex == maxSize - 1; }

  // Check if the stack is empty
  bool is_empty() { return topIndex == -1; }

  // Function to push an element onto the stack
  void push(char value) {
    if (is_full()) {
      cout << "Stack overflow. Cannot push '" << value << "'" << endl;
      return;
    }
    elements[++topIndex] = value;
  }

  // Function to pop an element from the stack
  void pop() {
    if (is_empty()) {
      cout << "Stack underflow. Nothing to pop." << endl;
      return;
    }
    cout << "Popped: " << elements[topIndex--] << endl;
  }

  // Function to peek at the top element without popping
  char peek() {
    if (is_empty()) {
      cout << "Stack is empty. Cannot peek." << endl;
      return ' ';
    }
    return elements[topIndex];
  }

  // Destructor to free the dynamically allocated memory
  ~Stack() { delete[] elements; }
};

// Function to check if the given character is an operator
bool is_operator(char symbol) {
  return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^';
}

// Function to return the precedence of operators
int get_precedence(char op) {
  if (op == '+' || op == '-') return 1;
  if (op == '*' || op == '/') return 2;
  if (op == '^') return 3;
  return 0;
}

// Function to convert an infix expression to postfix
string convert_infix_to_postfix(string infixExpression) {
  int exprLength = infixExpression.length();
  Stack operatorStack(exprLength);  // Stack to store operators
  string postfixExpression = "";

  // Loop through each character in the infix expression
  for (char &symbol : infixExpression) {
    if (symbol == ' ') {
      continue;  // Skip spaces
    }

    // Append operand (letters/numbers) to postfix string
    if (isalnum(symbol)) {
      postfixExpression += symbol;
    }
    // Push opening parenthesis onto the stack
    else if (symbol == '(') {
      operatorStack.push(symbol);
    }
    // When encountering a closing parenthesis, pop until matching '(' is found
    else if (symbol == ')') {
      while (!operatorStack.is_empty() && operatorStack.peek() != '(') {
        postfixExpression += operatorStack.peek();
        operatorStack.pop();
      }
      operatorStack.pop();  // Remove '(' from the stack
    }
    // If the character is an operator
    else if (is_operator(symbol)) {
      // Pop operators with higher or equal precedence from the stack
      while (!operatorStack.is_empty() && get_precedence(operatorStack.peek()) >= get_precedence(symbol)) {
        postfixExpression += operatorStack.peek();
        operatorStack.pop();
      }
      operatorStack.push(symbol);  // Push current operator to stack
    }
  }

  // Pop any remaining operators from the stack
  while (!operatorStack.is_empty()) {
    postfixExpression += operatorStack.peek();
    operatorStack.pop();
  }

  return postfixExpression;
}

int main() {
  string infixInput;

  cout << "Enter an infix expression: ";
  cin >> infixInput;

  cout << "Infix Expression: " << infixInput << endl;

  // Convert infix to postfix and display the result
  string postfixResult = convert_infix_to_postfix(infixInput);
  cout << "Postfix Expression: " << postfixResult << endl;

  return 0;
}
