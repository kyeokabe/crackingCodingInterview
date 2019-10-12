class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans=0;
        int weight=0;
        for(int i=0;i<arr.size();i++){
            weight+=arr[i];
            if(weight<=5000)
                ans++;
        }
        return ans;
    }
};
