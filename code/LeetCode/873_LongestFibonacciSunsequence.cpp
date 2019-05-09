class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        int len=0;
        unordered_map<int,int> m;
        for(int i=0;i<A.size();i++){
            m[A[i]]=i;
        }
        
        for(int i=0;i<A.size();i++){
            int idx1;
            int idx2;
            for(int j=i+1;j<A.size();j++){
                int temp=2;
                idx1=i;
                idx2=j;
                help(m,idx1,idx2,temp,A);
                if(temp>len)
                    len=temp;
            }
        }
        return len<=2 ? 0: len;
    }
        
    void help(unordered_map<int,int> &m, int i, int j, int &temp, vector<int> &A){
        if(i>=A.size()||j>=A.size())
            return;
        auto it=m.find(A[i]+A[j]);
        if(it==m.end())
            return;
        else{
            i=j;
            j=it->second;
            ++temp;
            help(m,i,j,temp,A);
        }
    }
};
