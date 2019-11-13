class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> f(word2.length()+1,0);
        vector<vector<int>> v(word1.length()+1,f);
        
        //v[i][j] ... ops needed to change
        //word1[0...i) to word2[0...j)
        //i=0~word1.length()
        
        for(int i=0;i<v.size();i++)
            v[i][0]=i;
        for(int j=0;j<v[0].size();j++)
            v[0][j]=j;
        
        for(int i=1;i<v.size();i++){
            for(int j=1;j<v[0].size();j++){
                if(word1[i-1]==word2[j-1])
                    v[i][j]=v[i-1][j-1];
                else{
                    v[i][j]=min(v[i][j-1],min(v[i-1][j-1],v[i-1][j]))+1;
                }
            }
        }
        
        return v[v.size()-1][v[0].size()-1];
    }
};
