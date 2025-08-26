class Solution {
    int canPlace(int d,vector<int>& pos){
        int cnt=1;
        int last=pos[0];
        for(int i=1;i<pos.size();i++){
            if((pos[i]-last)>=d){
                cnt++;
                last=pos[i];
            }
        }
        return cnt;
    }
public:
    int maxDistance(vector<int>& position, int c) {
        int n=position.size();
        sort(position.begin(),position.end());
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(auto it:position){
            mini=min(mini,it);
            maxi=max(maxi,it);
        }
        int lo=1;
        int hi=maxi-mini;
        while(hi-lo>1){
            int mid=lo+(hi-lo)/2;
            if(canPlace(mid,position)>=c){
                lo=mid;            }
            else{
                hi=mid-1;
            }
        }
        if(canPlace(hi,position)>=c) return hi;
        return lo;
    }
};