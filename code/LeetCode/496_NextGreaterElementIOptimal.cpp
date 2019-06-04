class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (!s.empty() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }

        vector<int> ans;
        
        for (int n : findNums){
            auto it=m.find(n);
            
            if(it==m.end())
                ans.push_back(-1);
            else
                ans.push_back(it->second);
        }
        
        return ans;
    }
};
