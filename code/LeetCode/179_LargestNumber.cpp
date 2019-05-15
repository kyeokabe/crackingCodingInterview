class Solution {
public:
    string largestNumber(vector<int>& nums) {
        //adapted from isaac7
        //https://leetcode.com/problems/largest-number/discuss/53157/A-simple-C%2B%2B-solution
        string ans="";
        vector<string> s;
        for(int i=0;i<nums.size();i++)
            s.push_back(to_string(nums[i]));
        sort(s.begin(),s.end(),[](string &s1, const string &s2)
             {return s1+s2>s2+s1;});
        for (int i=0;i<nums.size();i++)
            ans+=s[i];
        if(ans[0]=='0')
            return "0";
        return ans;
    }
};
