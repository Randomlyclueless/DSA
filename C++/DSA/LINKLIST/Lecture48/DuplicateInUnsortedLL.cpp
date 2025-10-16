#include <iostream>
#include <unordered_set>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {}
};

//
// ----------------------------------------------------
// 🧩 Approach 1: Brute Force (O(N²) Time, O(1) Space)
// ----------------------------------------------------
Node *removeDuplicatesBrute(Node *head)
{
    if (head == NULL)
        return NULL;

    // Outer loop - pick each element one by one
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        Node *prev = curr;
        Node *temp = curr->next;

        // Inner loop - check for duplicates ahead
        for (; temp != NULL; temp = temp->next)
        {
            if (temp->data == curr->data)
            {
                // Duplicate found — remove it
                prev->next = temp->next;
                // (optional: delete temp to free memory)
            }
            else
            {
                prev = temp;
            }
        }
    }

    return head;
}

//
// ----------------------------------------------------
// 🧩 Approach 2: Sort the List + Remove Adjacent Duplicates
// (O(N log N) Time, O(1) Space) — Order is NOT preserved
// ----------------------------------------------------

// -------- Merge Two Sorted Lists --------
Node *merge(Node *left, Node *right)
{
    if (!left)
        return right;
    if (!right)
        return left;

    Node *result = NULL;

    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }

    return result;
}

// -------- Find Middle Node --------
Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

// -------- Merge Sort --------
Node *mergeSort(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *mid = findMid(head);
    Node *rightHead = mid->next;
    mid->next = NULL;

    Node *left = mergeSort(head);
    Node *right = mergeSort(rightHead);

    return merge(left, right);
}

// -------- Remove Duplicates from Sorted List --------
Node *removeDuplicatesSorted(Node *head)
{
    if (!head)
        return NULL;

    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *dup = curr->next;
            curr->next = dup->next;
            delete dup;
        }
        else
        {
            curr = curr->next;
        }
    }
    return head;
}

//
// ----------------------------------------------------
// 🧩 Approach 3: Optimal Using Hash Set
// (O(N) Time, O(N) Space) — Preserves Order
// ----------------------------------------------------
Node *removeDuplicatesOptimal(Node *head)
{
    if (head == NULL)
        return NULL;

    unordered_set<int> visited;
    Node *curr = head;
    Node *prev = NULL;

    while (curr != NULL)
    {
        if (visited.find(curr->data) != visited.end())
        {
            // Duplicate found, remove it
            prev->next = curr->next;
            delete curr;
        }
        else
        {
            visited.insert(curr->data);
            prev = curr;
        }
        curr = prev->next;
    }

    return head;
}

//
// ----------------------------------------------------
// 🧩 Utility Functions
// ----------------------------------------------------
void printList(Node *head)
{
    for (Node *temp = head; temp != NULL; temp = temp->next)
        cout << temp->data << " ";
    cout << endl;
}

//
// ----------------------------------------------------
// 🧩 Main Function
// ----------------------------------------------------
int main()
{
    // Example: 3 -> 2 -> 3 -> 4 -> 2 -> 3
    Node *head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    // ------------ Brute Force ------------
    Node *head1 = removeDuplicatesBrute(head);
    cout << "After Brute Force removal: ";
    printList(head1);

    // Re-create list (since sorting modifies structure)
    Node *head2 = new Node(3);
    head2->next = new Node(2);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    head2->next->next->next->next = new Node(2);
    head2->next->next->next->next->next = new Node(3);

    // ------------ Sort + Delete ------------
    head2 = mergeSort(head2);
    head2 = removeDuplicatesSorted(head2);
    cout << "After Sorting + Removing duplicates: ";
    printList(head2);

    // Re-create list again
    Node *head3 = new Node(3);
    head3->next = new Node(2);
    head3->next->next = new Node(3);
    head3->next->next->next = new Node(4);
    head3->next->next->next->next = new Node(2);
    head3->next->next->next->next->next = new Node(3);

    // ------------ Optimal (Hash Set) ------------
    head3 = removeDuplicatesOptimal(head3);
    cout << "After Optimal removal (Hash Set): ";
    printList(head3);

    return 0;
}
