class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size()>1){
            sort(stones.begin(),stones.end());
            int temp=stones[stones.size()-1]-stones[stones.size()-2];
            stones.erase(stones.begin()+(stones.size()-1));
            stones.erase(stones.begin()+(stones.size()-1));
            if(temp!=0)
                stones.push_back(temp);
        }
        if(stones.size()==1)
            return stones[0];
        return 0;
    }
};
