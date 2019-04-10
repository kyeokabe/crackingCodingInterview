class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int ROW=nums.size();
        int COL=nums[0].size();
        
        if (ROW*COL!=r*c)
            return nums;
        
        vector<int> temp;
        for (int i=0;i<ROW;i++)
            for (int j=0;j<COL;j++)
                temp.push_back(nums[i][j]);
        
        vector<vector<int>> foo;
        int k=0;
        for (int i=0;i<r;i++){
            vector<int> poo;
            for (int j=0;j<c;j++){
                poo.push_back(temp[k]);
                k++;
            }
            foo.push_back(poo);
        }
        return foo;
    }
};
