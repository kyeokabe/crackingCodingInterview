class Solution {
public:
    int maxArea(vector<int>& h) {
        int L=0;
        int R=h.size()-1;
        int ans=0;
        while(L<R){
            if(min(h[L],h[R])*(R-L)>ans)
                ans=min(h[L],h[R])*(R-L);
            if(h[L]<h[R])
                L++;
            else
                R--;
        }
        return ans;
    }
};
