#include "Autofill.h"



Autofill::TrieNode* Autofill::getNewNode()
{
    
    TrieNode* newNode = new TrieNode;

    
    newNode->_isEndOfWord = false;

    
    for (int i = 0; i < ALPHABET_SIZE; i++)
        newNode->_children[i] = nullptr;

    newNode->count = 0;

    return newNode;
}


void Autofill::insert(string key)
{
    TrieNode* node = _root;

    for (int i = 0; i < key.length(); i++)
    {
        
        int index = key[i] - 'a';

        
        if (!node->_children[index])
            node->_children[index] = getNewNode();

        node = node->_children[index];
        node->count++; 
    }

    
    node->_isEndOfWord = true;
}


bool Autofill::search(string key)
{
    TrieNode* node = _root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a'; 
        if (!node->_children[index])
            return false;

        node = node->_children[index];
    }

    return (node != nullptr && node->_isEndOfWord);
}


bool Autofill::isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->_children[i])
            return false;
    return true;
}

 
Autofill::TrieNode* Autofill::remove(string key, TrieNode* root, int depth)
{
    if (depth == 0)
        root = _root;

     
    if (!root)
        return nullptr;

    if (!search(key))
        return nullptr;

    
    if (depth == key.size()) {

         
        if (root->_isEndOfWord) {
            root->_isEndOfWord = false;
            root->count--;
        }

        
        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    
    int index = key[depth] - 'a';
    root->_children[index] = remove(key, root->_children[index], depth + 1);
    root->count--;

    
    if (isEmpty(root) && root->_isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }

    
    return root;
}

bool Autofill::searchOption(string key) {
    TrieNode* node = _root;
    _option.erase();

    if (!node)
        return false;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a'; 
        if (!node->_children[index])
            return false;

        node = node->_children[index];
    }

    string buf;

    if (node->_isEndOfWord) {
        _option += key;
        _option += ' ';
        node->_isEndOfWord = false;
        recurcia(node, buf, key);
        node->_isEndOfWord = true;

    }
    else
        recurcia(node, buf, key);

}

void Autofill::recurcia(TrieNode* node, string& buf, const string& key) {

    if (node->_isEndOfWord) {
        _option += key;
        for (int i = 0; i < buf.length(); ++i) {
            _option += buf[i];
        }
        _option += ' ';
        if(node->count == 1)
            return;
    }

    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->_children[i]) {
            buf += i + 97;
            recurcia(node->_children[i], buf, key);
            buf.pop_back();
        }
   }

}

string Autofill::get_optionByOne() {
    string buf;

    if (_option.empty())
        return buf;
    
    int i = 0;
    for (; i < _option.length() && _option[i] != ' '; ++i)
        buf += _option[i];
    _option.erase(0, i + 1);
    return buf;
}