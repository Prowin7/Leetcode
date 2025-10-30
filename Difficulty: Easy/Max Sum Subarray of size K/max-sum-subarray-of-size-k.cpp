class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        int i =0;
        int j =0;
        int ans=INT_MIN;
        while(j<n){
            sum+=arr[j];
            while(j-i+1>=k){
                ans = max(ans,sum);
                sum-=arr[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};