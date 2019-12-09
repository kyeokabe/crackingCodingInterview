class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> v;
        int i=1;
        while(n>0){
            v.push_back(i);
            i++;
            n--;
        }
        
        while(k-1>0){
            next_permutation(v.begin(),v.end());
            k--;
        }
        string ans="";
        while(v.size()>0){
            ans=to_string(v.back())+ans;
            v.pop_back();
        }
        return ans;
    }
};
