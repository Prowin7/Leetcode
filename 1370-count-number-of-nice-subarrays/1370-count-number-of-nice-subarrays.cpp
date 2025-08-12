class Solution {
    int atmost(vector<int>& nums,int k){
        int n=nums.size();
        vector<int> freq(2,0);
        int i=0,j=0,cnt=0;
        while(j<n){
            freq[nums[j]%2]++;
            while(freq[1]>k){
                freq[nums[i]%2]--;
                i++;
            }
            cnt+=(j-i)+1;
            j++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};