class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        vector<int> v1;
        vector<int> v2;
        for(int i=0;i<words.size();i++){
            if(words[i]==word1)
                v1.push_back(i);
            if(words[i]==word2)
                v2.push_back(i);
        }
        
        int ans=INT_MAX;
        
        int i=0;
        int j=0;
        
        while(i<v1.size()&&j<v2.size()){
            if(abs(v1[i]-v2[j])<ans)
                ans=abs(v1[i]-v2[j]);
            if(v1[i]>v2[j])
                j++;
            else
                i++;
        }
        return ans;
    }
};
