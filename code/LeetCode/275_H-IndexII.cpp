class Solution {
public:
    int hIndex(vector<int>& c) {
        int ans=0;
        for (int i=0;i<c.size();i++){
            if (c[c.size()-1-i]>=i+1)
                ans++;
            else
                break;
        }
        return ans;
    }
};
