// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7
// looked at discussions to get the answer

class Solution {
public:
    int rand10() {
        
        int ans=0;

        while(!(1<=ans&&ans<=10))
            ans=(rand7()-1)*7+rand7();
        
        return ans;
        
    }
};
