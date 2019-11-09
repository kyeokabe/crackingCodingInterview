class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        unordered_map<int,int> m;
        
        int n=sideLength;
        
        for(int r=0;r<height;r++)
            for(int c=0;c<width;c++)
                m[c%n+(r%n)*n]++;
        
        priority_queue<int> pq;
        
        auto it=m.begin();
        while(it!=m.end()){
            pq.push(it->second);
            //cout<<"it->first = "<<it->first<<", it->second = "<<it->second<<endl;
            it++;
        }
        
        int ans=0;
        
        while(maxOnes>0){
            ans+=pq.top();
            pq.pop();
            maxOnes--;
        }
        
        return ans;
    }
};
