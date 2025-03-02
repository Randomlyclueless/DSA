#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// Huffman tree node
struct Node
{
    double freq;
    int index; // Use index to represent the character
    Node *left, *right;

    Node(double f, int idx) : freq(f), index(idx), left(nullptr), right(nullptr) {}
};

// Custom comparator for priority queue (min-heap)
struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        if (a->freq == b->freq) // Tie-breaker: keep order stable
            return a->index > b->index;
        return a->freq > b->freq; // Min heap based on frequency
    }
};

// Function to generate Huffman codes
void generateCodes(Node *root, string code, unordered_map<int, string> &huffmanCodes)
{
    if (!root)
        return;

    if (!root->left && !root->right)
    { // Leaf node
        huffmanCodes[root->index] = code;
    }

    generateCodes(root->left, code + ".", huffmanCodes);
    generateCodes(root->right, code + "-", huffmanCodes);
}

int main()
{
    int n;
    cin >> n;
    vector<double> frequencies(n);

    // Read frequencies
    for (int i = 0; i < n; i++)
    {
        cin >> frequencies[i];
    }

    // Min-Heap (Priority Queue) for Huffman Tree construction
    priority_queue<Node *, vector<Node *>, Compare> minHeap;

    // Create leaf nodes for each character (using index as identifier)
    for (int i = 0; i < n; i++)
    {
        minHeap.push(new Node(frequencies[i], i));
    }

    // Build Huffman Tree
    while (minHeap.size() > 1)
    {
        // Extract the two smallest frequency nodes
        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();

        // Create a new node with combined frequency
        Node *merged = new Node(left->freq + right->freq, min(left->index, right->index)); // Use min index for ordering
        merged->left = left;
        merged->right = right;

        minHeap.push(merged);
    }

    // Generate Huffman Codes
    unordered_map<int, string> huffmanCodes;
    generateCodes(minHeap.top(), "", huffmanCodes);

    // Output Huffman Codes in the order of input
    for (int i = 0; i < n; i++)
    {
        cout << huffmanCodes[i] << endl;
    }

    return 0;
}
