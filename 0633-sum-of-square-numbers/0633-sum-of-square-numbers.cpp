class Solution {
    bool binary(long long s, long long e, int target) {
        while(s<=e){
            long long mid = s+(e-s)/2;
            if(mid*mid==target) return true;
            else if(mid*mid<target) s = mid+1;
            else e = mid-1;
        }
        return false;
    }

public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        if(c==0) return true;
        while (a * a <= c) {
            long long b = c - a * a;
            if (binary(1, b, b))
                return true;
            a++;
        }
        return false;
    }
};