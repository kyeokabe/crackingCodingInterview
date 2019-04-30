class Solution {
public:
    vector<int> constructRectangle(int area) {
        //https://leetcode.com/problems/construct-the-rectangle/discuss/97244/3-line-C%2B%2B-clean-solution-with-Explanation
        //best solution adapted from beckswu 
        for(int i=sqrt(area);i>0;i--){
            if(area%i==0)
                return {area/i,i};
        }
        return{area,1};
    }
};
