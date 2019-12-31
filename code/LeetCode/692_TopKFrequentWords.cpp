class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        
        vector<pair<string,int>> v;
        
        auto it=m.begin();
        while(it!=m.end()){
            pair<string,int> temp={it->first,it->second};
            v.push_back(temp);
            it++;
        }
        
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> pq;
        for(int i=0;i<v.size();i++){
            pq.push(v[i]);
            if(pq.size()>k)
                pq.pop();
        }
        while(k>0){
            ans.push_back(pq.top().first);
            pq.pop();
            k--;
        }
        for(int i=0;i<ans.size()/2;i++)
            swap(ans[i],ans[ans.size()-1-i]);
        
        return ans;
    }
    
    struct cmp{
        bool operator()(const pair<string,int> &op1,const pair<string,int> &op2){
            if(op1.second!=op2.second)
                return op1.second>op2.second;
            return op1.first<op2.first;
        }
    };
};
