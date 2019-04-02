class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        bool monoIncrease=true;
        bool monoDecrease=true;
        for (int i=0;i<A.size()-1;i++){
            //cout<<"i = "<<i<<", i+1 = "<<i+1<<endl;
            if (A[i]<A[i+1])
                monoDecrease=false;
            if (A[i]>A[i+1])
                monoIncrease=false;
        }
        if (monoIncrease || monoDecrease)
            return true;
        
        return false;
    }
};
