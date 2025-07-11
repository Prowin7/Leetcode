class Solution {
public:
double pow(double x,long long n){
    if(n==0) return 1.0;
        double result=1;
        while(n>0){
            if(n%2==1){
                result=result*x;
            }
            x=x*x;
            n/=2;
        }
        return result;
}
    double myPow(double x, int n) {
        
        long long N = n;  
        
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
       return pow(x,N);
    }
};