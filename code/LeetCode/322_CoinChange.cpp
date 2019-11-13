class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0)
            return 0;
        
        unordered_map<int,int> m;
        
        for(int i=0;i<coins.size();i++){
            if(coins[i]>amount){
                swap(coins[i],coins[coins.size()-1]);
                coins.pop_back();
                i--;
            }
            
        }
        
        queue<int> q;
        int ans=1;
        for(int i=0;i<coins.size();i++){
            if(coins[i]==amount)
                return ans;
            q.push(coins[i]);
            m[coins[i]]++;
        }
        
        while(!q.empty()){
            ans++;
            int SIZE=q.size();
            for(int i=0;i<SIZE;i++){
                for(int j=0;j<coins.size();j++){
                    if(long(q.front()+coins[j])==long(amount))
                        return ans;
                    if(long(q.front()+coins[j])<long(amount)){
                        auto it=m.find(q.front()+coins[j]);
                        if(it==m.end()){
                            m[q.front()+coins[j]]++;
                            q.push(q.front()+coins[j]);
                        }
                    }
                }
                q.pop();
            }
        }
        return -1;
    }
};
