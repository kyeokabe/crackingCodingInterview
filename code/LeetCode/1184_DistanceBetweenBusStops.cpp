class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int sum=0;
        for(int i=0;i<distance.size();i++)
            sum+=distance[i];
        int minisum=0;
        
        if(destination<start)
            destination+=distance.size();
        
        for(int i=start;i<destination;i++)
            minisum+=distance[i%distance.size()];
        return min(minisum,sum-minisum);
    }
};
