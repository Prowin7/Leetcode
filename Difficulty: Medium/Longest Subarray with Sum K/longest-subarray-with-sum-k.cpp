class Solution {
    
  public:
    int longestSubarray(vector<int>& nums, int k) {
        // code here
       int n=nums.size();
       int sum=0;
       int maxLen=0;
       unordered_map<int,int> mp;
       for(int i=0;i<n;i++){
           sum+=nums[i];
           if(sum==k){
               maxLen=i+1;
           }
           if(mp.find(sum-k)!=mp.end()){
               maxLen=max(maxLen,i-mp[sum-k]);
           }
           if(mp.find(sum)==mp.end()){
               mp[sum]=i;
           }
       }
       return maxLen;
    }
};