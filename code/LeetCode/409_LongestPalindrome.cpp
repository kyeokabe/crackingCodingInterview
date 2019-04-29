class Solution {
public:
    int longestPalindrome(string s) {
        //https://leetcode.com/problems/longest-palindrome/discuss/89587/What-are-the-odds-(Python-and-C%2B%2B)
        //adapted from Stefan Pochmann
        int odd=0;
        for (char c='A';c<='z';c++)
            odd+=count(s.begin(),s.end(),c)&1;//this counts just the odd
        return s.length()-odd+(odd>0);//if no odds, don't subtract 1
    }
};
