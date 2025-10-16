#include <iostream>
#include <map>
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

// Floyd’s Cycle Detection Algorithm (Tortoise and Hare)
Node *floydsCycle(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
        {
            return slow; // Intersection point
        }
    }
    return NULL; // No loop
}

// Find the starting node of the loop
Node *getStartingNode(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *intersection = floydsCycle(head);
    if (intersection == NULL)
        return NULL; // No loop

    Node *slow = head;
    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove loop safely
void removeLoop(Node *head)
{
    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    if (startOfLoop == NULL)
    {
        cout << "No loop found to remove." << endl;
        return;
    }

    Node *temp = startOfLoop;
    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }
    temp->next = NULL; // Break the loop
    cout << "Loop removed successfully!" << endl;
}

// Helper function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    cout << "Linked List: ";
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main()
{
    // Create nodes
    Node *node1 = new Node(10);
    Node *node2 = new Node(20);
    Node *node3 = new Node(30);
    Node *node4 = new Node(40);

    // Link nodes
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    // Create a loop
    node4->next = node2; // Creates a loop (40 → 20)

    // Detect loop
    Node *loopNode = floydsCycle(node1);
    if (loopNode != NULL)
    {
        cout << "✅ Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "❌ No loop detected in the linked list." << endl;
    }

    // Find start of loop
    Node *startNode = getStartingNode(node1);
    if (startNode != NULL)
    {
        cout << "🔁 Cycle starts at node with data: " << startNode->data << endl;
    }

    // Remove loop
    removeLoop(node1);

    // Verify loop removal
    if (floydsCycle(node1) == NULL)
    {
        cout << "✅ Linked list is now linear (no loop)." << endl;
    }
    else
    {
        cout << "⚠️ Loop still exists!" << endl;
    }

    // Print final list
    printList(node1);

    return 0;
}
