class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
     
        vector<string> ans;
        unordered_map<string,int> m;
        for(int i=0;i<words.size();i++)
            m[words[i]]++;
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
        vector<pair<int,string>> v;
        
        auto it=m.begin();
        while(it!=m.end()){
            pair<int,string> temp={it->second,it->first};
            pq.push(temp);
            if(pq.size()>k)
                pq.pop();
            it++;
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        for(int i=0;i<ans.size()/2;i++)
            swap(ans[i],ans[ans.size()-1-i]);
        return ans;
    }
    
    struct cmp{
        bool operator()(const pair<int,string> &s1,const pair<int,string> &s2){
            return s1.first==s2.first?s2.second>s1.second:s2.first<s1.first;
        }
    };
};
