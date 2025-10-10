class Solution {
    bool binary(long long s, long long e, int target){
        while(e-s>1){
            long long mid = s+(e-s)/2;
            if(mid*mid<=target) s=mid;
            else e=mid;
        }
        if(s*s==target) return true;
        if(e*e==target) return false;
        return false;
    }
public:
    bool judgeSquareSum(int c) {
        long long a = 0;
        if(c==2) return true;
        while(a*a<=c){
            long long b = c - a*a;
            if(binary(0,b,b)) return true;
            a++;
        }
        return false;
    }
};