class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount==0)
            return 1;
        if(coins.size()==0)
            return 0;
        vector<int> foo(amount+1,0);
        vector<vector<int>> v(coins.size(),foo);
        
        for(int r=0;r<v.size();r++){
            for(int c=1;c<=amount;c++){
                int temp=coins[r]==c?1:0;
                temp+=(c-coins[r]>=0)?v[r][c-coins[r]]:0;
                if(r>=1)
                    temp+=v[r-1][c];
                v[r][c]=temp;
            }
        }
        
        return v[coins.size()-1][amount];
    }
};
