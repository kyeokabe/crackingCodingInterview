class Solution {
private:
    vector<int> original;
    vector<int> current;
    
public:
    Solution(vector<int>& nums) {
        current=nums;
        original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        current=original;
        return current;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> v;
        while(v.size()!=original.size()){
            int a=rand()%current.size();
            v.push_back(current[a]);
            swap(current[a],current.back());
            current.pop_back();
        }
        current=v;
        return current;
    }
};
