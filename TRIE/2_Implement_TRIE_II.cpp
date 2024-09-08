/*

Implement Trie - II
Problem Statement: Implement a Trie data structure that supports the following methods:

Insert (word): To insert a string `word` in the Trie.
Count Words Equal To (word): Return the count of occurrences of the string word in the Trie.
Count Words Starting With (prefix): Return the count of words in the Trie that have the string “prefix” as a prefix.
Erase (word): Delete one occurrence of the string word from the Trie.
Note:

The Erase(word) function is guaranteed to be called only when a word is present in the Trie.
Release the memory associated with variables using dynamic memory allocation at the end of your solution.
*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *links[26];
    int ew, cp; // endWith,countPrefix
    Node()
    {
        ew = 0;
        cp = 0;
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

    void increaseEnd()
    {
        ew++;
    }
    void increasePrefix()
    {
        cp++;
    }
    void deleteEnd()
    {
        ew--;
    }
    void decreasePrefix()
    {
        cp--;
    }

    int getEnd()
    {
        return ew;
    }
    int getPrefix()
    {
        return cp;
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
        // Write your code here.
    }

    void insert(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
        // Write your code here.
    }

    int countWordsEqualTo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefix();
    }

    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                node->decreasePrefix();
            }
            else
                return;
        }
        node->deleteEnd();
    }
};
