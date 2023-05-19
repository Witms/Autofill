#pragma once
#include <string>
#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26; // английский алфавит

class Autofill {
private:

    
    struct TrieNode
    {
        TrieNode* _children[ALPHABET_SIZE];
        bool _isEndOfWord; 
        int count; 
        TrieNode() {};
        
        
    };

public:

    void insert(string);
    bool search(string);
    TrieNode* remove(string, TrieNode* root = nullptr, int depth = 0);
    bool searchOption(string);
    string get_optionByOne();
    

    Autofill() { _root = getNewNode(); }

private:

    TrieNode* getNewNode();
    bool isEmpty(TrieNode*);
    void recurcia(TrieNode*, string&, const string& );

    TrieNode* _root;
    string _option;
};