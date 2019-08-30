// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int min=1;
        int max=n;
        while(min+1<max){
            int half=0;
            //to solve dumb overflow issue
            if(min%2==1&&max%2==1)
                half=min/2+max/2+1;
            else
                half=min/2+max/2;
            if(isBadVersion(half)==true)
                max=half;
            else
                min=half;
        }
        if(isBadVersion(min)==true)
            return min;
        else
            return max;
    }
};
