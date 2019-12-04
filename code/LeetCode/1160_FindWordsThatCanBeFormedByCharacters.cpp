class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> v(26,0);
        for(int i=0;i<chars.length();i++)
            v[chars[i]-'a']++;
        
        int ans=0;
        for(int i=0;i<words.size();i++){
            vector<int> v2=v;
            bool Good=true;
            for(int j=0;j<words[i].length();j++){
                v2[words[i][j]-'a']--;
                if(v2[words[i][j]-'a']<0){
                    Good=false;
                    break;
                }
            }
            if(Good)
                ans+=words[i].length();
        }
        return ans;
    }
};
