class Solution {
public:
    int mod = 1e9+7;
    int smallestRepunitDivByK(int k) {

        // Important: if k has factor 2 or 5 → impossible
        if (k % 2 == 0 || k % 5 == 0) return -1;

        int len = 1;
        long long n = 1 % k;   // work only with modulo

        while (true) {
            if (n % k == 0) return len;

            // build next repunit but keep only modulo
            n = (n * 10 + 1) % k;

            len++;

            // safety: if length exceeds k, cycle exists → impossible
            if (len > k) return -1;
        }

        return -1;
    }
};
