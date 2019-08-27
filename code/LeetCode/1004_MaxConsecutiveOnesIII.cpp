class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int count=0;
        for(int i=0;i<A.size();i++)
            if(A[i]==0)
                count++;
        //cout<<"count = "<<count<<endl;
        if(count<=K)
            return A.size();
        
        vector<int> B;
        B.push_back(0);
        for(int i=0;i<A.size();i++)
            B.push_back(A[i]);
        B.push_back(0);
        
        int min=0;
        int max=0;
        while(K+1>0||B[max]==1){
            if(B[max]==0)
                K--;
            max++;
        }
        
        int ans=max-min-1;
        //cout<<"ans = "<<ans<<", min = "<<min<<", max = "<<max<<endl;
      
        while(++max<=B.size()){
            while(B[max]==1)
                max++;
            min++;
            while(B[min]==1)
                min++;
            //cout<<"ans = "<<ans<<", min = "<<min<<", max = "<<max<<endl;
            if(max-min>ans)
                ans=max-min-1;
        }
        return ans;
    }
};
