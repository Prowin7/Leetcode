class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int len = 0;
        int n = nums.size();
        int i = 0;
        int j = 0;
        while(j<n){
            
            while((long)nums[j]>(long)k*nums[i]){
                i++;
            }
            len = max(len,j-i+1);
            j++;

        }
        
    return n - len;
    }
    
};