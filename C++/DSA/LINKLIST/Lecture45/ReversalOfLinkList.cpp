#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr; // Initialize next to nullptr
    }
};

// Iterative reversal
Node *ReverseLinkList(Node *&head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head; // Return head as is if empty or single node
    }
    Node *prev = nullptr;
    Node *curr = head;
    Node *fwd = nullptr;
    while (curr != nullptr)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
}

// Recursive reversal helper function
void recursiveReverse(Node *&head, Node *curr, Node *prev)
{
    if (curr == nullptr)
    {
        head = prev;
        return;
    }
    Node *forward = curr->next;
    recursiveReverse(head, forward, curr);
    curr->next = prev;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    // Create linked list 1 -> 2 -> 3 -> NULL
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original List: ";
    printList(head);

    // Iterative reversal
    head = ReverseLinkList(head);
    cout << "Reversed List (Iterative): ";
    printList(head);

    Node *head2 = new Node(7);
    head2->next = new Node(8);
    head2->next->next = new Node(9);
    cout << "Original List: ";
    printList(head2);
    // Recursive reversal back to original
    recursiveReverse(head2, head2, nullptr);
    cout << "Reversed List (Recursive): ";
    printList(head2);

    return 0;
}
