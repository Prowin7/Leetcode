class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        // // vector<int> prefix(n);
        // // prefix[0]=nums[0];
        // for(int i=1;i<n;i++) prefix[i]=nums[i]+prefix[i-1];
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++){
            // int remainder=(k!=0) ? prefix[i]%k: prefix[i];
            sum+=nums[i];
            int remainder=(k!=0)?sum%k:sum;
            if(mp.find(remainder)!=mp.end()){
                if(i-mp[remainder]>=2) return true;
            }
            else 
            mp[remainder]=i;
        }
        return false;
    } 
};