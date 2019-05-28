class Solution {
public:
    void sortColors(vector<int>& n) {
        int R=0;
        int W=0;
        int B=0;
        for(int i=0;i<n.size();i++){
            if(n[i]==0)
                ++R;
            if(n[i]==1)
                ++W;
            if(n[i]==2)
                ++B;
        }
        
        for(int i=0; i<n.size();i++){
            if(i<R)
                n[i]=0;
            else if(i<R+W)
                n[i]=1;
            else if(i<R+W+B)
                n[i]=2;
        }
    }
};
