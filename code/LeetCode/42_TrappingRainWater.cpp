class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()==0)
            return 0;
        vector<int> maxleft(height.size(),0);
        vector<int> maxright(height.size(),0);
        
        for(int i=1;i<height.size();i++)
            maxleft[i]=max(maxleft[i-1],height[i-1]);
        
        for(int i=height.size()-2;i>=0;i--)
            maxright[i]=max(maxright[i+1],height[i+1]);
        
        int ans=0;
        for(int i=1;i<height.size()-1;i++)
            if(height[i]<min(maxright[i],maxleft[i]))
                ans+=(min(maxright[i],maxleft[i])-height[i]);
        return ans;
    }
};
