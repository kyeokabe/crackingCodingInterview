class Solution {
public:
    int bulbSwitch(int n) {
        int count=0;
        int m=1;
        while(m*m<=n){
            count++;
            m++;
        }
        return count;
    }
};

/*

0 0 0 0 0 0 0 0 0#R0
1 1 1 1 1 1 1 1 1#R1
1 0 1 0 1 0 1 0 1#R2
1 0 0 0 1 1 1 0 0#R3
1 0 0 1 1 1 1 1 0#R4
1 0 0 1 0 1 1 1 0#R5
1 0 0 1 0 0 1 1 0#R6 
1 0 0 1 0 0 0 1 0#R7 
1 0 0 1 0 0 0 0 0#R8 
1 0 0 1 0 0 0 0 1#R9 


1#R1
1 0#R2
1 0 0#R3
1 0 0 1#R4
1 0 0 1 0#R5
1 0 0 1 0 0#R6
1 0 0 1 0 0 0#R7
1 0 0 1 0 0 0 0#R8
1 0 0 1 0 0 0 0 1#R9

12... 1,2,3,4,6,12 ... **even** number flips, so "off"
9 ... 1,3, 9 ... **odd** number flips, so "on"

*/
