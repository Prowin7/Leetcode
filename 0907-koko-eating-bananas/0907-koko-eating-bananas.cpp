class Solution {
    int complete(int k,vector<int>& piles){
        int cnt=0;
        for(int i=0;i<piles.size();i++){
            cnt+=(piles[i]+k-1)/k;
        }
        return cnt;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int total=INT_MIN;
        int n=piles.size();
        for(auto it:piles) total=max(it,total);
        int lo=1;
        int hi=total;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(complete(mid,piles)>h){
                lo=mid+1;
            }
            else {
                hi=mid;
            }
            

        }
        if(complete(lo,piles)<=h) return lo;
        
        return hi;
        }
};