class TrieNode {
public:
    bool isWord;
    vector<TrieNode *> nextNodes;
    
    TrieNode() {
        isWord = false;
        nextNodes.resize(26, NULL);
    }
};

class WordDictionary {
    TrieNode *root;
    
    void addWordToTrie(string word) {
        auto cur = root;
        
        for (auto c : word) {
            if (!cur->nextNodes[c - 'a']) {
                cur->nextNodes[c - 'a'] = new TrieNode();
            }
            
            cur = cur->nextNodes[c - 'a'];
        }
        
        cur->isWord = true;
    }
    
    bool searchInTrie(TrieNode *cur, string word) {
        for (int i = 0; i < word.size(); i++) {
            char c = word[i];
            if (c != '.') {
                if (!cur->nextNodes[c - 'a']) {
                    return false;
                }
                
                cur = cur->nextNodes[c - 'a'];
            } else {
                for (int j = 0; j < 26; j++) {
                    if (cur->nextNodes[j] && searchInTrie(cur->nextNodes[j], word.substr(i + 1))) {
                        return true;
                    }
                }
                
                return false;
            }
        }
        
        return cur->isWord;
    }
    
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        addWordToTrie(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return searchInTrie(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */