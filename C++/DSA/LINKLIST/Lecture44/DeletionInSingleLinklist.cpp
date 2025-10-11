#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Insert element at head
void InsertElement(Node *&head, int x)
{
    Node *nn = new Node(x);
    nn->next = head;
    head = nn;
}

// Delete element at Head
void DeleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
}

// Delete element at Tail
void DeleteAtTail(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL)
    { // only one node
        delete head;
        head = NULL;
        return;
    }
    Node *traverse = head;
    while (traverse->next->next != NULL)
    {
        traverse = traverse->next;
    }
    delete traverse->next;
    traverse->next = NULL;
}

// Delete element by value
void DeleteByValue(Node *&head, int val)
{
    if (head == NULL)
    {
        cout << "List is empty, nothing to delete." << endl;
        return;
    }
    // if head contains value
    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    Node *traverse = head;
    while (traverse->next != NULL && traverse->next->data != val)
    {
        traverse = traverse->next;
    }
    if (traverse->next == NULL)
    {
        cout << "Value " << val << " not found in list." << endl;
        return;
    }
    Node *temp = traverse->next;
    traverse->next = traverse->next->next;
    delete temp;
}

// Print list
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
int main()
{
    Node *head = NULL;

    cout << "Insert elements at head:" << endl;
    InsertElement(head, 10);
    InsertElement(head, 20);
    InsertElement(head, 30);
    printList(head); // 30 -> 20 -> 10 -> NULL

    cout << "\nDelete at Head:" << endl;
    DeleteAtHead(head);
    printList(head); // 20 -> 10 -> NULL

    cout << "\nDelete at Tail:" << endl;
    DeleteAtTail(head);
    printList(head); // 20 -> NULL

    cout << "\nInsert more elements:" << endl;
    InsertElement(head, 40);
    InsertElement(head, 50);
    InsertElement(head, 60);
    printList(head); // 60 -> 50 -> 40 -> 20 -> NULL

    cout << "\nDelete by Value (delete 40):" << endl;
    DeleteByValue(head, 40);
    printList(head); // 60 -> 50 -> 20 -> NULL

    cout << "\nDelete by Value (try 999, not present):" << endl;
    DeleteByValue(head, 999);
    printList(head); // unchanged

    return 0;
}
