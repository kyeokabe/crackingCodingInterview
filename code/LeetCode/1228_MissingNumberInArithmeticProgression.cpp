class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int SIZE=arr.size();
        int delta=(arr[arr.size()-1]-arr[0])/SIZE;
        for(int i=1;i<arr.size();i++)
            if(arr[i]-arr[i-1]!=delta)
                return arr[i-1]+delta;
        return 0;
    }
};
