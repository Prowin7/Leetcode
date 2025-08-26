class Solution {
    int day(int d,vector<int>& bloom,int k){
        int cnt=0;
        int flower=k;
        for(int i=0;i<bloom.size();i++){
            if(bloom[i]<=d){
                flower--;
            }
            else if(bloom[i]>d){
                flower=k;
            }
            if(flower==0){
                cnt++;
                flower=k;
            }
        }
        return cnt;
    }
public:
    int minDays(vector<int>& bloom, int m, int k) {
        int n=bloom.size();
        int lo=1;
        int hi=INT_MIN;
        for(auto it:bloom) hi=max(hi,it);
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            
            if(day(mid,bloom,k)<m){
                lo=mid+1;
            }
            else{
                hi=mid;
            }
        }
        if(day(lo,bloom,k)==m) return lo;
        if(day(hi,bloom,k)==m) return hi;
        return -1;
    }
};