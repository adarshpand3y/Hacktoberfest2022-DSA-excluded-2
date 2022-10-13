#include <bits/stdc++.h>
using namespace std;

class Trienode
{
public:
    Trienode *children[26];
    char data;
    bool isTerminal;

    Trienode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
public:
    Trienode *root;

    Trie()
    {
        root = new Trienode('\0');
    }
    void insertutil(Trienode *root, string word)
    {
        // base case;
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        Trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        else
        {
            child = new Trienode(word[0]);
            root->children[index] = child;
        }

        insertutil(child, word.substr(1));
    }

    void insertword(string word)
    {
        insertutil(root, word);
    }

    bool searchutil(Trienode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        Trienode *child;

        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }

        else
        {
            return false;
        }
        // recursion
        return searchutil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchutil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();
    t->insertword("ARM");
    t->insertword("ARM");
    t->insertword("ARMYD");

    cout << "Present or not " << t->search("ARM");
    return 0;
}