class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        ans.push_back(1);
        if (rowIndex==0)
            return ans;
        
        ans.push_back(1);

        if (rowIndex==1)
            return ans;

        helper(rowIndex-1,ans);
        return ans;
    }
    
    void helper(int rowIndex, vector<int> &ans){
        if (rowIndex==0)
            return;
        vector<int> ans2;
        ans2.push_back(1);
        
        for(int i=1;i<ans.size();i++)
            ans2.push_back(ans[i]+ans[i-1]);
        
        ans2.push_back(1);
        ans=ans2;
        helper(rowIndex-1,ans);
    }
};
