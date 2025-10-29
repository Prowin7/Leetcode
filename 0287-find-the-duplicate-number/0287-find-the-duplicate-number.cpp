class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 1;
        int e = n-1;
        while(e>s){
            int mid = s+(e-s)/2;
            int cnt=0;
            for(int i=0;i<n;i++){
                if(nums[i]<=mid){
                    cnt++;
                }
            }
            if(cnt>mid){
                e = mid;
            }
            else{
                s = mid+1;
            }
        }
        return s;
    }
};