class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()<=1)
            return s.length();
        
        int ans=0;
        vector<int> v(128,0);
        
        int ptrl=0;
        int ptrr=0;
        
        while(ptrr!=s.length()){
            v[s[ptrr]]++;
            while(v[s[ptrr]]>1){
                v[s[ptrl]]--;
                ptrl++;
            }
            ptrr++;
            if(ptrr-ptrl>ans)
                ans=ptrr-ptrl;
        }
        return ans;
    }
};
