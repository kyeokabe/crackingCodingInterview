class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        for(int i=0;i<coins.size();i++){
            if(amount==coins[i])
                return true;
            else if(coins[i]>amount){
                swap(coins[i],coins.back());
                coins.pop_back();
                i--;
            }
        }
        vector<int> v(amount+1,0);
        for(int i=0;i<coins.size();i++)
            v[coins[i]]=1;
        for(int i=1;i<v.size();i++){
            if(v[i]>0){
                for(int j=0;j<coins.size();j++){
                    int temp=i+coins[j];
                    if(temp<=amount){
                        if(v[temp]==0)
                            v[temp]=v[i]+1;
                        else
                            v[temp]=min(v[temp],v[i]+1);
                    }
                }
            }
        }
        return v[amount]==0?-1:v[amount];
    }
};
