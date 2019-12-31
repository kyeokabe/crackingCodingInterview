class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        auto it=m.begin();
        vector<pair<int,int>> v;
        while(it!=m.end()){
            pair<int,int> temp={it->first,it->second};
            v.push_back(temp);
            it++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
        for(int i=0;i<v.size();i++){
            pq.push(v[i]);
            if(pq.size()>k)
                pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
    
    struct cmp{
        bool operator()(const pair<int,int> &obj1,const pair<int,int> &obj2){
            if(obj2.second<obj1.second)
                return true;
            return false;
        }
    };
};
