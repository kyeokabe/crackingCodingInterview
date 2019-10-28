class Solution {
public:
    vector<string> crawl(string startURL, HtmlParser htmlParser) {
        string host="http://";
        int i=7;
        while(i<startURL.length()&&startURL[i]!='/'){
            host+=startURL[i];
            i++;
        }
        unordered_map<string,int> m;
        m[startURL]++;
        vector<string> ans;
        queue<string> Q;
        Q.push(startURL);
        while(!Q.empty()){
            vector<string> v=htmlParser.getUrls(Q.front());
            
            for(int i=0;i<v.size();i++){
                auto it=m.find(v[i]);
                if(it==m.end()&&isSameHost(v[i],host)){
                    m[v[i]]++;
                    Q.push(v[i]);
                }
            }
            ans.push_back(Q.front());
            Q.pop();
        }
        return ans;
    }
    
    bool isSameHost(string &a, string &host){
        if(a.length()<host.length())
            return false;
        for(int i=0;i<host.length();i++)
            if(a[i]!=host[i])
                return false;
        if(a.length()==host.length())
            return true;
        if(a[host.length()]!='/')
            return false;
        return true;
    }
};
