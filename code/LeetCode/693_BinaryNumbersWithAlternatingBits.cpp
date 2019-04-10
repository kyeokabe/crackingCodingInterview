class Solution {
public:
    bool hasAlternatingBits(int n) {
        vector<int> foo;
        while(n!=0){
            foo.push_back(n%2);
            n=n>>1;
        }
        for(int i=0;i<foo.size()-1;i++)
            if (foo[i]==foo[i+1])
                return false;
        return true;
    }
};
