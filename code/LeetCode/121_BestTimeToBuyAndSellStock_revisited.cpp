class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int ans=0;
        int maxP=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            maxP=max(maxP,prices[i]);
            ans=max(ans,maxP-prices[i]);
        }
        
        return ans;
    }
};


/*
//O(n) time complexity
//O(n) space complexity
//notice whole v vector is not necessary
//only max value needs to be remembered

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        
        int ans=0;
        vector<int> v(prices.size(),0);
        v[prices.size()-1]=prices[prices.size()-1];
        for(int i=prices.size()-2;i>=0;i--){
            v[i]=max(v[i+1],prices[i]);
            ans=max(ans,v[i+1]-prices[i]);
        }
        
        return ans;
    }
};
*/
