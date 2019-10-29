//since array element range is limited
//a vector can be used so each index number
//represents the element value and the entree
//represents the occurance

class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        vector<int> v(1001,0);
        for(int i=0;i<A.size();i++)
            v[A[i]]++;
        int i=1000;
        while(i>=0&&v[i]!=1)
            i--;
        return i;
    }
};
