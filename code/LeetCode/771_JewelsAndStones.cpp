class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,char> foo;
        for (int i=0;i<J.length();i++){
            foo[J[i]]=J[i];
        }
        int count=0;
        for (int i=0;i<S.length();i++){
            auto it=foo.find(S[i]);
            if (it!=foo.end())
                count++;
        }
        return count;
    }
};
