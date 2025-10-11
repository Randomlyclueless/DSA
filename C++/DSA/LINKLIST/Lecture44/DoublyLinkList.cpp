#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next; // recursively free rest of list if still linked
            next = NULL;
        }
        cout << "Memory freed for node with data " << val << endl;
    }
};

// Print linked list from head to tail
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print linked list from tail to head
void printReverse(Node *tail)
{
    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}

// Insert at Head
void InsertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL)
    { // empty list
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// Insert at Tail
void InsertAtTail(Node *&head, Node *&tail, int d)
{
    if (tail == NULL)
    { // empty list
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
        return;
    }

    Node *temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

// Insert at any position
void InsertAnywhere(Node *&head, Node *&tail, int insertEl, int pos)
{
    if (pos == 1)
    {
        InsertAtHead(head, tail, insertEl);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < pos - 1 && temp != NULL)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at end
    if (temp == tail)
    {
        InsertAtTail(head, tail, insertEl);
        return;
    }

    // inserting in between
    if (temp != NULL)
    {
        Node *nn = new Node(insertEl);
        nn->next = temp->next;
        temp->next->prev = nn;
        temp->next = nn;
        nn->prev = temp;
    }
}

// Delete node at position
void deleteNode(int pos, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (pos == 1)
    { // delete head
        Node *temp = head;

        if (head->next != NULL)
        {
            head->next->prev = NULL;
        }
        else
        {
            // if only one node
            tail = NULL;
        }

        head = head->next;
        temp->next = NULL; // break link so destructor doesn’t delete whole list
        delete temp;
    }
    else
    {
        Node *curr = head;
        int cnt = 1;

        while (cnt < pos && curr != NULL)
        {
            curr = curr->next;
            cnt++;
        }

        if (curr == NULL)
        {
            cout << "Position out of range!" << endl;
            return;
        }

        curr->prev->next = curr->next;

        if (curr->next != NULL)
        {
            curr->next->prev = curr->prev;
        }
        else
        {
            // deleting last node
            tail = curr->prev;
        }

        curr->next = NULL;
        curr->prev = NULL;
        delete curr;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    // Insert operations
    InsertAtHead(head, tail, 10);
    InsertAtHead(head, tail, 5);
    InsertAtTail(head, tail, 11);
    InsertAnywhere(head, tail, 58, 2);
    InsertAnywhere(head, tail, 99, 1);
    InsertAnywhere(head, tail, 77, 6);

    cout << "Forward: ";
    print(head); // 99 5 58 10 11 77
    cout << "Reverse: ";
    printReverse(tail); // 77 11 10 58 5 99

    // Delete operations
    cout << "\nDelete 1st node:" << endl;
    deleteNode(1, head, tail);
    print(head);

    cout << "Delete 3rd node:" << endl;
    deleteNode(3, head, tail);
    print(head);

    cout << "Delete last node:" << endl;
    deleteNode(4, head, tail);
    print(head);

    cout << "Final list forward: ";
    print(head);
    cout << "Final list reverse: ";
    printReverse(tail);

    return 0;
}
