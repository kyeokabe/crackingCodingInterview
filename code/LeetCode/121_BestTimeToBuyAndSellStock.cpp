class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==0)
            return 0;
        int dough=0;
        
        for (int i=0;i<prices.size()-1;i++){
            for (int j=1;j<prices.size();j++)
            {
                //cout<<"price j: "<<prices[j]<<" price i: "<<prices[i]<<endl;
                if(prices[j]-prices[i]>dough && j>i)
                    dough=prices[j]-prices[i];
            }
        }
        return dough;
    }
};
