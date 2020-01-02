class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_set<string> s;    
        priority_queue<string,vector<string>,cmp> pq;
        int ans=0;
        
        for(int i=0;i<words.size();i++){
            s.insert(words[i]);
            pq.push(words[i]);
        }
    
        while(!pq.empty()){
            if(pq.top().length()<=ans)
                break;
            int count=help(pq.top(),s);
            if(count>ans)
                ans=count;
            pq.pop();
        }
        return ans;
        
    }
    
    int help(string temp,unordered_set<string> &s){
        int count=0;
        for(int i=0;i<temp.length();i++){
            int count_temp;
            string s1=temp.substr(0,i);
            string s2;
            if(i+1<temp.length())
                s2=temp.substr(i+1,temp.length()-(i+1));
            string s3=s1+s2;
            if(s.find(s3)!=s.end())
                count_temp=help(s3,s)+1;
            else
                count_temp=1;
            if(count_temp>count)
                count=count_temp;
        }
        return count;
    }
    
    struct cmp{
        bool operator()(const string &s1, const string &s2){
            return s2.length()>=s1.length()?true:false;
        }
    };
};
