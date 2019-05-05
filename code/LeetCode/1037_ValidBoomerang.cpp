class Solution {
public:
    bool isBoomerang(vector<vector<int>>& p) {
        //https://leetcode.com/problems/valid-boomerang/discuss/286656/C%2B%2B-1-liner%3A-Triangle-Area
        //idea adopted from votrubac
        int areatimes2=p[0][0]*(p[1][1]-p[2][1])+p[1][0]*(p[2][1]-p[0][1])+p[2][0]*(p[0][1]-p[1][1]);
        return (areatimes2)==0 ?  false:  true;
    }
};
