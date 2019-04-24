class Solution {
public:
    int clumsy(int N) {
        if (N==1)
            return 1;
        
        int count=-1;
        int temp=1;
        int ans=0;
        queue<int> foo;
        while(N!=0){
            count++;
            if(count%4==1){
                if(N!=1)
                    temp=temp*N;
                else
                    foo.push(temp);
            }
            
            if (count%4==2){
                if(N!=1)
                    temp=temp/N;
                else
                    foo.push(temp);
            }

            if (count%4==3)//add
                foo.push(temp+N);
    
            if (count%4==0){//subtract
                temp=1;
                if (N==1)
                    foo.push(-N);
                else
                    temp=-N;
                if (count==0)
                    temp=temp*(-1);
            }
            N--;
        }
        while(foo.empty()!=true){
            ans+=foo.front();
            foo.pop();
        }
        return ans;
    }
};
