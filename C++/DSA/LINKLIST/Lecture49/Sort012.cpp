// Approach1

// Count no of 0, 1, 3 and then update the linked list with these counts

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *sortList(Node *head)
{
    int zerocount = 0;
    int onecount = 0;
    int twocount = 0;
    Node *temp = head;

    // Count 0s, 1s, 2s
    while (temp != NULL)
    {
        if (temp->data == 0)
            zerocount++;
        else if (temp->data == 1)
            onecount++;
        else if (temp->data == 2)
            twocount++;
        temp = temp->next;
    }

    temp = head;

    // Fill the linked list with 0s, 1s, 2s
    while (temp != NULL)
    {
        if (zerocount != 0)
        {
            temp->data = 0;
            zerocount--;
        }
        else if (onecount != 0)
        {
            temp->data = 1;
            onecount--;
        }
        else if (twocount != 0)
        {
            temp->data = 2;
            twocount--;
        }
        temp = temp->next;
    }

    return head;
}

// Definition for singly-linked list node
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

// Helper function to attach a node to a tail and move the tail forward
void populate(Node *&tail, Node *curr)
{
    tail->next = curr; // Link current node to the tail
    tail = curr;       // Move the tail to the current node
}

// Function to sort a linked list of 0s, 1s, and 2s
Node *sortList(Node *head)
{
    // Create dummy nodes for three separate lists: 0s, 1s, and 2s
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head; // Start from the head of the original list

    // Traverse the original list
    while (curr != NULL)
    {
        int val = curr->data; // Current node's value

        // Append the node to the corresponding list based on its value
        if (val == 0)
        {
            populate(zeroTail, curr); // Add node to 0s list
        }
        else if (val == 1)
        {
            populate(oneTail, curr); // Add node to 1s list
        }
        else
        {                            // val == 2
            populate(twoTail, curr); // Add node to 2s list
        }

        curr = curr->next; // Move to the next node
    }

    // Connect the three lists together

    // If the 1s list is not empty, link 0s -> 1s -> 2s
    if (oneHead->next != NULL)
    {
        zeroTail->next = oneHead->next; // 0s tail points to start of 1s
        oneTail->next = twoHead->next;  // 1s tail points to start of 2s
    }
    else
    { // If 1s list is empty, link 0s -> 2s directly
        zeroTail->next = twoHead->next;
    }

    twoTail->next = NULL; // Last node of 2s list should point to NULL

    head = zeroHead->next; // New head is start of 0s list

    // Delete dummy nodes to avoid memory leaks
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head; // Return the sorted list
}
