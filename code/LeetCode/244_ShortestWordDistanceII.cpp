class WordDistance {
    
private:
    unordered_map<string,vector<int>> m;
    
public:
    WordDistance(vector<string>& words) {
        for(int i=0;i<words.size();i++){
            if(m.find(words[i])==m.end()){
                vector<int> temp={i};
                m[words[i]]=temp;
            }
            else
                m[words[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        int ans=INT_MAX;
        int i=0;
        int j=0;
        while(i<m[word1].size()&&j<m[word2].size()){
            if(abs(m[word1][i]-m[word2][j])<ans)
                ans=(abs(m[word1][i]-m[word2][j]));
            if(m[word1][i]>m[word2][j])
                j++;
            else
                i++;
        }
        return ans;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(words);
 * int param_1 = obj->shortest(word1,word2);
 */
