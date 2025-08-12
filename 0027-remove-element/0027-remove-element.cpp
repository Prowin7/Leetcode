class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int i=0;
        int j=0;
        int cnt=0;
        while(j<n){
            if(nums[j]!=val){
                swap(nums[i],nums[j]);
                i++;
            }
            cnt++;
            j++;
        }
        return i;
    }
};