class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
        vector<int> v={a,b,c};
        sort(v.begin(),v.end());
        int x=v[0],y=v[1],z=v[2];
        
        int minimum;
        int maximum;
        
        if(x+1==y&&y+1==z)
            minimum=0;
        else if(x+1==y||y+1==z||x+2==y||y+2==z)
            minimum=1;
        else
            minimum=2;
        maximum=(z-y-1)+(y-x-1);
        vector<int> ans={minimum,maximum};
        return ans;
    }
};

//1 3 5
