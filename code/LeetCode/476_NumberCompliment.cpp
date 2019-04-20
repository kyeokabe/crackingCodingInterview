class Solution {
public:
    int findComplement(int num) {
        int ans=0;
        int count=0;
        while (num!=0){
            if(num%2==0)
                ans+=pow(2,count);
            num=num/2;
            count++;
        }
        return ans;
    }
};
