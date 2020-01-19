class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)
            return 0;
        unordered_map<int,int> m;
        m[0]++;
        queue<int> q;
        q.push(0);
        int ans=0;
        while(!q.empty()){
            ans++;
            int SIZE=q.size();
            for(int i=0;i<SIZE;i++){
                if(q.front()+nums[q.front()]>=nums.size()-1)
                    return ans;
                else{
                    for(int j=q.front()+nums[q.front()];j>q.front();j--){
                        if(j<nums.size()&&m.find(j)==m.end()){
                            m[j]++;
                            q.push(j);
                        }
                        else
                            break;
                    }
                
                }
                q.pop();
            }
        }
        
        return -1;
    }
};
