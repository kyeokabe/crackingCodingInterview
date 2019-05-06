class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.size()==0)
            return {};
        vector<int> foo;
        for(int i=0;i<nums.size();i++)
            foo.push_back(nums[i]);
        for(int i=0;i<nums.size();i++)
            foo.push_back(nums[i]);
        stack<int> n;
        stack<int> i;
        
        int k=0;
        
        while(k<foo.size()){
            if(n.empty()||n.top()>=foo[k]){
                n.push(foo[k]);
                i.push(k);
            }
            
            else if(n.top()<foo[k]){
                while(!n.empty()&&n.top()<foo[k]){
                    foo[i.top()]=foo[k];
                    n.pop();
                    i.pop();
                }
                n.push(foo[k]);
                i.push(k);
            }
            ++k;
        }
        while(!n.empty()){
            foo[i.top()]=-1;
            i.pop();
            n.pop();
        }
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(foo[i]);
        }
        return ans;
    }
};
