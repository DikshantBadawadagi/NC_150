class Solution {
    private:
    double f(double x,int n){
        if(n == 1)return x;
        return x * f(x,n-1);
    }
public:
    double myPow(double x, int n) {
        if(n == 0)return double(1);
        double ans = f(x,abs(n));
        if(n < 0){
            return double(1/ans);
        }
        return ans;
    }
};
