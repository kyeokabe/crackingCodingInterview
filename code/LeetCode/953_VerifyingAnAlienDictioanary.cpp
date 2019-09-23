class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> m;
        
        for(int i=0;i<order.size();i++)
            m[order[i]]=i;
        
        for(int i=1;i<words.size();i++){
            auto it2=m.find(words[i][0]);
            auto it1=m.find(words[i-1][0]);
            if(it1->second>it2->second)
                return false;
            else if(it1->second==it2->second){
                int size=min(words[i].length(),words[i-1].length());
                for(int j=1;j<size;j++){
                    auto it4=m.find(words[i][j]);
                    auto it3=m.find(words[i-1][j]);
                    if(it4->second<it3->second)
                        return false;
                    if(it4->second>it3->second)
                        break;
                    if(j==size-1&&words[i].length()<words[i-1].length())
                        return false;
                }
            }
        }
        return true;
    }
};
