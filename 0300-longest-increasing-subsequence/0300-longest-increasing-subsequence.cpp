class Solution {
public: 
int binarySearch(vector<int> &ans,int target){
    int n=ans.size();
    int left=0;
    int right=n-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(ans[mid]==target){
            return mid;
        }
        if(ans[mid]>target){
            right=mid-1;
        }
        else {
            left=mid+1;
        }
      
    }
      return left;
}
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++){
            if(ans.empty()||ans.back()<nums[i]){
                ans.push_back(nums[i]);
            }
            else{
                int ind=binarySearch(ans,nums[i]);
                ans[ind]=nums[i];
            }
        }
        return ans.size();
    }
};
