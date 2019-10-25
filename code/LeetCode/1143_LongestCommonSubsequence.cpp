class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        if(text1.length()==0||text2.length()==0)
            return 0;
        vector<int> f(text2.length()+1,0);
        vector<vector<int>> v(text1.length()+1,f);
        
        //v[i][j] is the length of longest common subsq of 
        //text1[0...i], text2[0...j]

        
        for(int i=0;i<text1.length();i++){
            for(int j=0;j<text2.length();j++){
                if(text2[j]==text1[i])
                    v[i+1][j+1]=v[i][j]+1;
                else
                    v[i+1][j+1]=max(v[i][j+1],v[i+1][j]);
            }
        }

        return v[text1.length()][text2.length()];
        
    }
};
