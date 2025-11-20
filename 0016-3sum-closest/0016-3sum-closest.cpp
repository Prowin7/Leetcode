class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int dist=INT_MAX;
        int ans;
        for(int i=0;i<n-2;i++){
            int j=i+1, k =n-1;
            while(j<k){
                int sum = nums[i] + nums[j] + nums[k];
                int prev = abs(target-sum);
                if(prev<dist){
                    ans = sum;
                    dist = prev;
                }
                if(sum>target){
                    k--;
                }
                else if(sum<target){
                    j++;
                }
                else{
                    return sum;
                }
            }
        }
        return ans;
    }
};