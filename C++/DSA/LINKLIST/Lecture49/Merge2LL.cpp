#include <iostream>
using namespace std;

// Definition of a singly linked list node
struct Node
{
    int data;                                // Value stored in the node
    Node *next;                              // Pointer to the next node
    Node(int val) : data(val), next(NULL) {} // Constructor
};

// Helper function to merge the second sorted list into the first in-place
Node *solve(Node *first, Node *second)
{
    Node *curr1 = first;       // Pointer to traverse the first list
    Node *next1 = curr1->next; // Next node in the first list
    Node *curr2 = second;      // Pointer to traverse the second list
    Node *next2 = nullptr;     // To store next node of curr2 temporarily

    // Traverse both lists until we reach the end of either
    while (next1 != NULL && curr2 != NULL)
    {
        // Check if the current node of second list fits between curr1 and next1
        if (curr2->data >= curr1->data && curr2->data <= next1->data)
        {
            next2 = curr2->next; // Save next node of curr2

            curr1->next = curr2; // Insert curr2 after curr1
            curr2->next = next1; // Link curr2 to next1

            // Move pointers forward
            curr1 = curr2;
            curr2 = next2;
        }
        else
        {
            // Move forward in the first list
            curr1 = next1;
            next1 = next1->next;

            // If we reach the end of the first list, append remaining second list
            if (next1 == NULL)
            {
                curr1->next = curr2;
                return first;
            }
        }
    }

    // Return the head of the merged list
    return first;
}

// Function to merge two sorted linked lists
Node *sortTwoLists(Node *first, Node *second)
{
    // If one of the lists is empty, return the other
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    // Determine which list has the smaller head and merge accordingly
    if (first->data <= second->data)
    {
        return solve(first, second); // Merge second into first
    }
    else
    {
        return solve(second, first); // Merge first into second
    }
}

// Helper function to print a linked list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " "; // Print current node's data
        head = head->next;         // Move to the next node
    }
    cout << endl; // New line at the end of the list
}

int main()
{
    // Create first sorted list: 1 -> 3 -> 5
    Node *first = new Node(1);
    first->next = new Node(3);
    first->next->next = new Node(5);

    // Create second sorted list: 2 -> 4 -> 6
    Node *second = new Node(2);
    second->next = new Node(4);
    second->next->next = new Node(6);

    // Print the original lists
    cout << "List 1: ";
    printList(first);

    cout << "List 2: ";
    printList(second);

    // Merge the two sorted lists
    Node *merged = sortTwoLists(first, second);

    // Print the merged list
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
