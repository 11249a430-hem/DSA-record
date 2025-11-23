Aim:
To write a C program to perform various operations on a singly linked list such as insertion at beginning, insertion at end, insertion at a specific position, deletion of a node, and displaying the list.

Algorithm:

1. Start the program.
2. Create a structure Node
Contains data
Contains pointer next
3. Create functions:
CreateNode() → Allocates memory and creates a new node
InsertAtBeginning() → Inserts new node at the start
InsertAtEnd() → Inserts new node at the end
InsertAtPosition() → Inserts a node at a given position
DeleteNode() → Deletes a node by value
DisplayList() → Prints all nodes
4. In main():
Initialize head = NULL
Display menu
Based on user choice, call the respective linked list function
Continue until user selects Exit
5. End the program.

Program:

#include <stdio.h>
#include <stdlib.h>

// Structure to represent each node of the linked list
struct Node
{
    int data;              // To store integer data
    struct Node *next;     // Pointer to next node
};

// Function to create a new node with given data
struct Node *CreateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    newNode->data = data;   // Assign data
    newNode->next = NULL;   // Next is NULL (no link yet)

    return newNode;
}

// Function to insert node at the beginning (head) of the list
void InsertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    newNode->next = *head;   // Point new node to current head
    *head = newNode;         // Make new node the new head

    printf("Node with data %d inserted at beginning successfully.\n", data);
}

// Function to insert node at the end of the linked list
void InsertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = CreateNode(data);

    // If list is empty → new node becomes the head
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;

        // Traverse to the last node
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;   // Link last node to the new node
    }

    printf("Node with data %d inserted at the end successfully.\n", data);
}

// Insert a node at a specific position
// Position starts at 1 (head is position 1)
void InsertAtPosition(struct Node **head, int data, int position)
{
    if (position < 1)
    {
        printf("Invalid position!\n");
        return;
    }

    // Insert at position 1 → beginning
    if (position == 1)
    {
        InsertAtBeginning(head, data);
        return;
    }

    struct Node *prev = *head;

    // Move to the (position - 1)th node
    for (int k = 1; k < position - 1 && prev != NULL; k++)
    {
        prev = prev->next;
    }

    if (prev == NULL)
    {
        printf("Given position is out of range!\n");
        return;
    }

    struct Node *newNode = CreateNode(data);

    newNode->next = prev->next;   // Link new node to next node
    prev->next = newNode;         // Link prev node to new node

    printf("Node with data %d inserted at position %d successfully.\n", data, position);
}

// Delete the first node that matches the given value
void DeleteNode(struct Node **head, int valueToDelete)
{
    if (*head == NULL)
    {
        printf("Linked List is empty, deletion can't be performed!\n");
        return;
    }

    struct Node *temp = *head;

    // If head needs to be deleted
    if (temp->data == valueToDelete)
    {
        *head = temp->next;
        free(temp);
        printf("Data %d deleted from list.\n", valueToDelete);
        return;
    }

    struct Node *prev = *head;

    // Search for the node to delete
    while (prev->next != NULL)
    {
        if (prev->next->data == valueToDelete)
        {
            temp = prev->next;
            prev->next = temp->next;   // Bypass the node
            free(temp);                // Free memory
            printf("Data %d deleted from list.\n", valueToDelete);
            return;
        }
        prev = prev->next;
    }

    // If value not found
    printf("Element %d not found.\n", valueToDelete);
}

// Display the entire linked list
void DisplayList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    printf("\nLinked List Nodes: ");
    while (temp != NULL)
    {
        // Printing each node with its address and next address
        printf(" |At=%p|%d|Next=%p| -> ", temp, temp->data, temp->next);
        temp = temp->next;
    }
}

// Main menu-driven program
int main()
{
    struct Node *head = NULL;
    int choice, data, pos;

    while (1)
    {
        printf("\n--- Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete by Value\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtBeginning(&head, data);
            break;

        case 2:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            InsertAtEnd(&head, data);
            break;

        case 3:
            printf("Enter data and position to insert: ");
            scanf("%d %d", &data, &pos);
            InsertAtPosition(&head, data, pos);
            break;

        case 4:
            printf("Enter value to delete: ");
            scanf("%d", &data);
            DeleteNode(&head, data);
            break;

        case 5:
            DisplayList(head);
            break;

        case 6:
            printf("Exiting...\n");
            exit(0);

        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

Output:
--- Linked List Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete by Value
5. Display List
6. Exit
Enter your choice: 1
Enter data to insert: 10
Node with data 10 inserted at beginning successfully.

--- Linked List Menu ---
Enter your choice: 2
Enter data to insert: 20
Node with data 20 inserted at the end successfully.

--- Linked List Menu ---
Enter your choice: 3
Enter data and position to insert: 15 2
Node with data 15 inserted at position 2 successfully.

--- Linked List Menu ---
Enter your choice: 5
Linked List Nodes:  |At=0x1234|10|Next=0x2345| ->  |At=0x2345|15|Next=0x3456| ->  |At=0x3456|20|Next=0x0| ->

--- Linked List Menu ---
Enter your choice: 4
Enter value to delete: 15
Data 15 deleted from list.

--- Linked List Menu ---
Enter your choice: 5
Linked List Nodes:  |At=0x1234|10|Next=0x3456| ->  |At=0x3456|20|Next=0x0| ->

Result:
The program successfully performs all basic operations on a singly linked list, including insertion, deletion, and displaying the nodes.
