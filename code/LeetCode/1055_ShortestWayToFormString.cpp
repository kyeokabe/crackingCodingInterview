class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char,int> m;
        for(int i=0;i<source.length();i++)
            m[source[i]]++;
        for(int i=0;i<target.length();i++){
            auto it=m.find(target[i]);
            if(it==m.end())
                return -1;
        }
        int ans=0;
        int i=0;
        int j=0;
        while(i<target.length()){
            j=0;
            while(j<source.length()){
                if(i==target.length())
                    break;
                if(source[j]==target[i]){
                    i++;
                }
                j++;
            }
            ans++;
        }
        return ans;
    }
};
