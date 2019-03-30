class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        stack<int> foo;
        
        for (int i=0;i<32;i++){
            if(n%2==0)
                foo.push(0);
            else
                foo.push(1);
            n=n>>1;
        }
        
        uint32_t a=0;
        int count=0;
        
        for (int i=0;i<32;i++){
            a=a+foo.top()*pow(2,count);
            count++;
            foo.pop();
        }
        return a;
    }
};
