class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";  
        if(strs.size()==1)
            return strs[0];
        int i=0;
        bool checkNext=true;
        while(checkNext){
            char c=strs[0][i];
            for(int j=1;j<strs.size();j++)
                if(i>=strs[j].length()||strs[j][i]!=c){
                    checkNext=false;
                    break;
                }
            if(checkNext==false)
                break;
            i++;
        }
        return strs[0].substr(0,i);
    }
};
