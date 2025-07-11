class Solution {
public:
    const int MOD = 1e9 + 7;

    // Fast modular exponentiation using a while loop
    long long power(long long base, long long exponent) {
        long long result = 1;
        base %= MOD;

        while (exponent > 0) {
            if (exponent % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exponent /= 2;
        }

        return result;
    }

    int countGoodNumbers(long long n) {
        long long even = (n + 1) / 2; // Positions 0, 2, 4, ...
        long long odd = n / 2;        // Positions 1, 3, 5, ...

        long long result = (power(5, even) * power(4, odd)) % MOD;
        return (int)result;
    }
};
