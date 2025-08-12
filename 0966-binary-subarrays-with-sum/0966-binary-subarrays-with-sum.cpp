class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
       int cnt=0;
       map<int,int>mp;
       mp[0]=1;
       int sum=0;
       for(int i=0;i<nums.size();i++){
        sum+=nums[i];
        cnt+=mp[sum-goal];
        mp[sum]++;
       }


        return cnt;
    }
};