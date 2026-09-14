class Solution {
public:
    int climbStairs(int n) {
        double p = (1+sqrt(5))/2;
        double r = pow(p,n+1)/sqrt(5);
        return round(r);
    }
};