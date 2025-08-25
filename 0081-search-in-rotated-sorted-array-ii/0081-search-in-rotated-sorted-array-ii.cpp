class Solution {
    int pivot(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        while (hi - lo > 1) {
            while (lo < hi && lo + 1 < nums.size() && nums[lo] == nums[lo + 1]) lo++;
            while (lo < hi && hi - 1 >= 0 && nums[hi] == nums[hi - 1]) hi--;
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        return (nums[hi] < nums[lo]) ? hi : lo;
    }

    int binarySearch(int lo, int hi, vector<int>& nums, int target) {
        if (lo > hi) return -1; // empty segment
        while (hi - lo > 1) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        if (lo >= 0 && lo < nums.size() && nums[lo] == target) return lo;
        if (hi >= 0 && hi < nums.size() && nums[hi] == target) return hi;
        return -1;
    }

public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return false;
        if (n == 1) return nums[0] == target;

        int pivotInd = pivot(nums);
        int ind = binarySearch(0, pivotInd - 1, nums, target);
        if (ind != -1) return true;
        ind = binarySearch(pivotInd, n - 1, nums, target);
        return ind != -1;
    }
};
