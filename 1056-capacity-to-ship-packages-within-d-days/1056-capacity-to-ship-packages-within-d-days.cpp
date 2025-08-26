class Solution {
    int time(int load, vector<int>& weights) {
    int cnt = 1; // need at least one day
    int sum = 0;
    for (int w : weights) {
        if (sum + w > load) {
            cnt++;
            sum = 0;
        }
        sum += w;
    }
    return cnt;
}
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0;
        
        int lo=INT_MIN;
         for (int w : weights) {
            sum += w;
            lo = max(lo, w); // lo must be at least the max package
        }
        int hi=sum;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(time(mid,weights)>days){
                lo=mid+1;
            }
            else {
                hi=mid;
            }
        }
        if(time(lo,weights)<=days) return lo;
        return hi;
    }
};