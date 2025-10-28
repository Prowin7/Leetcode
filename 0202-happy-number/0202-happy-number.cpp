class Solution {
    int nextNum(int n){
        int sum=0;
        while(n>0){
            int d = n%10;
            sum+=(d*d);
            n=n/10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
       
        int slow = n;
        int fast = nextNum(n);
        while(fast!=1 && fast!=slow){
            slow = nextNum(slow);
            fast = nextNum(nextNum(fast));
        }
        return fast==1;
    }
};