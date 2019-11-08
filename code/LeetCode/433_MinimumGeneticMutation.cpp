class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        int ans=0;
        queue<string> q;
        
        map<string,int> m;
        for(int i=0;i<bank.size();i++)
            m[bank[i]]++;
        
        q.push(start);
        
        while(!q.empty()){
            ans++;
            int SIZE=q.size();
            for(int i=0;i<SIZE;i++){
                auto it=m.begin();
                while(it!=m.end()){
                    if(charDiff(it->first,q.front())==1){
                        if(it->first==end)
                            return ans;
                        q.push(it->first);
                        m.erase(it);
                    }
                    if(it!=m.end())
                        it++;
                }
                q.pop();
            }
        }
        return -1;
    }
    
    
    int charDiff(string s1, string &s2){
        int count=0;
        for(int i=0;i<min(s1.length(),s2.length());i++)
            if(s1[i]!=s2[i])
                count++;
        return count;
    }
};
