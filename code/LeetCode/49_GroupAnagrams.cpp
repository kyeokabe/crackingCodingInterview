class Solution {
private:
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map <vector<int>,int> m;//unordered_map gives error for some reason...

        int k=0;
        for(int i=0;i<strs.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<strs[i].size();j++)
                ++temp[strs[i][j]-97];
            bool anagram=false;
            int SIZE=ans.size();
            
            auto it=m.find(temp);
            if(it!=m.end()){
                anagram=true;
                vector<string> temp3=ans[it->second];
                temp3.push_back(strs[i]);
                ans[it->second]=temp3;
            }
            else{
                m[temp]=k;
                ++k;
                vector<string> poo;
                poo.push_back(strs[i]);
                ans.push_back(poo);
            }
        }
        return ans;
    }
};
