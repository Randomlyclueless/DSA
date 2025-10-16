#include <iostream>
using namespace std;

// Node class to represent each element of the linked list
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Function to reverse the linked list in groups of size k
Node *kReverse(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    Node *curr = head;
    Node *prev = nullptr;
    Node *next = nullptr;
    int count = 0;

    // Step 1: Count if there are at least k nodes remaining
    Node *temp = head;
    int nodeCount = 0;
    while (temp != nullptr && nodeCount < k)
    {
        temp = temp->next;
        nodeCount++;
    }

    // If fewer than k nodes remain, do NOT reverse
    if (nodeCount < k)
    {
        return head;
    }

    // Step 2: Reverse the first k nodes
    while (curr != nullptr && count < k)
    {
        next = curr->next; // store next node
        curr->next = prev; // reverse current node pointer
        prev = curr;       // move prev one step ahead
        curr = next;       // move curr one step ahead
        count++;
    }

    // Step 3: Recur for the remaining list and connect the parts
    if (next != nullptr)
    {
        head->next = kReverse(next, k); // link the rest
    }

    // Step 4: Return new head of this reversed part
    return prev;
}

// Utility function to print a linked list
void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Main function to test the code
int main()
{
    // Step 1: Create a linked list manually
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->next = new Node(7);
    head->next->next->next->next->next->next->next = new Node(8);

    int k = 3;

    cout << "Original list: ";
    printList(head);

    // Step 2: Call kReverse
    Node *newHead = kReverse(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(newHead);

    return 0;
}
