class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size()<3)
            return false;
        int max=-pow(2,31);
        int index =0;
        for (int i=0;i<A.size();i++)
            if (A[i]>max){
                max=A[i];
                index=i;
            }
        if (index==0||index==A.size()-1)
            return false;
        for (int i=0;i<index;i++)
            if (A[i]>=A[i+1])
                return false;
        for (int i=index;i<A.size()-1;i++)
            if (A[i]<=A[i+1])
                return false;
        return true;
    }
};
