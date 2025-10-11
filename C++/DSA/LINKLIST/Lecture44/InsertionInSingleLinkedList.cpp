#include <iostream>
using namespace std;

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

// Insert Element at Head
void InsertElementAtHead(Node *&head, int x)
{
    Node *temp = new Node(x);
    temp->next = head;
    head = temp;
}

// Insert Element at Tail
void InsertAtTail(Node *&head, int x)
{
    Node *temp = new Node(x);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *traverse = head;
    while (traverse->next != NULL)
    {
        traverse = traverse->next; // FIXED (removed extra `'`)
    }
    traverse->next = temp;
}

// Insert at any position
void InsertAnywhere(Node *&head, int pos, int x)
{
    if (pos == 1)
    {
        InsertElementAtHead(head, x);
        return;
    }

    //     This loop moves traverse to the (pos-1)th node.
    // Example:
    // If pos = 3, we want traverse to point at the 2nd node
    // (because we’ll insert after it).

    Node *traverse = head;
    for (int i = 1; i < pos - 1 && traverse != NULL; i++)
    {
        traverse = traverse->next;
    }

    if (traverse == NULL)
    {
        return;
    }
    Node *nn = new Node(x);    // create new node
    nn->next = traverse->next; // new node points to what (pos)th node was
    traverse->next = nn;       // previous node now points to new node
}

// Insert element before given node
// here insertEl is the element we want to insert
// val is the value before which you want to insert element
Node *InsertBeforeElement(Node *head, int insertEl, int val)
{
    if (head == NULL)
    {
        return NULL; // FIXED (was return NULL:)
    }
    // Case 1: insert before head
    if (head->data == val)
    {
        Node *nn = new Node(insertEl);
        nn->next = head; // FIXED (was returning node without linking)
        return nn;
    }
    // Case 2 = traverse list
    Node *traverse = head;
    while (traverse->next != NULL)
    {
        if (traverse->next->data == val)
        { // FIXED (was traverse->next == val)
            Node *nn = new Node(insertEl);
            nn->next = traverse->next; // FIXED (was using undefined temp)
            traverse->next = nn;
            break;
        }
        traverse = traverse->next; // FIXED (was temp = temp->next)
    }
    return head;
}

// print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// ================= DRIVER MAIN =================
int main()
{
    Node *head = NULL;

    cout << "Insert at Head:" << endl;
    InsertElementAtHead(head, 10);
    InsertElementAtHead(head, 20);
    InsertElementAtHead(head, 30);
    printList(head); // 30 -> 20 -> 10 -> NULL

    cout << "\nInsert at Tail:" << endl;
    InsertAtTail(head, 40);
    InsertAtTail(head, 50);
    printList(head); // 30 -> 20 -> 10 -> 40 -> 50 -> NULL

    cout << "\nInsert Anywhere (position 3):" << endl;
    InsertAnywhere(head, 3, 99);
    printList(head); // 30 -> 20 -> 99 -> 10 -> 40 -> 50 -> NULL

    cout << "\nInsert Before Element (before 40):" << endl;
    head = InsertBeforeElement(head, 77, 40);
    printList(head); // 30 -> 20 -> 99 -> 10 -> 77 -> 40 -> 50 -> NULL

    cout << "\nInsert Before Head (before 30):" << endl;
    head = InsertBeforeElement(head, 5, 30);
    printList(head); // 5 -> 30 -> 20 -> 99 -> 10 -> 77 -> 40 -> 50 -> NULL

    cout << "\nTry Inserting Before Non-Existent Value (999):" << endl;
    head = InsertBeforeElement(head, 100, 999);
    printList(head); // unchanged list

    return 0;
}
