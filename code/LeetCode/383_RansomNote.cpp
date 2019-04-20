class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> foo;
        for (int i=0;i<26;i++)
            foo.push_back(0);        
        for (int i=0;i<magazine.length();i++)
            foo[magazine[i]-97]++;
        for (int i=0;i<ransomNote.length();i++){
            if (foo[ransomNote[i]-97]<=0)
                return false;
            foo[ransomNote[i]-97]--;
        }
        return true;
    }
};
