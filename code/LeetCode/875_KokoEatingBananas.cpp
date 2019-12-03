class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int low=1;
        int high=1;
        for(int i=0;i<piles.size();i++)
            if(piles[i]>high)
                high=piles[i];
        //cout<<check(piles,low,H)<<endl;
        int mid=(high+low)/2;
        while(high>low){
            if(check(piles,mid,H)){
                if(high-1==low){
                    if(!check(piles,low,H)&&check(piles,high,H))
                        return high;
                    if(!check(piles,low,H)&&!check(piles,high,H))
                        return high+1;
                    if(check(piles,low,H)&&check(piles,high,H))
                        return low;
                }
                
                high=mid;
                mid=(high+low)/2;
            }
            else{
                if(high-1==low){
                    if(!check(piles,low,H)&&check(piles,high,H))
                        return high;
                    if(!check(piles,low,H)&&!check(piles,high,H))
                        return high;
                    if(check(piles,low,H)&&check(piles,high,H))
                        return low;
                }
                low=mid;
                mid=(high+low)/2;
            }
        }
        return 0;
    }
    
    bool check(vector<int> piles, int eat, int H){
        int count=0;
        for(int i=0;i<piles.size();i++){
            if(piles[i]%eat==0)
                count+=piles[i]/eat;
            else
                count+=piles[i]/eat+1;
            if(count>H)
                return false;
        }
        return true;
    }
};
