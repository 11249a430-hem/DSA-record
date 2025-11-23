Aim:
To convert a given infix expression to its equivalent postfix expression using a stack.

Algorithm:
  
1.Create an empty stack for operators.
2.Read the infix expression from left to right (character by character).
3.If the character is an operand (letter or digit), append it to the postfix output.
4.If the character is '(', push it onto the stack.
5.If the character is ')', pop from the stack and append to postfix until '(' is popped.
6.If the character is an operator (+ - * / ^), then:
   While the stack is not empty and top of stack has operator of higher or equal precedence (for ^ you may treat as right-associative if needed), pop it and append to postfix.
   Push the current operator onto the stack.
   After the entire infix is processed, pop any remaining operators from the stack and append to postfix.
7.Terminate postfix string and display it.

Program:

#include <stdio.h>
#include <ctype.h>      // for isalnum() – checks if character is letter or digit
#include <string.h>     // for strlen()

#define MAX 100

char stack[MAX];
int top = -1;

// Check if stack is empty
int isEmpty() {
    return top == -1;
}

// Push an element onto stack
void push(char item) {
    if (top >= MAX - 1) {
        printf("stack overflow\n");
        return;
    }
    stack[++top] = item;   // increment top and insert item
}

// Pop top element from stack
char pop() {
    if (isEmpty()) {
        printf("stack underflow\n");
        return '\0';
    }
    return stack[top--];   // return top element and decrease top
}

// Look at top element without removing
char peek() {
    if (isEmpty()) return '\0';
    return stack[top];
}

// Function to decide operator precedence
int precedence(char item) {
    if (item == '^') return 3;                     // highest precedence
    else if (item == '*' || item == '/') return 2; // next level
    else if (item == '+' || item == '-') return 1; // lowest among operators
    else return 0;
}

int main() {
    char infix[MAX], postfix[MAX];
    int i, k = 0;
    char ch, temp;

    // Input infix expression
    printf("Enter Infix expression: ");
    scanf("%s", infix);

    // Scan the infix expression from left to right
    for (i = 0; i < (int)strlen(infix); i++) {
        ch = infix[i];

        if (isalnum(ch)) {         
            /* If character is operand (A, B, 1, 2, etc.) */
            postfix[k++] = ch;
        } 
        else if (ch == '(') {     
            /* Opening parenthesis is pushed directly */
            push(ch);
        } 
        else if (ch == ')') {     
            /* Pop until '(' is found */
            while (!isEmpty() && (temp = pop()) != '(') {
                postfix[k++] = temp;
            }
        } 
        else {                    
            /* Operator (+, -, *, /, ^) */
            /* Pop operators with equal or higher precedence */
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[k++] = pop();
            }
            push(ch);   // push current operator
        }
    }

    // Pop any remaining operators in the stack
    while (!isEmpty()) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';    // End postfix string

    // Output result
    printf("Postfix expression: %s\n", postfix);

    return 0;
}

Output:
Enter Infix expression: (A+B)^D+E/(F+A*D)+C
postfix expression: AB+D^E F A D * + / + C +

Result:
The given infix expression is successfully converted into its equivalent postfix expression using stack operations.
The program correctly applies the rules of operator precedence and parentheses handling, and displays the postfix form of the entered infix expression.
