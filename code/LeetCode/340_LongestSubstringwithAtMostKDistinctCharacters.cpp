class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        vector<int> v(128,0);
        int R=0;
        int L=0;
        int num_distinct=0;
        int ans=0;
        while(R!=s.length()){
            if(num_distinct<=k){
                if(v[s[R]]==0)
                    num_distinct++;
                v[s[R]]++;
                R++;
                if(num_distinct<=k&&R-L>ans)
                    ans=R-L;
            }
            else{
                v[s[L]]--;
                if(v[s[L]]==0)
                    num_distinct--;
                L++;
            }
        }
        return ans;
    }
};
