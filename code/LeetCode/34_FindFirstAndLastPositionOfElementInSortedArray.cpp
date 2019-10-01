//adapted from Back to Back SWE
//https://www.youtube.com/watch?v=RlXtTF34nnE
class Solution {
public:
    vector<int> searchRange(vector<int>& n, int t) {
        vector<int> ans;
        if(n.size()==0){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        int first=0,last=0;
        first=getstart(n,t,0,n.size()-1);
        last=getend(n,t,0,n.size()-1);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
    }
    
    int getstart(vector<int>& n, int t, int left, int right){
        if(right-left<=1){
            if(n[left]==t)
                return left;
            if(n[right]==t)
                return right;
            else
                return -1;
        }
        
        int mid=(right-left)/2+left;//prevent overflow
        if(n[mid]<t)
            return getstart(n,t,mid,right);
        else
            return getstart(n,t,left,mid);
    }
    
    int getend(vector<int>& n, int t, int left, int right){
        if(right-left<=1){
            if(n[right]==t)
                return right;
            if(n[left]==t)
                return left;
            else
                return -1;
        }
        
        int mid=(right-left)/2+left;//prevent overflow
        if(n[mid]<=t)
            return getend(n,t,mid,right);
        else
            return getend(n,t,left,mid);
    }
};
