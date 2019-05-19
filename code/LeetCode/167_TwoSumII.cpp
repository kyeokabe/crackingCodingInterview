class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int HI=numbers.size()-1;
        int LOW=0;
        while(numbers[HI]+numbers[LOW]!=target){
            if(numbers[HI]+numbers[LOW]>target){
                --HI;
            }
            else
                ++LOW;
        }
        return {LOW+1,HI+1};
    }
};
