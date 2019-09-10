class NumArray {

private:
    vector<int> v;
    vector<int> n;
    
public:
    NumArray(vector<int>& nums) {
        n=nums;
        v=nums;
        for(int i=1;i<v.size();i++)
            v[i]+=v[i-1];
    }
    
    void update(int i, int val) {
        n[i]=val;
        v=n;
        for(int i=1;i<v.size();i++)
            v[i]+=v[i-1];
        
    }
    
    int sumRange(int i, int j) {
        return (i>0)? v[j]-v[i-1]:v[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
