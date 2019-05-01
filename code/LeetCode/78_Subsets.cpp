class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=pow(2,nums.size());
        for(int i=0;i<n;i++){
            queue<int> foo;
            int k=i;
            while(k!=0){
                if(k%2==0)
                    foo.push(1);
                else
                    foo.push(0);
                k=k/2;
            }

            vector<int> temp;
            int count=0;
            while(!foo.empty()){
                if(foo.front()==0)
                    temp.push_back(nums[count]);
                foo.pop();
                ++count;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
