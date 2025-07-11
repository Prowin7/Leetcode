class Solution {
public:
    double pow(double x, long long n) {
        double result = 1.0;
        while (n > 0) {
            if (n % 2 == 1)
                result *= x;
            x *= x;
            n /= 2;
        }
        return result;
    }

    double myPow(double x, int n) {
        long long N = n;  // Convert to long long to safely handle INT_MIN
        if (N < 0) {
            x = 1 / x;
            N = -N;  // safe now
        }
        return pow(x, N);
    }
};
