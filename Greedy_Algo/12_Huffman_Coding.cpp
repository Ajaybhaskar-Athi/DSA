#include<bits/stdc++.h>
using namespace std;
//Geek for Geeks

struct Node {
    char data;
    int freq; // Changed from unsigned to int
    Node *left, *right;

    Node(char data, int freq) {
        left = right = nullptr; // Changed NULL to nullptr for better readability
        this->data = data;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

class Solution {
public:
    void printCodes(Node* root, string str, vector<string>& codes) {
        if (!root)
            return;
        if (root->data != '$')
            codes.push_back(str);
        printCodes(root->left, str + "0", codes);
        printCodes(root->right, str + "1", codes);
    }

    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        for (int i = 0; i < N; ++i)
            minHeap.push(new Node(S[i], f[i]));

        while (minHeap.size() != 1) {
            Node* left = minHeap.top(); // Initialize left inside the loop
            minHeap.pop();
            Node* right = minHeap.top(); // Initialize right inside the loop
            minHeap.pop();
            Node* nn = new Node('$', left->freq + right->freq); // Rename top to nn and initialize inside the loop
            nn->left = left;
            nn->right = right;
            minHeap.push(nn);
        }

        vector<string> codes;
        printCodes(minHeap.top(), "", codes);
        return codes;
    }
};
