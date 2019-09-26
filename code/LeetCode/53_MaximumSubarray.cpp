//adapted from youtube channel "Back To Back SWE"
//https://www.youtube.com/watch?v=2MmGzdiKR9Y
class Solution {
public:
    int maxSubArray(vector<int>& n) {
        if(n.size()==0)
            return 0;
        if(n.size()==1)
            return n[0];
        vector<int> sub(n.size(),0);
        sub[0]=n[0];
        int ans=n[0];
        for(int i=1;i<n.size();i++){
            sub[i]=max(n[i],sub[i-1]+n[i]);
            if(sub[i]>ans)
                ans=sub[i];
        }
        return ans;
    }
};
