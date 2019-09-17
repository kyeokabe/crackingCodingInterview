class Solution {
public:
    int heightChecker(vector<int>& h) {
        vector<int> h2=h;
        sort(h2.begin(),h2.end());
        
        int ptr1=0;
        int ptr2=0;
        int ans=0;
        
        while(ptr1!=h.size()){
            if(h[ptr1]!=h2[ptr2])
                ans++;
            ptr1++;
            ptr2++;
        }

        return ans;
    }
};

//12121
