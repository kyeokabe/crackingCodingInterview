/**
 * // This is Sea's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Sea {
 *   public:
 *     bool hasShips(vector<int> topRight, vector<int> bottomLeft);
 * };
 */

class Solution {
public:
    int countShips(Sea sea, vector<int> topRight, vector<int> bottomLeft) {

        vector<int> v={topRight[0],topRight[1],bottomLeft[0],bottomLeft[1]};
        queue<vector<int>> q;
        q.push(v);
        
        int ans=0;
        
        while(!q.empty()){
            vector<int> TR={q.front()[0],q.front()[1]};
            vector<int> BL={q.front()[2],q.front()[3]};
            q.pop();
            int hasShip=sea.hasShips(TR,BL);
            if(hasShip){
                if(TR[0]==BL[0]&&TR[1]==BL[1]){
                    ans++;
                }
                else if(TR[0]>BL[0]){
                    vector<int> temp1={(BL[0]+TR[0])/2,TR[1],BL[0],BL[1]};
                    vector<int> temp2={TR[0],TR[1],(BL[0]+TR[0])/2+1,BL[1]};
                    q.push(temp1);
                    q.push(temp2);
                }
                else{
                    vector<int> temp1={TR[0],TR[1],BL[0],(BL[1]+TR[1])/2+1};
                    vector<int> temp2={TR[0],(BL[1]+TR[1])/2,BL[0],BL[1]};
                    q.push(temp1);
                    q.push(temp2);
                }
            }
        }
        return ans;
    }
};
