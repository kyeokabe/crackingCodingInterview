//adapted from Back to Back SWE
//https://www.youtube.com/watch?v=fV-TF4OvZpk
class Solution {
public:
    int lengthOfLIS(vector<int>& n) {
        if(n.size()==0)
            return 0;
        vector<int> v(n.size(),1);
        for (int i=1;i<n.size();i++){
            for(int j=0;j<i;j++){
                if(n[j]<n[i]&&v[i]<v[j]+1)
                    v[i]=v[j]+1;
            }
        }
        int ans=1;
        for(int i=0;i<n.size();i++)
            if(v[i]>ans)
                ans=v[i];
        return ans;
    }
};
