//adapted from https://leetcode.com/problems/perfect-squares/discuss/71488/Summary-of-4-different-solutions-(BFS-DP-static-DP-and-mathematics)
class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        v.assign(n+1,INT_MAX);
        v[0]=0;
        if(n<=0)
            return 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                //cout<<"i = "<<i<<", j = "<<j<<endl;
                //cout<<"v[i-1] = "<<v[i-1]<<endl;
                //cout<<"v[i-j*j] = "<<v[i-j*j]<<endl;
                int temp=min(v[i-1]+1,v[i]);// this is actually redundant
                //just need to compare v[i] and v[i-j*j]+1 min
                v[i]=min(temp,v[i-j*j]+1);
            }
            //cout<<endl;
        }
        return v[n];
    }
};
