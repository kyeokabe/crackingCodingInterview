class Solution {
public:
    int longestValidParentheses(string s) {

        //find index that are invalid
        stack<int> k;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(')
                k.push(i);
            else{
                if(!k.empty()&&s[k.top()]=='('){
                    k.pop();
                }
                else
                    k.push(i);
            }
        }
        
        vector<int> v(s.length(),0);
        while(!k.empty()){
            v[k.top()]=1;
            k.pop();
        }
        
        //problem now becomes find longest contegious 0 subvector
        int count=0;
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                count++;
                if(ans<count)
                    ans=count;
            }
            else
                count=0;
        }
        return ans;
    }
};
