#include <iostream>
#include <cctype> // for isalnum
using namespace std;

class Stack
{
    int topIndex;   
    int maxSize;    
    char *stackArr; 
public:
  
    Stack()
    {
        topIndex = -1;
        maxSize = 10;
        stackArr = new char[maxSize];
    }

    Stack(int n)
    {
        topIndex = -1;
        maxSize = n;
        stackArr = new char[maxSize];
    }

    // Check if the stack is full
    bool is_full()
    {
        return topIndex == maxSize - 1;
    }

    bool is_empty()
    {
        return topIndex == -1;
    }

    void push(char value)
    {
        if (is_full())
        {
            cout << "Stack overflow. Cannot push " << value << endl;
            return;
        }
        stackArr[++topIndex] = value;
    }

    // Pop an element from the stack
    char pop()
    {
        if (is_empty())
        {
            cout << "Stack underflow. Cannot pop" << endl;
            return ' ';
        }
        return stackArr[topIndex--];
    }

    // Peek at the top element without popping it
    char peek()
    {
        if (is_empty())
        {
            cout << "Stack is empty. Cannot peek" << endl;
            return ' ';
        }
        return stackArr[topIndex];
    }

    
    ~Stack()
    {
        delete[] stackArr;
    }
};

// Function to check if a character is an operator
bool is_operator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}
// Function to get the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}


string infix_to_prefix(string infixExpr)
{
    // Temporary stack to reverse the infix string
    Stack tempStack(infixExpr.length());
    for (char &ch : infixExpr)
    {
        tempStack.push(ch);
    }

    string reversedInfix = "";

 
    while (!tempStack.is_empty())
    {
        char ch = tempStack.pop();
       
        if (ch == '(')
        {
            ch = ')';
        }
        else if (ch == ')')
        {
            ch = '(';
        }
        reversedInfix += ch;
    }

    Stack opStack(reversedInfix.length());
    string prefixTemp = "";

    for (char &ch : reversedInfix)
    {
        if (ch == ' ')
        {
            continue;
        }
       
        if (isalnum(ch))
        {
            prefixTemp += ch;
        }
        // Push opening parentheses onto the stack
        else if (ch == '(')
        {
            opStack.push(ch);
        }
      
        else if (ch == ')')
        {
            while (!opStack.is_empty() && opStack.peek() != '(')
            {
                prefixTemp += opStack.pop();
            }
            opStack.pop(); // Remove '(' from the stack
        }
        else if (is_operator(ch))
        {
          
            while (!opStack.is_empty() && precedence(opStack.peek()) >= precedence(ch))
            {
                prefixTemp += opStack.pop();
            }
            opStack.push(ch);
        }
    }

   
    while (!opStack.is_empty())
    {
        prefixTemp += opStack.pop();
    }

    // Reverse the result to obtain the final prefix expression
    string finalPrefix = "";
    for (char &ch : prefixTemp)
    {
        tempStack.push(ch);
    }
    while (!tempStack.is_empty())
    {
        finalPrefix += tempStack.pop();
    }
    return finalPrefix;
}

int main()
{
    // Updated infix expression
    string infixExpression = "K+L-M*N+(O^P)*W/U/V*T+Q";

    cout << "Original Infix Expression: " << infixExpression << endl;

   
    string prefixExpression = infix_to_prefix(infixExpression);
    cout << "Converted Prefix Expression: " << prefixExpression << endl;

    return 0;
}
