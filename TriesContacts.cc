#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Trie
{
private:
    static const int alphabet_size = 26;
public:
    bool is_end;
    int prefix_count;
    Trie* child[alphabet_size];
    Trie() {
        is_end = false;
        prefix_count = 0;
    }
    Trie(bool b, int pc):is_end{b}, prefix_count{pc} {}
};

Trie* contacts_head = new Trie();

void insert(const string& word)
{
    Trie* curr = contacts_head;
    curr->prefix_count++; //important
    for (unsigned i = 0; i < word.size(); ++i) {
        int letter = (int)word[i] - (int)'a';
        if (curr->child[letter] == nullptr) {
            curr->child[letter] = new Trie();
        }
        curr->child[letter]->prefix_count++;
        curr = curr->child[letter];
    }
    curr->is_end = true;
}

bool search(const string& word) {
    Trie* curr = contacts_head;
    for (unsigned i = 0; i < word.size(); i++) {
        if (curr->child[((int)word[i]-(int)'a')] == nullptr) {
            return false;
        }
        curr = curr->child[((int)word[i]-(int)'a')];
    }
    return true;
}

int word_prefix_count (const string& word) {
    Trie* curr = contacts_head;
    for (unsigned i = 0; i < word.size(); i++) {
        if (curr->child[((int)word[i]-(int)'a')] == nullptr) {
            return 0;
        }
        curr = curr->child[((int)word[i]-(int)'a')];
    }
    return curr->prefix_count;
}

int main() {
    int n; cin >> n;
    int counter = 0;
    
    for (unsigned i = 0; i < n; ++i)
    {
        string command;
        string q;
        cin >> command >> q;
        
        if (command == "add") {insert(q);}
        else {
            counter = word_prefix_count(q);
            cout << counter << endl;
            counter = 0;
        }
    }
    
    return 0;
}
