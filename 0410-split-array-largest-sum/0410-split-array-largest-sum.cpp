class Solution {

    bool possible(int mid, vector<int>& nums, int k) {
        int cnt = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]>mid) return false;
            if (sum + nums[i] <= mid) {
                sum += nums[i];
            } else {
                cnt++;
                sum = nums[i];
            }
        }
        return cnt <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for (auto it : nums)
            sum += it;
        int l = 0;
        int r = sum;

        while (r - l > 1) {
            int mid = l + (r - l) / 2;
            if (possible(mid, nums, k)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        if (possible(l, nums, k))
            return l;
        return r;
    }
};