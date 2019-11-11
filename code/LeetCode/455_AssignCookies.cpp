class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int ptr1=0;
        int ptr2=0;
        
        int ans=0;
        while(ptr1<g.size()&&ptr2<s.size()){
            if(g[ptr1]<=s[ptr2]){
                ans++;
                ptr1++;
                ptr2++;
            }
            else if(g[ptr1]>s[ptr2])
                ptr2++;
        }
        return ans;
    }
};
