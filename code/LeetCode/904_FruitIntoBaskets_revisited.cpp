//adapted from lee215
//https://leetcode.com/problems/fruit-into-baskets/discuss/170740/JavaC%2B%2BPython-Sliding-Window-for-K-Elements
class Solution {
public:
    int totalFruit(vector<int> &tree) {
        unordered_map<int,int> m;
        int i=0;
        int j=0;
        for(i=0,j=0;j<tree.size();j++){
            m[tree[j]]++;
            if(m.size()>2){
                m[tree[i]]--;
                if(m[tree[i]]==0)
                    m.erase(tree[i]);
                i++;
            }
        }
        return j-i;
    }
};
