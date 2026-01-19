class Solution {
    int atmost(vector<int>& nums,int k){
        int n=nums.size();
        unordered_map<int,int> freq;
        int i=0,j=0,cnt=0,distinct=0;
        while(j<n){
            freq[nums[j]]++;
            while(freq.size()>k){
                freq[nums[i]]--;
                if(freq[nums[i]]==0) freq.erase(nums[i]);
                i++;
            }
            cnt+=(j-i)+1;
            j++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        return atmost(nums,k)-atmost(nums,k-1);
    }
};