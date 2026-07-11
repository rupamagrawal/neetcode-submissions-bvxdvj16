class Solution {
private:
    double fastPow(double x, long long n){
        if(n==0)return 1;

        if(n%2==0)return fastPow(x*x, n/2);
        return x*fastPow(x*x, n/2);
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if(N<0){
            x = 1/x;
            N=-N;
        }
        return fastPow(x, N);
    }
};
