class Solution {
private:
    double r;
    double x_c;
    double y_c;
    
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x_c=x_center;
        y_c=y_center;
    }
    
    vector<double> randPoint() {
        vector<double> v;
        double radius=r*sqrt(rand0to1());
        double theta=2*3.14159265359*rand0to1();
        
        double x=x_c+radius*cos(theta);
        double y=y_c+radius*sin(theta);
        
        v.push_back(x);
        v.push_back(y);
        return v;
    }
    
    double rand0to1(){
        return double(double(rand())/RAND_MAX);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

/*
//correct but exceeds time limit
class Solution {
private:
    double r;
    double x_c;
    double y_c;
    
public:
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x_c=x_center;
        y_c=y_center;
    }
    
    vector<double> randPoint() {
        bool validCoordinate=false;
        double x;
        double y;
        while(validCoordinate==false){
            x=2*r*rand0to1();  //x: 0~2r
            x=x_c-0.5*x;     //x: x_c-r~x_c+r
            y=2*r*rand0to1();  //y: 0~2r
            x=x_c-0.5*x;     //y: y_c-r~y_c+r
            if((x-x_c)*(x-x_c)+(y-y_c)*(y-y_c)<=r*r)
                validCoordinate=true;
        }
        vector<double> v;
        v.push_back(x);
        v.push_back(y);
        return v;
    }
    
    double rand0to1(){
        return double(double(rand())/RAND_MAX);
    }
};

*/
