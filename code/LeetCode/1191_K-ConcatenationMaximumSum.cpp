class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int ans=0;
        if (k==0)
            return 0;
        
        int sumArray=0;
        for(int i=0;i<arr.size();i++){
            sumArray+=arr[i];
        }
        if(sumArray<=0&&k>=3)
            k=2;
        
        if(k==2){
            int arrsize=arr.size();
            for(int i=0;i<arrsize;i++)
                arr.push_back(arr[i]);
            k=1;
        }
        if (k==1){
            int sum=0;
            for(int i=0;i<arr.size();i++){
                sum+=arr[i];
                if(sum<0)
                    sum=0;
                ans=max(sum,ans);
                int foo=pow(10,9)+7;
                ans=ans%foo;
            }
            return ans;
        }
        
        int minisum=0;
        for(int i=1;i<=k-2;i++){
            minisum+=sumArray;
            int foo=pow(10,9)+7;
            minisum=minisum%foo;
        }
        
        int left=0;
        int leftsum=0;
        int right=0;
        int rightsum=0;
        for(int i=arr.size()-1;i>=0;i--){
            left+=arr[i];
            leftsum=max(leftsum,left);
        }
        
        for(int i=0;i<arr.size();i++){
            right+=arr[i];
            rightsum=max(rightsum,right);
        }
        
        int foo=pow(10,9)+7;
        ans=(leftsum+rightsum+minisum)%foo;
        return ans;
    }
};
