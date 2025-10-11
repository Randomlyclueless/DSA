#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Memory is free for node with data " << this->data << endl;
    }
};

void insertNode(Node *&tail, int element, int d)
{
    // empty list
    if (tail == NULL)
    {
        Node *nn = new Node(d);
        tail = nn;
        nn->next = nn;
    }
    else
    {
        Node *curr = tail;
        // find the element
        while (curr->data != element)
        {
            curr = curr->next;
            if (curr == tail)
            { // if element not found
                cout << "Element " << element << " not found!" << endl;
                return;
            }
        }
        // insert after curr
        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void deletenode(Node *&tail, int value)
{
    // empty list
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    Node *prev = tail;
    Node *curr = prev->next;

    // search for the node to delete
    while (curr->data != value)
    {
        if (curr == tail)
        {
            cout << "Value " << value << " not found in the list!" << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    // one node in the list
    if (curr == prev)
    {
        tail = NULL;
    }
    else if (curr == tail)
    {
        // deleting tail node → move tail pointer
        tail = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node *tail)
{
    if (tail == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node *tail = NULL;

    insertNode(tail, 5, 3); // inserting in empty list
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);

    deletenode(tail, 3);
    print(tail);
}
