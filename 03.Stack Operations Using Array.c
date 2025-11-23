Aim:
To write a C program to implement stack operations such as push, pop, and display using an array.

Algorithm:

1. Start the program.
2. Read the stack size (MAX).
Initialize Top = -1.
3. Define stack operations:
Push():
If Top == MAX-1, display "Overflow".
Else increase Top and insert item.
Pop():
If Top == -1, display "Underflow".
Else remove and decrease Top.
Display():
Print all elements from index 0 to Top.
4. In main():
Create stack array.
Display menu:
1 → Push
2 → Pop
3 → Exit
Perform the chosen operation using switch–case.
5. Repeat until user selects Exit.
6. End the program.

Program:#include<stdio.h>

int Top = -1;   // Global variable to track top index of stack
int MAX;        // Maximum size of the stack (entered by user)

// Function to display current stack elements
void display(int stack[])
{
    printf("Current stack elements are-\n");
    
    // Print all elements from bottom to top
    for(int i = 0; i <= Top; i++)
    {
        printf(">>%d", stack[i]);
    }
    printf("(Top)");
}

// Function to push an element into stack
void push(int stack[])
{
    int item;

    // Check overflow condition
    if(Top == MAX - 1)
    {
        printf("Stack is Overflow");
    }
    else
    {
        printf("Enter the element to push : ");
        scanf("%d", &item);

        Top = Top + 1;       // Increment Top
        stack[Top] = item;   // Insert item at new top
    }
}

// Function to remove (pop) top element
void pop(int stack[])
{
    int item;

    // Check underflow condition
    if(Top == -1)
    {
        printf("Stack is Underflow");
    }
    else
    {
        item = stack[Top];   // Store the top element
        Top = Top - 1;       // Decrease Top to remove element
        printf("Popped element: %d\n", item);
    }
}

int main()
{
    int operation = 0;

    // Input stack size from user
    printf("Enter the size of stack : ");
    scanf("%d", &MAX);

    int stack[MAX];  // Declare stack with given size

    // Menu-driven program
    while(operation != 3)
    {
        printf("\n 1.Push \n 2.Pop \n 3.Exit \n");
        printf("\nPlease choose stack operation to perform : ");
        scanf("%d", &operation);

        switch(operation)
        {
            case 1:
                push(stack);     // Perform push operation
                display(stack);  // Show stack
                break;

            case 2:
                pop(stack);      // Perform pop operation
                display(stack);  // Show stack
                break;

            case 3:
                return 0;        // Exit program

            default:
                printf("Incorrect operation");
                break;
        }
    }

    return 0;
}



Output:
Enter the size of stack : 5

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 1
Enter the elements to push : 10
Current stack elements are-
>>10(Top)

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 1
Enter the elements to push : 20
Current stack elements are-
>>10>>20(Top)

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 2
Current stack elements are-
>>10(Top)

1.Push
2.Pop
3.Exit
Please choose stack operation to perform : 2
Stack is Underflow
Current stack elements are-
>>10(Top)

Result:
This program successfully demonstrates stack operations using an array, allowing the user to push, pop, and display stack elements.
