class Solution {
public:
    string frequencySort(string s) {
        string ans;
        unordered_map<char,int> m;
        for(int i=0;i<s.length();i++)
            m[s[i]]++;
        vector<pair<char,int>> v;
        auto it=m.begin();
        while(it!=m.end()){
            pair<char,int> temp={it->first,it->second};
            v.push_back(temp);
            it++;
        }
        priority_queue<pair<char,int>, vector<pair<char,int>>, cmp> pq;
        for(int i=0;i<v.size();i++)
            pq.push(v[i]);
        while(!pq.empty()){
            int SIZE=pq.top().second;
            string temp(pq.top().second,pq.top().first);
            ans+=temp;
            pq.pop();
        }
        return ans;
    }
    
    struct cmp{
        bool operator()(const pair<char,int> &obj1,const pair<char,int> &obj2){
            if(obj2.second>obj1.second)
                return true;
            return false;
        }
    };
};
