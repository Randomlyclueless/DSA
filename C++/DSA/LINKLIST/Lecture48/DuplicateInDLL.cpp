#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

// Function to print the doubly linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to append a new node at the end
void append(Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);
    Node *last = *head_ref;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    new_node->prev = last;
}

// Your removeDuplicates function
Node *removeDuplicates(Node *head)
{
    if (!head)
        return NULL;

    Node *curr = head;

    while (curr && curr->next)
    {
        if (curr->data == curr->next->data)
        {
            Node *dup = curr->next;
            curr->next = dup->next;
            if (dup->next)
            {
                dup->next->prev = curr;
            }
            delete dup;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

int main()
{
    Node *head = NULL;

    // Creating a sorted doubly linked list with duplicates
    append(&head, 1);
    append(&head, 2);
    append(&head, 2);
    append(&head, 3);
    append(&head, 3);
    append(&head, 3);
    append(&head, 4);

    cout << "Original list: ";
    printList(head);

    // Remove duplicates
    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}
