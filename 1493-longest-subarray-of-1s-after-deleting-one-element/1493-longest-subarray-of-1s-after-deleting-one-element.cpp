class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int zCnt=0;
        int mLen=0;
        int start=0;
        for(int i=0;i<n;i++){
            zCnt +=(nums[i]==0);
            while(zCnt>1){
                zCnt-=(nums[start]==0);
                start++;
            }
            mLen=max(mLen,i-start);
        }
        return mLen;
    }
};