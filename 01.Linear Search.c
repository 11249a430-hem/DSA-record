Aim:
To write a C program that performs linear search on an array to find the position of a given element.

Algorithm:

1.Start the program.
2.Read the size of the array (n).
3.Read n elements into the array.
4.Read the element to be searched (key).
5.Traverse the array from index 0 to n–1.
6.If any element matches key, print its position and stop the search.
7.If the loop ends without a match, print “Element not found”.
8.End the program.

Program:
    #include <stdio.h>

int main()
{
    int n, key, i;

    // Ask user for size of the array
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    // Declare array of size 'n'
    int arr[n];

    // Input array elements from the user
    printf("Enter the elements of the array : ");
    for(i=0; i<n; i++)
        scanf("%d", &arr[i]);

    // Ask user which element to search
    printf("Enter the element to search : ");
    scanf("%d", &key);

    // Linear search begins
    for(i=0; i<n; i++)
    {
        // If key is found at index i
        if(arr[i] == key)
        {
            printf("Element found at position %d \n", i+1);  
            // Return 0 ends the program immediately after finding the element
            return 0;
        }
    }

    // If loop completes without finding the element
    printf("Element not found");
}


Output:
Enter the size of the array : 5
Enter the elements of the array : 10 25 30 45 50
Enter the element to search : 30
Element found at position 3

Result:
This program searches an element in an array using linear search and correctly displays whether the element is found or not.
