Aim:
To write a C program to perform various operations on a Doubly Linked List, such as inserting nodes at the beginning and end, deleting nodes from the beginning and end, and displaying the list using a menu-driven (switch case) approach.

Algorithm:

1. Start the program
2. Define a structure NODE
data (stores value)
prev (pointer to previous node)
next (pointer to next node)
3. Initialize
head = NULL
INSERT AT BEGINNING
Create a new node using malloc()
Read the value and store it in newNode->data
If list is empty (head == NULL):
Set head = newNode
Else:
Set newNode->next = head
Set head->prev = newNode
Update head = newNode
INSERT AT END
Create a new node
If list is empty:
Set head = newNode
Else:
Traverse the list to reach last node
Set last->next = newNode
Set newNode->prev = last
DELETE FROM BEGINNING
If list is empty:
→ Display “List is empty”
Else:
Store head in temp
Move head = head->next
If head ≠ NULL → set head->prev = NULL
Free temp
DELETE FROM END
If list is empty: display “List empty”
If only one node:
Set head = NULL
Free that node
Else:
Traverse to last node
Set last->prev->next = NULL
Free last node
DISPLAY
If list is empty → print “List is empty”
Else:
Start from head
Print each node using:
data <-> data <-> ... NULL
6. Repeat operations until user selects EXIT
7. Stop the program

Program:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node *head = NULL;

// Create new node
struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertBeginning() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at beginning.\n");
}

// Insert at end
void insertEnd() {
    int value;
    printf("Enter value to insert: ");
    scanf("%d", &value);

    struct Node *newNode = createNode(value);

    if (head == NULL) {
        head = newNode;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;

    printf("Node inserted at end.\n");
}

// Delete from beginning
void deleteBeginning() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    printf("Node deleted from beginning.\n");
}

// Delete from end
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;

    if (temp->next == NULL) {  // only one node
        head = NULL;
        free(temp);
        printf("Last node deleted.\n");
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);

    printf("Node deleted from end.\n");
}

// Display list
void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    printf("Doubly Linked List: ");

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- DOUBLY LINKED LIST MENU ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Delete from Beginning\n");
        printf("4. Delete from End\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: insertBeginning(); break;
            case 2: insertEnd(); break;
            case 3: deleteBeginning(); break;
            case 4: deleteEnd(); break;
            case 5: display(); break;
            case 6: return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}

Output:
--- DOUBLY LINKED LIST MENU ---
1. Insert at Beginning
2. Insert at End
3. Delete from Beginning
4. Delete from End
5. Display
6. Exit
Enter your choice: 1
Enter value to insert: 10
Node inserted at beginning.

Enter your choice: 2
Enter value to insert: 20
Node inserted at end.

Enter your choice: 5
Doubly Linked List: 10 <-> 20 <-> NULL

Enter your choice: 3
Node deleted from beginning.

Enter your choice: 5
Doubly Linked List: 20 <-> NULL

Enter your choice: 6

Result:
The program successfully implements all basic operations of a Doubly Linked List using an interactive menu. It demonstrates insertion, deletion, and traversal in both directions, showing the working of linked list manipulation in C.
