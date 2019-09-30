class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        if(s.length()==1){
            if(s[0]==t[0]||abs(s[0]-t[0])<=maxCost)
                return 1;
            else
                return 0;
        }
        
        
        vector<int> v(s.length(),0);
        for(int i=0;i<s.length();i++)
            v[i]=abs(s[i]-t[i]);
        
        int ptr1=0, ptr2=0, sum=0, ans=0;

        while(ptr2!=v.size()){
 
            if(sum<=maxCost){
                sum+=v[ptr2];
                ptr2++;
                if(sum<=maxCost&&ans<ptr2-ptr1)
                    ans=ptr2-ptr1;
            }
            else{
                sum-=v[ptr1];
                ptr1++;
            }
        }
        return ans;
    }
};
