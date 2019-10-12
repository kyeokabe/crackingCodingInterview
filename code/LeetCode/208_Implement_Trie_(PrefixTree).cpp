class Trie {
    
private:
    unordered_map<string,int> m;
public:
    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        m[word]++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto it=m.find(word);
        if(it==m.end())
            return false;
        return true;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto it=m.begin();
        while(it!=m.end()){
            if(it->first.substr(0,prefix.length())==prefix)
                return true;
            it++;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
