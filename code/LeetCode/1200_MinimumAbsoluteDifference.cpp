class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int temp=INT_MAX;
        
        for(int i=1;i<arr.size();i++)
            if(arr[i]-arr[i-1]<temp)
                temp=arr[i]-arr[i-1];
        
        vector<vector<int>> v;
        for(int i=1;i<arr.size();i++)
            if(arr[i]-arr[i-1]==temp){
                vector<int> v2={arr[i-1],arr[i]};
                v.push_back(v2);
            }
        return v;
    }
};
