#include <iostream>
using namespace std;


class TrieNode {
    public :
    char data;  // parent data
    TrieNode **children;    // pointer array which will store the addresses of each child
    bool isTerminal;
    
    TrieNode(char data) {
        this -> data = data;    // Constructor
        children = new TrieNode*[26];
        for(int i = 0; i <26; i++) {
            children[i] = NULL; // Initialising each index with NULL as there is no element at present
        }
        isTerminal = false;
    }
    
};

class Trie {
    TrieNode *root;
    
    public :
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = true;
            return;
        }
        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if(root->children[index] != NULL) {
            child = root -> children[index];
        }
        else{
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        // Recursive Calculation
        insertWord(child, word.substr(1));
    }
    
    void insertWord(string word) {
        insertWord (root, word);
    }
    
    bool search(TrieNode *parent, string word)
    {
        if (word.size() == 0)
            return parent->isTerminal;
        if (parent->children[word[0] - 'a'] != NULL)
            return search(parent->children[word[0] - 'a'], word.substr(1));
        else
            return false;
    }

    bool search(string word)
    {
        // Write your code here
        if (word.size() == 0)
            return false;
        return search(root, word);
    }
    
    void removeWord(TrieNode *root, string word) {
        // Base case
        if(word.size() == 0) {
            root -> isTerminal = false;
            return;
        }
        
        // Small Calculation
        TrieNode *child;
        int index = word[0] - 'a';
        if(root-> children[index] != NULL) {
            child = root -> children[index];
        }
        else{
            // Word Not Found
            return;
        }
        
        removeWord(child, word.substr(1));
        
        // Remove Child Node if it is Useless
        
        if(child -> isTerminal == false) {
            for(int i = 0; i<26; i++) {
                if(child -> children[i] != NULL) {
                    return;
                }
            }
            delete child;
            root->children[index] = NULL;
        }
    }
    void removeWord(string word) {
        removeWord(root, word);
    }
    
    
};

int main() {
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    
    cout << t.search("and") << endl;
    t.removeWord("and");
    cout<<t.search("and") << endl;
}

// Output

// 1 means true as "and" exist
// 0 means false as "and" does not exist