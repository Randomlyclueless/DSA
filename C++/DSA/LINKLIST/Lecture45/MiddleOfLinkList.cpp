#include <iostream>
using namespace std;

// Node class
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

// Function to print list from a given node
void printFromNode(Node *node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Function to find middle node (second middle if even)
Node *findMiddle(Node *head)
{
    if (head == nullptr)
        return nullptr; // Empty list

    Node *slow = head;
    Node *fast = head;

    // Move fast 2 steps, slow 1 step
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow; // slow now points to middle (second middle if even)
}

int main()
{
    int N;
    cin >> N;

    Node *head = nullptr;
    Node *tail = nullptr;

    // Read linked list values
    for (int i = 0; i < N; i++)
    {
        int val;
        cin >> val;
        Node *newNode = new Node(val);

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Find middle node
    Node *middle = findMiddle(head);

    // Print from middle node to end
    printFromNode(middle);

    return 0;
}
