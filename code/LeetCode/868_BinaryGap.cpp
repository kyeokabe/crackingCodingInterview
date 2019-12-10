class Solution {
public:
    int binaryGap(int N) {
        string temp;
        for(int i=31;i>=0;i--){
            if(N>=pow(2,i)){
                temp+="1";
                N-=pow(2,i);
            }
            else
                temp+="0";
        }
        int count=0;
        for(int i=0;i<temp.length();i++)
            if(temp[i]=='1')
                count++;
        if(count<=1)
            return 0;
        int i=0;
        while(temp[i]=='0')
            i++;
        int j=temp.length()-1;
        while(temp[j]=='0')
            j--;
        int ans=0;
        count=0;
        for(int k=i;k<j;k++){
            if(temp[k]=='0'){
                count++;
                if(count>ans)
                    ans=count;
            }
            else
                count=0;
        }
        return ans+1;
    }
};
