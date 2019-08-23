class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,char> m;
            int temp=0;
            for(int j=i;j<s.length();j++){
                auto it=m.find(s[j]);
                if(it!=m.end())
                    break;
                else{
                    m.insert({s[j],s[j]});
                    temp++;
                    if(temp>ans)
                        ans=temp;
                }
            }
        }
        return ans;
    }
};
