class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        if(nums.size()==0)
            return ans;
        int max_val=INT_MIN;
        int ind=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_val){
                max_val=nums[i];
                ind=i;
            }
        }
        
        vector<int> v;
        for(int i=ind+1;i<nums.size();i++)
            v.push_back(nums[i]);
        for(int i=0;i<=ind;i++)
            v.push_back(nums[i]);
        stack<int> s;
        /*
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<" "<<endl;
        */
        for(int i=v.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(v[i]);
                v[i]=-1;
            }
            else{
                if(s.top()>v[i]){
                    int temp=v[i];
                    v[i]=s.top();
                    s.push(temp);
                }
                else{
                    while(!s.empty()&&s.top()<=v[i])
                        s.pop();
                    if(s.empty()){
                        s.push(v[i]);
                        v[i]=-1;
                    }
                    else{
                        int temp=s.top();
                        s.push(v[i]);
                        v[i]=temp;
                    }
                }
            }
        }
        /*
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<" "<<endl;
        */
        for(int i=v.size()-1-ind;i<v.size();i++)
            ans.push_back(v[i]);
        for(int i=0;i<v.size()-1-ind;i++)
            ans.push_back(v[i]);
        return ans;
    }
};
