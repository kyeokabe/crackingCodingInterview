class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> foo;
        for (int i=1;i<=n;i++){
            if ((i%3!=0) && (i%5!=0)){
                foo.push_back(to_string(i));
            }
            else
                if((i%3==0) && (i%5!=0))
                    foo.push_back("Fizz");
            else
                if((i%3!=0) && (i%5==0))
                    foo.push_back("Buzz");
            else
                if((i%3==0) && (i%5==0))
                    foo.push_back("FizzBuzz");
        }
        return foo;
    }
};
