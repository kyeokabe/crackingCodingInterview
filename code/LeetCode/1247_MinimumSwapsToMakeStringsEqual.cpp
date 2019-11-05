class Solution {
public:
    int minimumSwap(string s1, string s2) { 
        //filter impossible case out
        int count_x=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]=='x')
                count_x++;
            if(s2[i]=='x')
                count_x++;
        }
        
        if(count_x%2==1)
            return -1;
        
        //count num of pairs with 
        //s1[i]==x&&s2[i]==y 
        //s1[i]==y&&s2[i]==x 
        int s1x_s2y=0;
        int s1y_s2x=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]=='x'&&s2[i]=='y')
                s1x_s2y++;
            if(s1[i]=='y'&&s2[i]=='x')
                s1y_s2x++;
        }
        
        int ans=0;
        while(s1x_s2y>=2){
            s1x_s2y-=2;
            ans++;
        }
        
        while(s1y_s2x>=2){
            s1y_s2x-=2;
            ans++;
        }
        
        if(s1x_s2y==1)
            ans+=2;
        return ans;
    }
};
