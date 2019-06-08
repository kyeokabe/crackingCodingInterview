class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points.begin(),points.end(),[](vector<int> &p,vector<int> &q){return p[0]*p[0]+p[1]*p[1]<q[0]*q[0]+q[1]*q[1];});
        return vector<vector<int>>(points.begin(),points.begin()+K);
    }
};
