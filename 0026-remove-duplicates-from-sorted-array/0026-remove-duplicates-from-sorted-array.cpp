class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        int prev=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]!=prev){
                nums[ind]=nums[i];
                ind++;
                prev=nums[i];
            }
        }
        return ind;
    }
};