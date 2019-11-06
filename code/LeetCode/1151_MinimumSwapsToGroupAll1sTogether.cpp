class Solution {
public:
    int minSwaps(vector<int>& data) {
        int num1s=0;
        for(int i=0;i<data.size();i++)
            if(data[i]==1)
                num1s++;
        int num0s=0;
        for(int i=0;i<num1s;i++)
            if(data[i]==0)
                num0s++;
        int ans=num0s;
        int ptr1=num1s;
        int ptr2=0;
        while(ptr1<data.size()){
            if(data[ptr1]==0)
                num0s++;
            if(data[ptr2]==0)
                num0s--;
            ptr2++;
            ptr1++;
            if(ans>num0s)
                ans=num0s;
        }
        return ans;
    }
};
