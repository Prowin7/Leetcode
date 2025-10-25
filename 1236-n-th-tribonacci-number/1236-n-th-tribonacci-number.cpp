class Solution {
public:
    int tribonacci(int n) {
        vector<int> sum(n+3);
        sum[0]=0;
        sum[1]=1;
        sum[2]=1;
        for(int i=3;i<=n;i++){
            sum[i]=sum[i-1]+sum[i-2]+sum[i-3];
        }
        return sum[n];
    }
};