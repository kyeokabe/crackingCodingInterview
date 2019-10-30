/*
Adapted from Stefan Pochmann solution
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/discuss/84550/Slow-1-liner-to-Fast-solutions

Think of this problem as a matrix
When you add a min answer, search right
If answer added is first element of a row
search down as well
nums1   0 1 2 3
nums2 0
      1
      2
      3
*/

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;        
        if(k==0||nums1.size()==0||nums2.size()==0)
            return ans;
        int cap=nums1.size()*nums2.size();
        if(k>cap||k<0)
            k=cap;
        
        map<vector<int>,int> m;

        vector<int> v={nums1[0]+nums2[0],0,0}; //sum,i_nums1,j_nums2
        m[v]++;
        //cout<<q.top()[0]<<endl;
        
        while(k>0){
            auto it=m.begin();
            vector<int> temp=it->first;
            vector<int> temp_ans={nums1[temp[1]],nums2[temp[2]]};
            ans.push_back(temp_ans);
            vector<int> v1;
            if(nums1.size()>temp[1]+1){
                vector<int> v1={nums1[temp[1]+1]+nums2[temp[2]],temp[1]+1,temp[2]};
                m[v1]++;
            }
            if(temp[1]==0&&temp[2]+1<nums2.size()){
                vector<int> v2={nums1[temp[1]]+nums2[temp[2]+1],temp[1],temp[2]+1};
                m[v2]++;
            }

            m.erase(it->first);
            k--;
            while(m.size()>k){
                auto it2=m.rbegin();
                m.erase(it2->first);
            }
        }
        
        return ans;
    }
};
