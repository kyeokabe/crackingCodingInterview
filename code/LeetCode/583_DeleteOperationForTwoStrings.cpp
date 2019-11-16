class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.length()==0)
            return word2.length();
        if(word2.length()==0)
            return word1.length();
        
        vector<int> foo(word2.length(),0);
        vector<vector<int>> v(word1.length(),foo);
        
        for(int i=0;i<word1.length();i++){
            for(int j=0;j<word2.length();j++){
                v[i][j]=word1[i]==word2[j]?1:0;
            }
        }
        
        for(int j=1;j<word2.length();j++)
            v[0][j]=max(v[0][j-1],v[0][j]);
        
        for(int i=1;i<word1.length();i++)
            v[i][0]=max(v[i-1][0],v[i][0]);
        
        for(int i=1;i<word1.length();i++){
            for(int j=1;j<word2.length();j++){
                v[i][j]=max(max(v[i-1][j],v[i][j-1]),v[i][j]+v[i-1][j-1]);
            }
        }
        
        int common_length=v[word1.length()-1][word2.length()-1];
        return word1.length()+word2.length()-2*common_length;
    }
};
