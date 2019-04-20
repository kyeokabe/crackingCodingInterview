class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> foo;
        for (int i=0;i<26;i++)
            foo.push_back(0);
        
        for(int i=0;i<s.length();i++){
            foo[s[i]-97]++;
        }
        
        for (int i=0;i<s.length();i++)
            if (foo[s[i]-97]==1)
                return i;  
        
        return -1;
    }
};
