class Solution {
public:
    string removeVowels(string S) {
        string ans;
        for(int i=0;i<S.length();i++)
            if(S[i]!='a'&&S[i]!='e'&&S[i]!='i'&&S[i]!='o'&&S[i]!='u')
                ans+=S[i];
        return ans;
    }
};
