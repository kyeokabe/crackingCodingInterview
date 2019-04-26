class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows==0)
            return {};
        vector<int> foo;
        vector<vector<int>> ans;
        int count=1;
        foo.push_back(1);
        ans.push_back(foo);
        if (numRows==1)
            return ans;
        foo.push_back(1);
        ans.push_back(foo);
        if (numRows==2)
            return ans;
        count++;
        while(count!=numRows){
            vector<int> temp = ans[count-1];
            count++;
            vector<int> temp2;
            temp2.push_back(1);
            for (int i=0;i<temp.size()-1;i++)
                temp2.push_back(temp[i]+temp[i+1]);
            temp2.push_back(1);
            ans.push_back(temp2);
        }
        return ans;
    }
};
