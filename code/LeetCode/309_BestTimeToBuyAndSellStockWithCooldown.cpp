//adapted from
//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

class Solution {
public:
    int maxProfit(vector<int>& p) {
        if(p.size()==0)
            return 0;
        vector<int> s0(p.size(),0);
        vector<int> s1(p.size(),0);
        vector<int> s2(p.size(),0);
        
        s0[0]=0;
        s1[0]=-p[0];
        s2[0]=INT_MIN;
        
        for(int i=1;i<p.size();i++){
            s0[i]=max(s0[i-1],s2[i-1]);
            s1[i]=max(s0[i-1]-p[i],s1[i-1]);
            s2[i]=s1[i-1]+p[i];
        }
        
        return max(s2[p.size()-1],s0[p.size()-1]);
    }
};
