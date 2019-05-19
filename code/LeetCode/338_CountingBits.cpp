class Solution {
public:
    vector<int> countBits(int num) {
        //no idea how to comu up with this without seeing answer
        //adapted from fengcc
        //https://leetcode.com/problems/counting-bits/discuss/79527/Four-lines-C%2B%2B-time-O(n)-space-O(n)
        vector<int> ans(num+1,0);
        for(int i=1;i<ans.size();i++)
            ans[i]=ans[i&(i-1)]+1;
        return ans;
    }
};

/*


00000000 //0=>0
00000001 //1=>1
00000010 //2=>1
00000011 //3=>2
00000100 //4=>1
00000101 //5=>2
00000110 //6=>2
00000111 //7=>3
00001000 //8=>1
00001001 //9=>2

*/
