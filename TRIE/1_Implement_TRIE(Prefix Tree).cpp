#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *links[26];
    bool flag;
    Node()
    {
        flag = false;
        for (auto &a : links)
            a = nullptr;
    }

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != nullptr;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        this->flag = true;
    }
    bool isEnd()
    {
        return this->flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                // insert if not present
                node->put(word[i], new Node());
            }
            // moving reference
            node = node->get(word[i]);
        }
        node->setEnd();
        // marking end of word as true
    }

    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *node = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }
        return true;
    }
};
