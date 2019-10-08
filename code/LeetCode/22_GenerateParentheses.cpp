class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        if(n==0)
            return ans;
        string temp="(";
        int open=n-1;
        int closed=n;
        help(ans, open, closed, temp);
        return ans;
    }
    
    void help(vector<string> &ans, int open, int closed, string &temp){
        if(open==0&&closed==0){
            ans.push_back(temp);
        }
        if(open>=1){
            temp=temp+"(";
            help(ans,open-1,closed,temp);
            temp=temp.substr(0,temp.length()-1);
        }
        if(open<closed&&closed>=1){
            temp=temp+")";
            help(ans,open,closed-1,temp);
            temp=temp.substr(0,temp.length()-1);
        }
    }
    
};
