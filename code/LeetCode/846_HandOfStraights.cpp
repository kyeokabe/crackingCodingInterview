class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W!=0)
            return false;
        map<int,int> m;
        for(int i=0;i<hand.size();i++)
            m[hand[i]]++;
        auto it=m.begin();
        for(int i=0;i<hand.size()/W;i++){
            auto it=m.begin();
            it->second--;
            int k=it->first;
            if(it->second==0)
                m.erase(it->first);
            for(int j=0;j<W-1;j++){
                if(next(it)==m.end())
                    return false;
                else{
                    it=next(it);
                    if(it->first-k!=1)
                        return false;
                    k=it->first;
                    it->second--;
                    if(it->second==0)
                        m.erase(it->first);
                }
            }
        }
        return true;
    }
};
