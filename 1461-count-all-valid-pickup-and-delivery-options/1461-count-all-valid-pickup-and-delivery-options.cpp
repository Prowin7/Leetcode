class Solution {
public:
    int countOrders(int n) {
        long long cnt=1;
        int MOD = 1e9+7;
        for(int i =2;i<=n;i++){
            cnt = (cnt * (2*i-1)*i )%MOD;
        }
        return (int)cnt;
    }
};