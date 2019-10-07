class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> ans;
        int ptr1=0;
        int ptr2=0;
        int ptr3=0;
        
        while(ptr1<arr1.size()){
            
            while(ptr2<arr2.size()&&arr2[ptr2]<arr1[ptr1]){
                ptr2++;
                if(ptr2>=arr2.size())
                    return ans;
            }

            while(ptr3<arr3.size()&&arr3[ptr3]<arr1[ptr1]){
                ptr3++;
                if(ptr3>=arr3.size())
                    return ans;
            }
            
            if(arr1[ptr1]==arr2[ptr2]&&arr2[ptr2]==arr3[ptr3]){
                ans.push_back(arr1[ptr1]);
                ptr2++;
                ptr3++;
                if(ptr2>=arr2.size()||ptr3>=arr3.size())
                    break;
            }
            
            ptr1++;
        }
        return ans;
    }
};
