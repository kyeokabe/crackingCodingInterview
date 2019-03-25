class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if (digits.back()!=9)
            digits[digits.size()-1]++;
        else
        {
            int size=digits.size();

            stack<int> foo;

            while (digits.back()==9){
                foo.push(9);
                cout<<digits.size()<<endl;
                digits.pop_back();
                size--;
                if (digits.empty())
                    break;
            }
            if (size==0){
                digits.push_back(1);
                while(!foo.empty()){
                    digits.push_back(0);
                    foo.pop();
                }
            }
            else{
                digits[digits.size()-1]++;
                while(!foo.empty()){
                    digits.push_back(0);
                    foo.pop();
                }
            }
        } 
        return digits;
    }
};
