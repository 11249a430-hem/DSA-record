Aim:
To implement Circular Queue operations such as enqueue, dequeue, and display using a linked list, where the last node links back to the first node.

Algorithm:

1. Start the program
2. Define a NODE structure
data
next pointer
ENQUEUE Algorithm
Read value
Create a new node
If queue is empty:
front = rear = newNode
rear->next = front (circular link)
Else:
rear->next = newNode
rear = newNode
rear->next = front
DEQUEUE Algorithm
If queue empty → Underflow
If only one node:
front = rear = NULL
Else:
Move front = front->next
Update rear->next = front
Free deleted node
DISPLAY Algorithm
If queue empty → print message
Start with temp = front
Traverse using:
do { print data; temp = temp->next; } while(temp != front)
Stop when returned to start
3.Repeat until user chooses 
4.EXIT

Program:

#include <stdio.h>
#include <stdlib.h>

// Structure for a queue node
struct Node {
    int data;
    struct Node *next;   // Points to next node (for circular link)
};

// Front → first element, Rear → last element
struct Node *front = NULL, *rear = NULL;


// ENQUEUE OPERATION – Insert at the rear
void enqueue() {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    // Create a new node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty
    if (front == NULL) {
        front = rear = newNode;
        rear->next = front;      // Circular connection
    } 
    else {
        rear->next = newNode;    // Link old rear to new node
        rear = newNode;          // Move rear forward
        rear->next = front;      // Maintain circular link
    }

    printf("Element enqueued.\n");
}


// DEQUEUE OPERATION – Delete from the front
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow.\n");
        return;
    }

    struct Node *temp = front;

    // If only one element in queue
    if (front == rear) {
        front = rear = NULL;
    } 
    else {
        front = front->next;     // Move front to next node
        rear->next = front;      // Keep circular link
    }

    free(temp);                  // Delete old front
    printf("Element dequeued.\n");
}


// DISPLAY OPERATION – Print all queue elements
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");

    // Traverse until we return to front
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("(back to front)\n");
}


// MAIN FUNCTION – Menu-driven program
int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

Output:
--- CIRCULAR QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value to enqueue: 10
Element enqueued.

Enter choice: 1
Enter value to enqueue: 20
Element enqueued.

Enter choice: 3
Circular Queue elements: 10 -> 20 -> (back to front)

Enter choice: 2
Element dequeued.

Enter choice: 3
Circular Queue elements: 20 -> (back to front)

Enter choice: 4

Result:
The program successfully implements a Circular Queue using a Linked List.
It performs enqueue, dequeue, and display efficiently, while maintaining the circular connection from rear to front.Aim:
To implement Circular Queue operations such as enqueue, dequeue, and display using a linked list, where the last node links back to the first node.

Algorithm:

1. Start the program
2. Define a NODE structure
data
next pointer
ENQUEUE Algorithm
Read value
Create a new node
If queue is empty:
front = rear = newNode
rear->next = front (circular link)
Else:
rear->next = newNode
rear = newNode
rear->next = front
DEQUEUE Algorithm
If queue empty → Underflow
If only one node:
front = rear = NULL
Else:
Move front = front->next
Update rear->next = front
Free deleted node
DISPLAY Algorithm
If queue empty → print message
Start with temp = front
Traverse using:
do { print data; temp = temp->next; } while(temp != front)
Stop when returned to start
3.Repeat until user chooses 
4.EXIT

Program:

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *front = NULL, *rear = NULL;

// ENQUEUE operation
void enqueue() {
    int value;
    printf("Enter value to enqueue: ");
    scanf("%d", &value);

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (front == NULL) {     // Queue empty
        front = rear = newNode;
        rear->next = front;  // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }

    printf("Element enqueued.\n");
}

// DEQUEUE operation
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow.\n");
        return;
    }

    struct Node *temp = front;

    if (front == rear) {  // Only one node
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front;  // Maintain circular link
    }

    free(temp);
    printf("Element dequeued.\n");
}

// DISPLAY operation
void display() {
    if (front == NULL) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;

    printf("Circular Queue elements: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("(back to front)\n");
}

int main() {
    int choice;

    while (1) {
        printf("\n--- CIRCULAR QUEUE USING LINKED LIST ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

Output:
--- CIRCULAR QUEUE USING LINKED LIST ---
1. Enqueue
2. Dequeue
3. Display
4. Exit
Enter choice: 1
Enter value to enqueue: 10
Element enqueued.

Enter choice: 1
Enter value to enqueue: 20
Element enqueued.

Enter choice: 3
Circular Queue elements: 10 -> 20 -> (back to front)

Enter choice: 2
Element dequeued.

Enter choice: 3
Circular Queue elements: 20 -> (back to front)

Enter choice: 4

Result:
The program successfully implements a Circular Queue using a Linked List.
It performs enqueue, dequeue, and display efficiently, while maintaining the circular connection from rear to front.
