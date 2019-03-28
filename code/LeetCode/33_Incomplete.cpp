/*

question inputs not fair test case
[1,3]
0

...run time error but not my fault!
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //cout<<"check0"<<endl;
        int SIZE=nums.size();
        if (SIZE==0)
            return -1;
        if (SIZE==1)
            if (target==nums[0])
                return target;
            else
                return -1;
        
        //cout<<"check0.5"<<endl;
        //gets index of end of 1st half
        int end=binarySearch(nums);
        cout<<"bin search "<<end<<endl;
        int firstarray=regularBinary(nums,0,end-1,target);
        //cout<<"check2"<<endl;
        int secondarray=regularBinary(nums,end,nums.size()-1,target);
        cout<<firstarray<<" first"<<endl;
        cout<<secondarray<<" second"<<endl;

        if(firstarray!=-1)
            return firstarray;
        if(secondarray!=-1)
            return secondarray;
            
        return -1;
    }
    
    int regularBinary(vector<int> &nums, int L, int R, int target){

        //int L=0;
        //int R=nums.size()-1;
        
        if (nums[L]==target)
            return L;
        if (nums[R]==target)
            return R;
        
        while(L<R){
            int floor=(L+R)/2;
            if (nums[floor]==target)
                return floor;
            if(nums[floor]>target)
                R=floor;
            if(nums[floor]<target)
                L=floor+1;
        }
        return -1;
    }
    
    int binarySearch(vector<int> &nums){
        int k=nums.size()-1;    
        if (nums[k]<nums[k-1]) 
            return k-1;
        
        int count=-1;
        //cout<<"cat"<<endl;
        while(nums[k]>nums[k-1]){
            if (nums[0]>nums[k]){
                k=k-MAX(nums.size()*(pow(2,count)),1);
                count--;
            }
            else{
                k=k+MAX(nums.size()*(pow(2,count)),1);
                count--;
            }
            //cout<<"dog"<<endl;

        }
        return k;
    }
    
    int MAX(int a, int b){
        if (a>b)
            return a;
        return b;
    }
};
