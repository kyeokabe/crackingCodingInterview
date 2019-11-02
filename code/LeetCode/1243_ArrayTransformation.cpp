class Solution {
public:
    vector<int> transformArray(vector<int>& arr) {
        bool needchange=true;
        while(needchange){
            needchange=false;
            vector<int> v(arr.size(),0);
            v[0]=arr[0];
            v[arr.size()-1]=arr[arr.size()-1];
            for(int i=1;i<arr.size()-1;i++){
                if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]){
                    needchange=true;
                    v[i]=arr[i]-1;
                }
                else if(arr[i]<arr[i-1]&&arr[i]<arr[i+1]){
                    needchange=true;
                    v[i]=arr[i]+1;
                }
                else
                    v[i]=arr[i];
            }
            arr=v;
        }
        return arr;
    }
};
