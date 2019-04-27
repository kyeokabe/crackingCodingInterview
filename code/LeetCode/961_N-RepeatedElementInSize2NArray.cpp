class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        map<int,int> foo;
        for(int i=0;i<A.size();i++){
            auto it=foo.find(A[i]);
            if(it!=foo.end())
                return A[i];
            foo[A[i]]=A[i];
        }
        return 0;
    }
};
