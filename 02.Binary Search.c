Aim:
To write a C program to search an element in a sorted array using the Binary Search algorithm.

Algorithm:
1.Start the program.
2.Read the number of elements n from the user.
3.Read the n elements of the array in sorted order.
4.Read the element to be searched (key).
5.Initialize
    low = 0,
    high = n - 1.
6.Repeat while low <= high:
a. Find the middle index: mid = (low + high) / 2.
b. If arr[mid] == key,
    Display that the element is found at position mid + 1.
    Set found = 1 and exit the loop.
c. If arr[mid] < key, set low = mid + 1.
d. Else set high = mid - 1.
7.If the loop ends and found is still 0, display “Element not found”.
8.Stop the program.

Program:
#include <stdio.h>

int main()
{
    int n, i, mid, low, high, key, found = 0;

    // Take number of elements from the user
    printf("Enter the number of elements : ");
    scanf("%d", &n);

    // Declare array of size n
    int arr[n];

    // Input elements (must be in sorted order for binary search)
    printf("Enter the %d elements in sorted order : ", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Initialize low and high for binary search
    low = 0;
    high = n - 1;

    // Input element to search
    printf("Enter the element to search : ");
    scanf("%d", &key);

    // Binary search loop
    while(low <= high)
    {
        // Find middle index
        mid = (low + high) / 2;

        // If key is found at mid
        if (arr[mid] == key)
        {
            printf("The Element %d is found at the position %d", key, mid + 1);
            found = 1;   // Mark that element is found
            break;       // Exit the loop
        }
        // If key is greater, search in right half
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        // If key is smaller, search in left half
        else
        {
            high = mid - 1;
        }
    }

    // If element was not found in the array
    if (!found)
    {
        printf("Element not found");
        return 0;
    }
}

Output:
Enter the number of elements : 5
Enter the 5 elements in sorted order : 10 20 30 40 50
Enter the element to search : 30
The Element 30 is found at position 3

Result:
This program uses binary search to quickly find an element in a sorted array and displays whether the element is found or not.
