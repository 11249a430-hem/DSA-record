Aim:
To write a C program that reverses a string using stack operations (push and pop) implemented with an array.

Algorithm:

1. Start the program.
2. Read the size of the character stack (MAX).
3. Allocate memory for the stack using realloc.
4. Define push(item):
If stack is full, display “Overflow”.
Else increment Top and insert character.
5. Define pop():
If stack is empty, display “Underflow”.
Else return the character at Top and decrement Top.
6. In StringReversal():
Read a string from the user.
Push every character of the string onto the stack.
Pop all characters and print them to get the reversed string.
7. End the program.

Program:

#include<stdio.h>
#include<stdlib.h>

int Top = -1, MAX;    // Global stack top & maximum size
char *STACK;          // Dynamic stack array

// Function to PUSH a character onto the stack
void push(char item)
{
    // Check overflow condition
    if (Top == MAX - 1)
    {
        printf("Stack is Overflow");
    }
    else
    {
        Top = Top + 1;       // Move top forward
        STACK[Top] = item;   // Insert character
    }
}

// Function to POP a character from the stack
char pop()
{
    char item;

    // Underflow condition
    if (Top == -1)
    {
        printf("Stack is Underflow / Empty \n");
        return '\0';
    }
    else
    {
        item = STACK[Top];   // Take character from top
        Top = Top - 1;       // Move top backward
        return item;         // Return removed character
    }
}

// Function to reverse a string using stack
void StringReversal()
{
    char string[MAX];    // Array to store input string

    printf("Please Enter the string of size %d to reverse : ", MAX);
    scanf("%s", string); // Read string from user

    // PUSH each character of string into stack
    for (int c = 0; string[c] != '\0'; c++)
    {
        push(string[c]);
    }

    printf("Reversed String : ");

    // POP characters to reverse the string
    while (Top != -1)
    {
        printf("%c", pop());
    }
}

int main()
{
    // Get maximum size of stack (string length allowed)
    printf("Enter the size of CHAR STACK : ");
    scanf("%d", &MAX);

    // Allocate memory for stack
    STACK = realloc(STACK, MAX);

    // Reverse string using stack
    StringReversal();

    return 0;
}

Output:
Enter the size of CHAR STACK : 5
Please Enter the string of size 5 to reverse : HELLO
Reversed String : OLLEH


Result:
The program successfully reverses a string using stack operations, demonstrating the LIFO (Last In, First Out) property of stacks.Aim:
To write a C program that reverses a string using stack operations (push and pop) implemented with an array.

Algorithm:

1. Start the program.
2. Read the size of the character stack (MAX).
3. Allocate memory for the stack using realloc.
4. Define push(item):
If stack is full, display “Overflow”.
Else increment Top and insert character.
5. Define pop():
If stack is empty, display “Underflow”.
Else return the character at Top and decrement Top.
6. In StringReversal():
Read a string from the user.
Push every character of the string onto the stack.
Pop all characters and print them to get the reversed string.
7. End the program.

Program:

#include<stdio.h>
#include<stdlib.h>

int Top = -1, MAX;
char *STACK;

void push(char item)
{
if(Top == MAX - 1)
{
printf("Stack is Overflow");
}
else
{
Top = Top + 1;
STACK[Top] = item;
}
}

char pop()
{
char item;
if (Top == -1)
{
printf("Stack is Underflow / Empty \n");
return '\0';
}
else
{
item=STACK[Top];
Top = Top - 1;
return item;
}
}

void StringReversal()
{
char string[MAX];
printf("Please Enter the string of size %d to reverse : ", MAX);
scanf("%s", string);

for(int c=0; c<MAX; c++)
{
push(string[c]);
}

printf("Reversed String : ");

for(int c=0; c<MAX; c++)
{
printf("%c", pop());
}
}

int main()
{
printf("Enter the size of CHAR STACK : ");
scanf("%d", &MAX);
STACK = realloc(STACK, MAX);
StringReversal();
return 0;
}

Output:
Enter the size of CHAR STACK : 5
Please Enter the string of size 5 to reverse : HELLO
Reversed String : OLLEH


Result:
The program successfully reverses a string using stack operations, demonstrating the LIFO (Last In, First Out) property of stacks.Aim:
To write a C program that reverses a string using stack operations (push and pop) implemented with an array.

Algorithm:

1. Start the program.
2. Read the size of the character stack (MAX).
3. Allocate memory for the stack using realloc.
4. Define push(item):
If stack is full, display “Overflow”.
Else increment Top and insert character.
5. Define pop():
If stack is empty, display “Underflow”.
Else return the character at Top and decrement Top.
6. In StringReversal():
Read a string from the user.
Push every character of the string onto the stack.
Pop all characters and print them to get the reversed string.
7. End the program.

Program:

#include<stdio.h>
#include<stdlib.h>

int Top = -1, MAX;
char *STACK;

void push(char item)
{
if(Top == MAX - 1)
{
printf("Stack is Overflow");
}
else
{
Top = Top + 1;
STACK[Top] = item;
}
}

char pop()
{
char item;
if (Top == -1)
{
printf("Stack is Underflow / Empty \n");
return '\0';
}
else
{
item=STACK[Top];
Top = Top - 1;
return item;
}
}

void StringReversal()
{
char string[MAX];
printf("Please Enter the string of size %d to reverse : ", MAX);
scanf("%s", string);

for(int c=0; c<MAX; c++)
{
push(string[c]);
}

printf("Reversed String : ");

for(int c=0; c<MAX; c++)
{
printf("%c", pop());
}
}

int main()
{
printf("Enter the size of CHAR STACK : ");
scanf("%d", &MAX);
STACK = realloc(STACK, MAX);
StringReversal();
return 0;
}

Output:
Enter the size of CHAR STACK : 5
Please Enter the string of size 5 to reverse : HELLO
Reversed String : OLLEH


Result:
The program successfully reverses a string using stack operations, demonstrating the LIFO (Last In, First Out) property of stacks.Aim:
To write a C program that reverses a string using stack operations (push and pop) implemented with an array.

Algorithm:

1. Start the program.
2. Read the size of the character stack (MAX).
3. Allocate memory for the stack using realloc.
4. Define push(item):
If stack is full, display “Overflow”.
Else increment Top and insert character.
5. Define pop():
If stack is empty, display “Underflow”.
Else return the character at Top and decrement Top.
6. In StringReversal():
Read a string from the user.
Push every character of the string onto the stack.
Pop all characters and print them to get the reversed string.
7. End the program.

Program:

#include<stdio.h>
#include<stdlib.h>

int Top = -1, MAX;
char *STACK;

void push(char item)
{
if(Top == MAX - 1)
{
printf("Stack is Overflow");
}
else
{
Top = Top + 1;
STACK[Top] = item;
}
}

char pop()
{
char item;
if (Top == -1)
{
printf("Stack is Underflow / Empty \n");
return '\0';
}
else
{
item=STACK[Top];
Top = Top - 1;
return item;
}
}

void StringReversal()
{
char string[MAX];
printf("Please Enter the string of size %d to reverse : ", MAX);
scanf("%s", string);

for(int c=0; c<MAX; c++)
{
push(string[c]);
}

printf("Reversed String : ");

for(int c=0; c<MAX; c++)
{
printf("%c", pop());
}
}

int main()
{
printf("Enter the size of CHAR STACK : ");
scanf("%d", &MAX);
STACK = realloc(STACK, MAX);
StringReversal();
return 0;
}

Output:
Enter the size of CHAR STACK : 5
Please Enter the string of size 5 to reverse : HELLO
Reversed String : OLLEH


Result:
The program successfully reverses a string using stack operations, demonstrating the LIFO (Last In, First Out) property of stacks.
