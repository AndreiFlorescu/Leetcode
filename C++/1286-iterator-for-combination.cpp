class CombinationIterator {
    vector<string> combs;
    int cur_pos;
    int comb_len;
    string chars;
    
    void create_combs(int len, string word, int pos) {
        if (len == comb_len) {
            combs.push_back(word);
            return;
        }
        
        for (int i = pos; i < chars.length(); i++) {
                word.push_back(chars[i]);
                
                create_combs(len + 1, word, i + 1);
            
                word.erase(word.end() - 1);
        }
        
        return;
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {
        cur_pos = 0;
        comb_len = combinationLength;
        chars = characters;
        
        string s;
        
        create_combs(0, s, 0);
    }
    
    string next() {
        return combs[cur_pos++];
    }
    
    bool hasNext() {
        return cur_pos != combs.size();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */