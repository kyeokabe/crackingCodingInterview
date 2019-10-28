class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        vector<int> v(256,0);
        int i_min=INT_MAX;
        int i_max=INT_MIN;
        int mode;
        int max_freq=0;
        int c=0;

        for(int i=0;i<count.size();i++){
            if(count[i]>max_freq){
                max_freq=count[i];
                mode=i;
            }
            
            if(i_min==INT_MAX&&count[i]!=0)
                i_min=i;
            if(count[i]!=0){
                i_max=i;
                c+=count[i];
            }
            
        }
        
        double mean=0;
        for(int i=0;i<count.size();i++)
            mean+=double(i*count[i])/c;
        
        double median=0;
        if(c%2==0){
            int a=0;
            int b=0;
            int mid_a=c/2;
            int mid_b=c/2+1;
            int i=0;
            while(mid_a>0){
                mid_a-=count[i];
                i++;
            }
            a=i-1;
            i=0;
            while(mid_b>0){
                mid_b-=count[i];
                i++;
            }
            b=i-1;
            median=double(a+b)/2;
            
        }
        else{
            int mid=c/2+1;
            int i=0;
            while(mid>0){
                mid-=count[i];
                i++;
            }
            median=double(i)-1;
        }
        
        vector<double> ans={double(i_min), double(i_max),mean,median,double(mode)};
        return ans;
    }
};
